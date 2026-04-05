# import dpkt
# import socket
# import pandas as pd
# import logging
# from datetime import datetime
# import os

# # ====================== 附加题2：日志配置（独立功能） ======================
# def init_log():
#     log_file = f"attack_log_{datetime.now().strftime('%Y%m%d')}.log"
#     logging.basicConfig(
#         level=logging.WARNING,
#         format="%(asctime)s - %(message)s",
#         handlers=[logging.FileHandler(log_file, encoding='utf-8'), logging.StreamHandler()]
#     )
#     return log_file

# # ====================== 基础威胁检测 ======================
# def detect_attack(df):
#     df["time_sec"] = df["timestamp"].astype(int)
#     ip_count = df.groupby("src_ip").size()
#     attack_ips = ip_count[ip_count > 50].index.tolist()
    
#     for ip in attack_ips:
#         # 实时写入日志 + 控制台输出
#         logging.warning(f"【异常】高频攻击源IP：{ip}")
#     return attack_ips

# # ====================== 解析PCAP ======================
# def parse_pcap(pcap_path):
#     results = []
#     with open(pcap_path, 'rb') as f:
#         pcap = dpkt.pcap.Reader(f)
#         for ts, buf in pcap:
#             eth = dpkt.ethernet.Ethernet(buf)
#             if isinstance(eth.data, dpkt.ip.IP):
#                 ip = eth.data
#                 results.append({
#                     "timestamp": ts,
#                     "src_ip": socket.inet_ntoa(ip.src)
#                 })
#     return pd.DataFrame(results)

# # ====================== 主函数 ======================
# if __name__ == "__main__":
#     log_file = init_log()
#     print(f"日志文件：{log_file}")
    
#     df = parse_pcap("./zuoye/attack.pcap")
#     detect_attack(df)
#     print("========== 附加题2：日志写入完成 ==========")












import dpkt
import socket
import pandas as pd
import logging
from datetime import datetime
import os

# ====================== 附加题2：日志配置 ======================
def setup_logger():
    log_file = f"attack_detection_{datetime.now().strftime('%Y%m%d_%H%M%S')}.log"
    logging.basicConfig(
        level=logging.INFO,
        format="%(asctime)s - %(levelname)s - %(message)s",
        handlers=[
            logging.FileHandler(log_file, encoding='utf-8'),
            logging.StreamHandler()
        ]
    )
    return log_file

# ====================== 通用PCAP解析函数 ======================
def parse_pcap_to_df(pcap_path):
    if not os.path.exists(pcap_path):
        logging.error(f"文件不存在：{pcap_path}")
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
                    "is_anomaly": False
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
                                "ACK": 1 if (flags & dpkt.tcp.TH_ACK) else 0
                            }
                        elif ip.p == dpkt.ip.IP_PROTO_UDP:
                            udp = ip.data
                            pkt_info["src_port"] = udp.sport
                            pkt_info["dst_port"] = udp.dport

                if pkt_info["src_ip"]:
                    results.append(pkt_info)

        logging.info(f"解析完成，共 {len(results)} 条报文")
        return pd.DataFrame(results)

    except Exception as e:
        logging.error(f"解析失败：{str(e)}")
        return None

# ====================== 攻击检测 ======================
def detect_high_freq_attack(df, freq_threshold=50):
    df["time_sec"] = df["timestamp"].astype(int)
    ip_sec_count = df.groupby(["src_ip", "time_sec"]).size().reset_index(name="pkt_count")
    high_freq = ip_sec_count[ip_sec_count["pkt_count"] > freq_threshold]
    attack_ips = high_freq["src_ip"].unique()

    for ip in attack_ips:
        logging.warning(f"【高频攻击】源IP={ip}")
    return attack_ips

def detect_port_scan(df, scan_threshold=10):
    df["time_sec"] = df["timestamp"].astype(int)
    scan_stats = df.groupby(["src_ip", "dst_ip", "time_sec"])["dst_port"].nunique().reset_index()
    scan_records = scan_stats[scan_stats["dst_port"] > scan_threshold]
    scanner_ips = scan_records["src_ip"].unique()

    for ip in scanner_ips:
        logging.warning(f"【端口扫描】源IP={ip}")
    return scanner_ips

# ====================== 防御指令 ======================
def generate_firewall_rules(all_malicious_ips):
    logging.info("\n封禁指令：")
    for ip in all_malicious_ips:
        logging.info(f"iptables -A INPUT -s {ip} -j DROP")

# ====================== 主函数 ======================
if __name__ == "__main__":
    setup_logger()
    ATTACK_PCAP_PATH = "./zuoye/attack.pcap"
    traffic_df = parse_pcap_to_df(ATTACK_PCAP_PATH)
    if traffic_df is None:
        exit()

    attack_ips = detect_high_freq_attack(traffic_df)
    scanner_ips = detect_port_scan(traffic_df)
    all_malicious = list(set(attack_ips + scanner_ips))

    if all_malicious:
        generate_firewall_rules(all_malicious)
    logging.info("检测完成！")
