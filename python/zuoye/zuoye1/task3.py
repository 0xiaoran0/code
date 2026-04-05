import dpkt
import socket
import pandas as pd
from collections import defaultdict, Counter
import os

# ====================== 通用PCAP解析函数（复用稳定版） ======================
def parse_pcap_to_df(pcap_path):
    """解析pcap文件为DataFrame，返回标准化流量数据"""
    if not os.path.exists(pcap_path):
        print(f"❌ 错误：文件 {pcap_path} 不存在！")
        return None

    results = []
    protocol_names = {6: 'TCP', 17: 'UDP', 1: 'ICMP'}

    try:
        with open(pcap_path, 'rb') as f:
            pcap = dpkt.pcap.Reader(f)
            for ts, buf in pcap:
                pkt_info = {
                    "timestamp": ts,
                    "src_ip": None,
                    "dst_ip": None,
                    "protocol": None,
                    "src_port": None,
                    "dst_port": None,
                    "is_anomaly": False  # 异常流量标注
                }

                # 以太网帧解析
                if pcap.datalink() == dpkt.pcap.DLT_EN10MB:
                    eth = dpkt.ethernet.Ethernet(buf)
                    if isinstance(eth.data, dpkt.ip.IP):
                        ip = eth.data
                        pkt_info["src_ip"] = socket.inet_ntoa(ip.src)
                        pkt_info["dst_ip"] = socket.inet_ntoa(ip.dst)
                        pkt_info["protocol"] = protocol_names.get(ip.p, ip.p)

                        # TCP/UDP端口解析
                        if ip.p == dpkt.ip.IP_PROTO_TCP:
                            tcp = ip.data
                            pkt_info["src_port"] = tcp.sport
                            pkt_info["dst_port"] = tcp.dport
                        elif ip.p == dpkt.ip.IP_PROTO_UDP:
                            udp = ip.data
                            pkt_info["src_port"] = udp.sport
                            pkt_info["dst_port"] = udp.dport

                if pkt_info["src_ip"] and pkt_info["dst_ip"]:
                    results.append(pkt_info)

        return pd.DataFrame(results)

    except Exception as e:
        print(f"❌ 解析失败：{str(e)}")
        return None

# ====================== 任务a：异常高频访问检测 ======================
def detect_high_freq_attack(df, freq_threshold=50):
    """
    规则：1秒内，单个源IP发送报文数 > 阈值 → 判定为【高频攻击/DoS】
    :param df: 流量DataFrame
    :param freq_threshold: 高频阈值（默认50条/秒）
    :return: 攻击IP列表、异常数据、异常特征
    """
    print("=" * 80)
    print("🔍 任务a：异常高频访问流量检测")
    print("=" * 80)

    # 1. 按【源IP+时间秒数】统计报文数量
    df["time_sec"] = df["timestamp"].astype(int)
    ip_sec_count = df.groupby(["src_ip", "time_sec"]).size().reset_index(name="pkt_count")

    # 2. 筛选超过阈值的高频流量
    high_freq_records = ip_sec_count[ip_sec_count["pkt_count"] > freq_threshold]
    attack_ips = high_freq_records["src_ip"].unique()
    anomaly_df = df.copy()

    # 3. 标注异常条目
    if len(attack_ips) > 0:
        anomaly_df.loc[anomaly_df["src_ip"].isin(attack_ips), "is_anomaly"] = True

    # 4. 输出结果
    if len(attack_ips) == 0:
        print("✅ 未检测到异常高频访问流量")
        return [], anomaly_df, {}
    else:
        print(f"⚠️ 检测到【高频攻击】源IP：{list(attack_ips)}")
        # 统计攻击目标
        target_ips = anomaly_df[anomaly_df["is_anomaly"]]["dst_ip"].value_counts().to_dict()
        print(f"🎯 攻击目标IP及报文数：{target_ips}")
        print(f"📊 阈值设定：{freq_threshold} 条/秒（超过判定为异常）")

        # 异常特征
        feature = {
            "attack_type": "高频DoS攻击",
            "attack_ips": list(attack_ips),
            "target_ips": target_ips,
            "threshold": freq_threshold
        }
        return attack_ips, anomaly_df, feature

