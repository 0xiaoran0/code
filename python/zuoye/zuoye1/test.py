import dpkt
import socket
import pandas as pd
import json
from collections import defaultdict, Counter

# ==================== 任务1：TCP套接字频次统计 ====================
def stats_tcp_socket(pcap_path, output_csv="stats_socket.csv"):
    """
    统计TCP会话(源IP:Port -> 目的IP:Port)的出现次数
    按降序排序，保存为stats_socket.csv
    """
    tcp_session_list = []
    with open(pcap_path, 'rb') as f:
        pcap = dpkt.pcap.Reader(f)
        for _, buf in pcap:
            # 仅处理以太网格式报文
            if pcap.datalink() != dpkt.pcap.DLT_EN10MB:
                continue
            eth = dpkt.ethernet.Ethernet(buf)
            if not isinstance(eth.data, dpkt.ip.IP):
                continue
            ip = eth.data
            # 仅解析TCP报文
            if ip.p == dpkt.ip.IP_PROTO_TCP:
                src_ip = socket.inet_ntoa(ip.src)
                dst_ip = socket.inet_ntoa(ip.dst)
                tcp = ip.data
                # 生成唯一TCP会话标识
                session_key = f"{src_ip}:{tcp.sport} -> {dst_ip}:{tcp.dport}"
                tcp_session_list.append(session_key)

    # 统计频次并降序排序
    session_count = Counter(tcp_session_list)
    df = pd.DataFrame(list(session_count.items()), columns=["TCP_Session", "Packet_Count"])
    df = df.sort_values(by="Packet_Count", ascending=False).reset_index(drop=True)
    # 保存CSV文件
    df.to_csv(output_csv, index=False, encoding="utf-8")
    print(f"✅ 任务1完成：TCP套接字统计已保存至 {output_csv}")
    return df

# ==================== 任务2：协议占比统计（输出JSON） ====================
def calc_protocol_percent(pcap_path):
    """
    统计ICMP/UDP/TCP + TCP各标志位数量，计算占比
    输出标准JSON格式
    """
    # 初始化统计字段
    stats = {
        "ICMP": 0,
        "UDP": 0,
        "TCP": 0,
        "TCP_SYN": 0,
        "TCP_ACK": 0,
        "TCP_PSH": 0,
        "TCP_FIN": 0,
        "TCP_RST": 0
    }
    total_packets = 0  # 总报文数

    with open(pcap_path, 'rb') as f:
        pcap = dpkt.pcap.Reader(f)
        for _, buf in pcap:
            if pcap.datalink() != dpkt.pcap.DLT_EN10MB:
                continue
            eth = dpkt.ethernet.Ethernet(buf)
            if not isinstance(eth.data, dpkt.ip.IP):
                continue
            ip = eth.data
            total_packets += 1

            # 基础协议分类
            if ip.p == 1:
                stats["ICMP"] += 1
            elif ip.p == 17:
                stats["UDP"] += 1
            elif ip.p == 6:
                stats["TCP"] += 1
                # 修复原代码BUG：用多个if判断所有TCP标志位（支持组合标志）
                tcp = ip.data
                if tcp.flags & dpkt.tcp.TH_SYN:
                    stats["TCP_SYN"] += 1
                if tcp.flags & dpkt.tcp.TH_ACK:
                    stats["TCP_ACK"] += 1
                if tcp.flags & dpkt.tcp.TH_PUSH:
                    stats["TCP_PSH"] += 1
                if tcp.flags & dpkt.tcp.TH_FIN:
                    stats["TCP_FIN"] += 1
                if tcp.flags & dpkt.tcp.TH_RST:
                    stats["TCP_RST"] += 1

    # 计算百分比（保留2位小数）
    result_json = {}
    for key, count in stats.items():
        percent = round((count / total_packets) * 100, 2) if total_packets > 0 else 0.0
        result_json[key] = {"数量": count, "占比(%)": percent}

    # 格式化输出JSON
    json_str = json.dumps(result_json, ensure_ascii=False, indent=2)
    print("\n✅ 任务2完成：协议占比统计结果（JSON）")
    print(json_str)
    return json_str

# ==================== 任务3：攻击流量密度统计（1秒粒度，实时输出） ====================
def calc_traffic_density(pcap_path, interval=1):
    """
    以1秒为粒度统计attack.pcap的报文总数
    实时输出到终端
    """
    print("\n✅ 任务3：攻击流量密度统计（1秒粒度，实时输出）")
    print("-" * 60)
    second_traffic = defaultdict(int)  # key: 时间秒数，value: 报文数量
    last_sec = -1

    with open(pcap_path, 'rb') as f:
        pcap = dpkt.pcap.Reader(f)
        for ts, buf in pcap:
            current_sec = int(ts)  # 取时间戳整数秒
            second_traffic[current_sec] += 1

            # 实时打印：秒数变化时输出上一秒的统计结果
            if current_sec != last_sec and last_sec != -1:
                print(f"第 {last_sec:>4d} 秒 | 报文总数：{second_traffic[last_sec]:>5d} 条")
            last_sec = current_sec

        # 打印最后一秒的结果
        if last_sec != -1:
            print(f"第 {last_sec:>4d} 秒 | 报文总数：{second_traffic[last_sec]:>5d} 条")
    print("-" * 60)
    print("任务3执行完成！")
    return second_traffic

# ==================== 主函数：执行所有任务 ====================
if __name__ == "__main__":
    # 【修改为你的pcap文件实际路径】
    HTTP_PCAP_PATH = "zuoye/http.pcap"
    ATTACK_PCAP_PATH = "zuoye/attack.pcap"

    # 执行任务1：http.pcap TCP套接字统计
    stats_tcp_socket(HTTP_PCAP_PATH)

    # 执行任务2：http.pcap 协议占比统计
    calc_protocol_percent(HTTP_PCAP_PATH)

    # 执行任务3：attack.pcap 流量密度统计
    calc_traffic_density(ATTACK_PCAP_PATH)
