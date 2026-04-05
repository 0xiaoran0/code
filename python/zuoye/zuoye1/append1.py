# import dpkt
# import socket
# import pandas as pd
# from collections import defaultdict
# import os

# # ====================== 通用PCAP解析 ======================
# def parse_pcap(pcap_path):
#     results = []
#     protocol_names = {6: 'TCP', 17: 'UDP', 1: 'ICMP'}
#     with open(pcap_path, 'rb') as f:
#         pcap = dpkt.pcap.Reader(f)
#         for ts, buf in pcap:
#             pkt = {
#                 "src_ip": None, "dst_ip": None, "ttl": None,
#                 "pkt_len": None, "tcp_flags": None, "protocol": None
#             }
#             if pcap.datalink() == dpkt.pcap.DLT_EN10MB:
#                 eth = dpkt.ethernet.Ethernet(buf)
#                 if isinstance(eth.data, dpkt.ip.IP):
#                     ip = eth.data
#                     pkt["src_ip"] = socket.inet_ntoa(ip.src)
#                     pkt["dst_ip"] = socket.inet_ntoa(ip.dst)
#                     pkt["ttl"] = ip.ttl
#                     pkt["pkt_len"] = ip.len
#                     pkt["protocol"] = protocol_names.get(ip.p, ip.p)

#                     if ip.p == 6:
#                         tcp = ip.data
#                         pkt["tcp_flags"] = {
#                             "SYN": 1 if (tcp.flags & dpkt.tcp.TH_SYN) else 0,
#                             "ACK": 1 if (tcp.flags & dpkt.tcp.TH_ACK) else 0
#                         }
#             results.append(pkt)
#     return pd.DataFrame(results)

# # ====================== 附加题1：扩展攻击特征检测 ======================
# def detect_extend_features(df):
#     print("========== 附加题1：扩展攻击特征检测结果 ==========")
#     # 1. TTL异常（固定不变=攻击）
#     ttl_anomaly = df.groupby("src_ip")["ttl"].nunique()
#     ttl_ips = ttl_anomaly[ttl_anomaly == 1].index.tolist()
    
#     # 2. 报文长度异常（长度固定=攻击）
#     len_anomaly = df.groupby("src_ip")["pkt_len"].nunique()
#     len_ips = len_anomaly[len_anomaly == 1].index.tolist()
    
#     # 3. SYN Flood（只有SYN无ACK）
#     syn_ips = []
#     tcp_df = df.dropna(subset=["tcp_flags"])
#     syn_ips = tcp_df[tcp_df["tcp_flags"].apply(lambda x: x["SYN"]==1 and x["ACK"]==0)]["src_ip"].unique()
    
#     # 4. 暴力破解（单IP单端口高频）
#     brute = df.groupby(["src_ip"])["dst_ip"].count()
#     brute_ips = brute[brute>50].index.tolist()

#     # 输出结果
#     print(f"TTL异常攻击IP：{ttl_ips}")
#     print(f"报文长度固定IP：{len_ips}")
#     print(f"SYN Flood攻击IP：{list(syn_ips)}")
#     print(f"疑似暴力破解IP：{brute_ips}")

# # ====================== 主函数 ======================
# if __name__ == "__main__":
#     df = parse_pcap("./zuoye/attack.pcap")
#     detect_extend_features(df)













import dpkt
import socket
import pandas as pd
from collections import defaultdict
import os

# ====================== 通用PCAP解析函数 ======================
def parse_pcap_to_df(pcap_path):
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
                    "ttl": None,
                    "pkt_len": None,
                    "tcp_flags": None,
                    "is_anomaly": False,
                    "anomaly_type": "正常"
                }

                if pcap.datalink() == dpkt.pcap.DLT_EN10MB:
                    eth = dpkt.ethernet.Ethernet(buf)
                    if isinstance(eth.data, dpkt.ip.IP):
                        ip = eth.data
                        pkt_info["src_ip"] = socket.inet_ntoa(ip.src)
                        pkt_info["dst_ip"] = socket.inet_ntoa(ip.dst)
                        pkt_info["protocol"] = protocol_names.get(ip.p, ip.p)
                        pkt_info["ttl"] = ip.ttl
                        pkt_info["pkt_len"] = ip.len

                        if ip.p == dpkt.ip.IP_PROTO_TCP:
                            tcp = ip.data
                            pkt_info["src_port"] = tcp.sport
                            pkt_info["dst_port"] = tcp.dport
                            flags = tcp.flags
                            pkt_info["tcp_flags"] = {
                                "SYN": 1 if (flags & dpkt.tcp.TH_SYN) else 0,
                                "ACK": 1 if (flags & dpkt.tcp.TH_ACK) else 0,
                                "RST": 1 if (flags & dpkt.tcp.TH_RST) else 0
                            }
                        elif ip.p == dpkt.ip.IP_PROTO_UDP:
                            udp = ip.data
                            pkt_info["src_port"] = udp.sport
                            pkt_info["dst_port"] = udp.dport

                if pkt_info["src_ip"]:
                    results.append(pkt_info)

        return pd.DataFrame(results)

    except Exception as e:
        print(f"❌ 解析失败：{str(e)}")
        return None

