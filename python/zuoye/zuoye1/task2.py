import dpkt
import socket
import pandas as pd
import json
from collections import Counter
import os

# ====================== 通用工具函数 ======================
def parse_pcap_to_df(pcap_path):
    """
    通用PCAP解析函数：将pcap文件解析为DataFrame，包含所有需要的字段
    :param pcap_path: pcap文件路径
    :return: 包含报文元数据的DataFrame，解析失败返回None
    """
    if not os.path.exists(pcap_path):
        print(f"错误：文件 {pcap_path} 不存在！")
        return None
    
    results = []
    protocol_names = {6: 'TCP', 17: 'UDP', 1: 'ICMP'}
    
    try:
        with open(pcap_path, 'rb') as f:
            pcap = dpkt.pcap.Reader(f)
            for ts, buf in pcap:
                # 初始化当前报文的基础信息
                pkt_info = {
                    "timestamp": ts,
                    "src_ip": None,
                    "dst_ip": None,
                    "protocol": None,
                    "src_port": None,
                    "dst_port": None,
                    "tcp_flags": None  # 存储TCP标志位字典
                }

                # 解析以太网帧（主流链路层类型）
                if pcap.datalink() == dpkt.pcap.DLT_EN10MB:
                    eth = dpkt.ethernet.Ethernet(buf)
                    # 解析IP层
                    if isinstance(eth.data, dpkt.ip.IP):
                        ip = eth.data
                        pkt_info["src_ip"] = socket.inet_ntoa(ip.src)
                        pkt_info["dst_ip"] = socket.inet_ntoa(ip.dst)
                        pkt_info["protocol"] = protocol_names.get(ip.p, ip.p)

                        # 解析TCP
                        if ip.p == dpkt.ip.IP_PROTO_TCP:
                            tcp = ip.data
                            pkt_info["src_port"] = tcp.sport
                            pkt_info["dst_port"] = tcp.dport
                            # 修复原代码elif问题：用if判断所有标志位（支持多标志共存）
                            flag_stats = {'SYN': 0, 'ACK': 0, 'PSH': 0, 'FIN': 0, 'RST': 0}
                            flags = tcp.flags
                            if flags & dpkt.tcp.TH_SYN:
                                flag_stats['SYN'] = 1
                            if flags & dpkt.tcp.TH_ACK:
                                flag_stats['ACK'] = 1
                            if flags & dpkt.tcp.TH_PUSH:
                                flag_stats['PSH'] = 1
                            if flags & dpkt.tcp.TH_FIN:
                                flag_stats['FIN'] = 1
                            if flags & dpkt.tcp.TH_RST:
                                flag_stats['RST'] = 1
                            pkt_info["tcp_flags"] = flag_stats

                        # 解析UDP
                        elif ip.p == dpkt.ip.IP_PROTO_UDP:
                            udp = ip.data
                            pkt_info["src_port"] = udp.sport
                            pkt_info["dst_port"] = udp.dport

                        # 解析ICMP（无端口）
                        elif ip.p == dpkt.ip.IP_PROTO_ICMP:
                            pass  # ICMP无端口字段，保持None即可

                # 过滤有效报文（至少有IP和协议）
                if pkt_info["src_ip"] and pkt_info["protocol"]:
                    results.append(pkt_info)
        
        # 转换为DataFrame，方便后续统计
        df = pd.DataFrame(results)
        return df

    except Exception as e:
        print(f"解析 {pcap_path} 失败：{str(e)}")
        return None

# ====================== 功能1：TCP套接字频次统计 ======================
def stats_tcp_socket(http_pcap_path, output_csv="stats_socket.csv"):
    """
    统计http.pcap中TCP会话（IP:Port对）的出现频次，降序保存为CSV
    """
    df = parse_pcap_to_df(http_pcap_path)
    if df is None or df.empty:
        print("无有效TCP报文数据，跳过套接字统计！")
        return
    
    # 筛选TCP报文
    tcp_df = df[df["protocol"] == "TCP"].copy()
    if tcp_df.empty:
        print("http.pcap中无TCP报文！")
        return
    
    # 构造套接字对（格式：src_ip:src_port <-> dst_ip:dst_port）
    tcp_df["socket_pair"] = tcp_df.apply(
        lambda row: f"{row['src_ip']}:{row['src_port']} <-> {row['dst_ip']}:{row['dst_port']}",
        axis=1
    )
    
    # 统计频次并降序
    socket_count = tcp_df["socket_pair"].value_counts().reset_index()
    socket_count.columns = ["tcp_socket_pair", "count"]
    socket_count = socket_count.sort_values(by="count", ascending=False)
    
    # 保存为CSV
    socket_count.to_csv(output_csv, index=False, encoding="utf-8")
    print(f"✅ 套接字频次统计完成，结果已保存至 {output_csv}")