# ====================== 任务b：端口扫描行为检测 ======================
def detect_port_scan(df, scan_threshold=10):
    """
    规则：1秒内，单个源IP 对 同一目标IP 访问 > 阈值个不同目的端口 → 判定为【端口扫描】
    :param df: 流量DataFrame
    :param scan_threshold: 端口数阈值（默认10个/秒）
    :return: 扫描者IP、扫描特征
    """
    print("\n" + "=" * 80)
    print("🔍 任务b：端口扫描行为检测")
    print("=" * 80)

    # 1. 按【源IP+目标IP+时间秒】统计不同目的端口数量
    df["time_sec"] = df["timestamp"].astype(int)
    port_scan_stats = df.groupby(["src_ip", "dst_ip", "time_sec"])["dst_port"].nunique().reset_index()
    port_scan_stats.columns = ["src_ip", "dst_ip", "time_sec", "unique_dst_ports"]

    # 2. 筛选扫描行为
    scan_records = port_scan_stats[port_scan_stats["unique_dst_ports"] > scan_threshold]
    scanner_ips = scan_records["src_ip"].unique()

    if len(scanner_ips) == 0:
        print("✅ 未检测到端口扫描行为")
        return [], {}
    else:
        print(f"⚠️ 检测到【端口扫描】源IP：{list(scanner_ips)}")
        scan_features = {}
        for _, row in scan_records.iterrows():
            src = row["src_ip"]
            dst = row["dst_ip"]
            port_num = row["unique_dst_ports"]
            # 获取扫描的端口范围
            scanned_ports = df[(df["src_ip"] == src) & (df["dst_ip"] == dst)]["dst_port"].unique()
            scan_features[src] = {
                "target_ip": dst,
                "scanned_port_count": port_num,
                "port_range": f"{min(scanned_ports)} ~ {max(scanned_ports)}",
                "all_ports": sorted(scanned_ports)[:10]  # 展示前10个
            }
            print(f"├─ 扫描者：{src} → 目标：{dst}")
            print(f"├─ 扫描端口数：{port_num} 个")
            print(f"└─ 端口范围：{scan_features[src]['port_range']}")

        print(f"📊 阈值设定：{scan_threshold} 个不同端口/秒（超过判定为扫描）")
        return scanner_ips, scan_features

# ====================== 任务c：生成iptables防火墙封禁指令 ======================
def generate_firewall_rules(attack_ips, scanner_ips):
    """
    合并攻击IP，生成Linux iptables封禁指令
    """
    print("\n" + "=" * 80)
    print("🛡️  任务c：自动生成iptables防御指令")
    print("=" * 80)

    # 去重所有恶意IP
    malicious_ips = list(set(attack_ips + scanner_ips))
    if len(malicious_ips) == 0:
        print("✅ 无恶意IP，无需生成封禁指令")
        return

    print("⚠️  恶意IP列表：", malicious_ips)
    print("\n📝 Linux iptables 封禁指令（直接复制执行）：")
    print("-" * 60)
    for ip in malicious_ips:
        # 封禁入站流量：丢弃该IP的所有数据包
        rule = f"iptables -A INPUT -s {ip} -j DROP"
        print(rule)
    print("-" * 60)
    print("💡 执行说明：Linux root权限下运行，永久生效需保存规则")

# ====================== 主函数 ======================
if __name__ == "__main__":
    # 配置文件路径（修改为你的attack.pcap路径）
    ATTACK_PCAP_PATH = "./zuoye/attack.pcap"

    # 1. 解析流量数据
    traffic_df = parse_pcap_to_df(ATTACK_PCAP_PATH)
    if traffic_df is None or traffic_df.empty:
        print("❌ 无有效流量数据，退出检测")
        exit()

    # 2. 执行高频攻击检测（任务a）
    attack_ips, anomaly_df, high_freq_feature = detect_high_freq_attack(traffic_df)

    # 3. 执行端口扫描检测（任务b）
    scanner_ips, scan_feature = detect_port_scan(traffic_df)

    # 4. 生成防火墙封禁指令（任务c）
    generate_firewall_rules(attack_ips, scanner_ips)

    print("\n🎉 威胁检测完成！")