# ====================== 高频攻击检测 ======================
def detect_high_freq_attack(df, freq_threshold=50):
    df["time_sec"] = df["timestamp"].astype(int)
    ip_sec_count = df.groupby(["src_ip", "time_sec"]).size().reset_index(name="pkt_count")
    high_freq = ip_sec_count[ip_sec_count["pkt_count"] > freq_threshold]
    attack_ips = high_freq["src_ip"].unique()

    if len(attack_ips) > 0:
        for ip in attack_ips:
            target = df[df["src_ip"] == ip]["dst_ip"].mode()[0]
            print(f"【高频攻击】源IP={ip} -> 目标IP={target}")
            df.loc[df["src_ip"] == ip, ["is_anomaly", "anomaly_type"]] = [True, "高频DoS攻击"]
    return attack_ips, df

# ====================== 端口扫描检测 ======================
def detect_port_scan(df, scan_threshold=10):
    df["time_sec"] = df["timestamp"].astype(int)
    scan_stats = df.groupby(["src_ip", "dst_ip", "time_sec"])["dst_port"].nunique().reset_index()
    scan_records = scan_stats[scan_stats["dst_port"] > scan_threshold]
    scanner_ips = scan_records["src_ip"].unique()

    if len(scanner_ips) > 0:
        for ip in scanner_ips:
            target = df[df["src_ip"] == ip]["dst_ip"].mode()[0]
            print(f"【端口扫描】源IP={ip} -> 目标IP={target}")
            df.loc[df["src_ip"] == ip, ["is_anomaly", "anomaly_type"]] = [True, "端口扫描"]
    return scanner_ips, df

# ====================== 附加题1：扩展攻击特征 ======================
def detect_extended_attacks(df):
    malicious_ips = []
    print("\n========== 附加题1：扩展攻击特征检测 ==========")

    ttl_stats = df.groupby("src_ip")["ttl"].nunique()
    ttl_anomaly_ips = ttl_stats[ttl_stats == 1].index.tolist()
    for ip in ttl_anomaly_ips:
        print(f"【TTL异常攻击】源IP={ip}")
        df.loc[df["src_ip"] == ip, ["is_anomaly", "anomaly_type"]] = [True, "TTL异常攻击"]
        malicious_ips.append(ip)

    len_stats = df.groupby("src_ip")["pkt_len"].nunique()
    len_anomaly_ips = len_stats[len_stats == 1].index.tolist()
    for ip in len_anomaly_ips:
        print(f"【报文长度异常】源IP={ip}")
        df.loc[df["src_ip"] == ip, ["is_anomaly", "anomaly_type"]] = [True, "长度异常攻击"]
        malicious_ips.append(ip)

    syn_df = df.dropna(subset=["tcp_flags"])
    syn_flood_ips = syn_df[syn_df["tcp_flags"].apply(lambda x: x["SYN"] == 1 and x["ACK"] == 0)]["src_ip"].unique()
    for ip in syn_flood_ips:
        print(f"【SYN Flood攻击】源IP={ip}")
        df.loc[df["src_ip"] == ip, ["is_anomaly", "anomaly_type"]] = [True, "SYN Flood攻击"]
        malicious_ips.append(ip)

    brute_force = df.groupby(["src_ip", "dst_port"]).size().reset_index(name="count")
    brute_ips = brute_force[brute_force["count"] > 30]["src_ip"].unique()
    for ip in brute_ips:
        print(f"【暴力破解攻击】源IP={ip}")
        df.loc[df["src_ip"] == ip, ["is_anomaly", "anomaly_type"]] = [True, "暴力破解攻击"]
        malicious_ips.append(ip)

    return list(set(malicious_ips)), df

# ====================== 生成防御指令 ======================
def generate_firewall_rules(all_malicious_ips):
    print("\n========== 防火墙封禁指令 ==========")
    for ip in all_malicious_ips:
        print(f"iptables -A INPUT -s {ip} -j DROP")

# ====================== 主函数 ======================
if __name__ == "__main__":
    ATTACK_PCAP_PATH = "./zuoye/attack.pcap"
    traffic_df = parse_pcap_to_df(ATTACK_PCAP_PATH)
    if traffic_df is None:
        exit()

    attack_ips, df1 = detect_high_freq_attack(traffic_df)
    scanner_ips, df2 = detect_port_scan(df1)
    extend_ips, final_df = detect_extended_attacks(df2)

    all_malicious = list(set(attack_ips + scanner_ips + extend_ips))
    if all_malicious:
        generate_firewall_rules(all_malicious)