# ====================== 功能2：协议占比计算（输出JSON） ======================
def stats_protocol_ratio(pcap_path, output_json="protocol_ratio.json"):
    """
    统计PCAP中ICMP/UDP/TCP（及TCP标志位）的报文数量和占比，输出JSON
    """
    df = parse_pcap_to_df(pcap_path)
    if df is None or df.empty:
        print("无有效报文数据，跳过协议占比统计！")
        return
    
    total_pkts = len(df)
    stats = {
        "total_packets": total_pkts,
        "protocol_count": {},
        "protocol_percent": {}
    }

    # 1. 基础协议统计（ICMP/UDP/TCP）
    proto_count = df["protocol"].value_counts().to_dict()
    stats["protocol_count"]["ICMP"] = proto_count.get("ICMP", 0)
    stats["protocol_count"]["UDP"] = proto_count.get("UDP", 0)
    stats["protocol_count"]["TCP"] = proto_count.get("TCP", 0)

    # 2. TCP标志位细分统计（核心修复：统一键名+补全TCP_PSH）
    tcp_df = df[df["protocol"] == "TCP"]
    tcp_flag_stats = {
        "TCP_SYN": 0,
        "TCP_ACK": 0,
        "TCP_SYN_ACK": 0,
        "TCP_FIN": 0,
        "TCP_RST": 0,
        "TCP_PSH": 0  # 补全遗漏的键，键名统一带TCP_前缀
    }
    if not tcp_df.empty:
        for _, row in tcp_df.iterrows():
            flags = row["tcp_flags"]
            if flags["SYN"] and flags["ACK"]:
                tcp_flag_stats["TCP_SYN_ACK"] += 1
            else:
                # 所有赋值键名与初始化完全匹配（均为TCP_XXX）
                if flags["SYN"]:
                    tcp_flag_stats["TCP_SYN"] += 1
                if flags["ACK"]:
                    tcp_flag_stats["TCP_ACK"] += 1
                if flags["FIN"]:
                    tcp_flag_stats["TCP_FIN"] += 1
                if flags["RST"]:
                    tcp_flag_stats["TCP_RST"] += 1
                if flags["PSH"]:
                    tcp_flag_stats["TCP_PSH"] += 1  # 统一为TCP_PSH，无拼写错误
    stats["protocol_count"].update(tcp_flag_stats)

    # 3. 计算百分比（保留2位小数）
    for key, count in stats["protocol_count"].items():
        if total_pkts > 0:
            stats["protocol_percent"][key] = round((count / total_pkts) * 100, 2)
        else:
            stats["protocol_percent"][key] = 0.0

    # 保存为JSON（格式化输出，方便阅读）
    with open(output_json, "w", encoding="utf-8") as f:
        json.dump(stats, f, ensure_ascii=False, indent=4)
    
    print(f"✅ 协议占比统计完成，结果已保存至 {output_json}")
    # 终端打印JSON结果
    print("📊 协议占比统计结果：")
    print(json.dumps(stats, ensure_ascii=False, indent=4))

# ====================== 功能3：attack.pcap流量密度（1秒粒度） ======================
def stats_traffic_density(attack_pcap_path):
    """
    针对attack.pcap，以1秒为粒度统计报文总数，实时输出到终端
    """
    df = parse_pcap_to_df(attack_pcap_path)
    if df is None or df.empty:
        print("attack.pcap无有效报文数据！")
        return
    
    # 转换时间戳为秒级整数（1秒粒度）
    df["timestamp_sec"] = df["timestamp"].astype(int)
    
    # 统计每个秒级的报文数
    density_stats = df["timestamp_sec"].value_counts().sort_index()
    
    print("\n🚀 attack.pcap 流量密度统计（1秒粒度）：")
    print("=====================================")
    print(f"{'时间戳（秒）':<15} {'报文数量':<10}")
    print("=====================================")
    # 实时逐行输出（模拟实时效果）
    for sec, count in density_stats.items():
        print(f"{sec:<15} {count:<10}")
    
    # 汇总信息
    total_pkts = len(df)
    total_seconds = len(density_stats)
    avg_density = round(total_pkts / total_seconds, 2) if total_seconds > 0 else 0
    print("=====================================")
    print(f"总报文数：{total_pkts}")
    print(f"总时长：{total_seconds} 秒")
    print(f"平均流量密度：{avg_density} 报文/秒")

# ====================== 主函数（执行所有功能） ======================
if __name__ == "__main__":
    # 配置文件路径（请替换为你的实际文件路径）
    HTTP_PCAP_PATH = "./zuoye/http.pcap"
    ATTACK_PCAP_PATH = "./zuoye/attack.pcap"

    # 执行功能1：TCP套接字频次统计
    stats_tcp_socket(HTTP_PCAP_PATH)
    
    # 执行功能2：分别统计两个PCAP的协议占比
    print("\n--- 统计http.pcap协议占比 ---")
    stats_protocol_ratio(HTTP_PCAP_PATH, "http_protocol_ratio.json")
    print("\n--- 统计attack.pcap协议占比 ---")
    stats_protocol_ratio(ATTACK_PCAP_PATH, "attack_protocol_ratio.json")
    
    # 执行功能3：attack.pcap流量密度统计
    print("\n--- attack.pcap 流量密度统计 ---")
    stats_traffic_density(ATTACK_PCAP_PATH)
