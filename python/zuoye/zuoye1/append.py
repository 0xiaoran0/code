import dpkt
import socket
import pandas as pd
import logging
from collections import defaultdict
import os
from datetime import datetime

# ====================== 【附加题2】Logging 配置：实时写入异常日志 ======================
def setup_logger():
    """配置logging模块，实时将攻击检测结果写入日志文件"""
    # 日志格式：时间 - 日志级别 - 检测信息
    log_format = "%(asctime)s - %(levelname)s - %(message)s"
    # 日志文件名（带时间戳，避免覆盖）
    log_file = f"attack_detection_{datetime.now().strftime('%Y%m%d_%H%M%S')}.log"
    
    # 基础配置：同时输出到控制台+日志文件，实时写入
    logging.basicConfig(
        level=logging.INFO,
        format=log_format,
        handlers=[
            logging.FileHandler(log_file, encoding='utf-8'),  # 写入文件
            logging.StreamHandler()  # 控制台打印
        ]
    )
    logging.info("✅ 威胁检测系统启动，日志实时写入文件中...")
    return log_file

# ====================== 通用PCAP解析函数 ======================
def parse_pcap_to_df(pcap_path):
    """解析pcap文件，新增TTL、报文长度扩展特征"""
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
                    "ttl": None,          # 【附加题1】新增TTL特征
                    "pkt_len": None,      # 【附加题1】新增报文长度特征
                    "tcp_flags": None,    # 【附加题1】新增TCP标志位特征
                    "is_anomaly": False,
                    "anomaly_type": "正常"
                }

                if pcap.datalink() == dpkt.pcap.DLT_EN10MB:
                    eth = dpkt.ethernet.Ethernet(buf)
                    if isinstance(eth.data, dpkt.ip.IP):
                        ip = eth.data
                        # 基础信息
                        pkt_info["src_ip"] = socket.inet_ntoa(ip.src)
                        pkt_info["dst_ip"] = socket.inet_ntoa(ip.dst)
                        pkt_info["protocol"] = protocol_names.get(ip.p, ip.p)
                        # 【附加题1】扩展特征赋值
                        pkt_info["ttl"] = ip.ttl
                        pkt_info["pkt_len"] = ip.len

                        # TCP解析（标志位）
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

        logging.info(f"✅ 流量解析完成，共加载 {len(results)} 条有效报文")
        return pd.DataFrame(results)

    except Exception as e:
        logging.error(f"解析失败：{str(e)}")
        return None

# ====================== 【基础检测】高频访问/端口扫描 ======================
def detect_high_freq_attack(df, freq_threshold=50):
    """高频DoS攻击检测"""
    df["time_sec"] = df["timestamp"].astype(int)
    ip_sec_count = df.groupby(["src_ip", "time_sec"]).size().reset_index(name="pkt_count")
    high_freq = ip_sec_count[ip_sec_count["pkt_count"] > freq_threshold]
    attack_ips = high_freq["src_ip"].unique()

    if len(attack_ips) > 0:
        for ip in attack_ips:
            target = df[df["src_ip"] == ip]["dst_ip"].mode()[0]
            msg = f"【高频攻击】源IP={ip} -> 目标IP={target}，报文数={freq_threshold}+条/秒"
            logging.warning(msg)  # 实时写入日志
            df.loc[df["src_ip"] == ip, ["is_anomaly", "anomaly_type"]] = [True, "高频DoS攻击"]
    return attack_ips, df

def detect_port_scan(df, scan_threshold=10):
    """端口扫描检测"""
    df["time_sec"] = df["timestamp"].astype(int)
    scan_stats = df.groupby(["src_ip", "dst_ip", "time_sec"])["dst_port"].nunique().reset_index()
    scan_records = scan_stats[scan_stats["dst_port"] > scan_threshold]
    scanner_ips = scan_records["src_ip"].unique()

    if len(scanner_ips) > 0:
        for ip in scanner_ips:
            target = df[df["src_ip"] == ip]["dst_ip"].mode()[0]
            msg = f"【端口扫描】源IP={ip} -> 目标IP={target}，扫描端口数={scan_threshold}+个"
            logging.warning(msg)  # 实时写入日志
            df.loc[df["src_ip"] == ip, ["is_anomaly", "anomaly_type"]] = [True, "端口扫描"]
    return scanner_ips, df

# ====================== 【附加题1】扩展攻击检测特征 ======================
def detect_extended_attacks(df):
    """
    新增4类攻击识别特征（除报文数量外）：
    1. TTL异常：攻击流量TTL固定值（正常流量波动）
    2. 报文长度异常：DoS攻击报文长度完全一致
    3. SYN Flood：大量无ACK的SYN包
    4. 暴力破解：单IP对单端口高频访问
    """
    malicious_ips = []
    # 1. TTL异常检测（TTL固定=攻击特征，正常TTL波动）
    ttl_stats = df.groupby("src_ip")["ttl"].nunique()
    ttl_anomaly_ips = ttl_stats[ttl_stats == 1].index.tolist()
    for ip in ttl_anomaly_ips:
        logging.warning(f"【TTL异常攻击】源IP={ip}，TTL值固定，疑似攻击工具流量")
        df.loc[df["src_ip"] == ip, ["is_anomaly", "anomaly_type"]] = [True, "TTL异常攻击"]
        malicious_ips.append(ip)

    # 2. 报文长度异常检测（长度无波动）
    len_stats = df.groupby("src_ip")["pkt_len"].nunique()
    len_anomaly_ips = len_stats[len_stats == 1].index.tolist()
    for ip in len_anomaly_ips:
        logging.warning(f"【报文长度异常】源IP={ip}，报文长度完全一致，疑似Flood攻击")
        df.loc[df["src_ip"] == ip, ["is_anomaly", "anomaly_type"]] = [True, "长度异常攻击"]
        malicious_ips.append(ip)

    # 3. SYN Flood攻击检测（只有SYN标志，无ACK）
    syn_df = df.dropna(subset=["tcp_flags"])
    syn_flood_ips = syn_df[syn_df["tcp_flags"].apply(lambda x: x["SYN"] == 1 and x["ACK"] == 0)]["src_ip"].unique()
    for ip in syn_flood_ips:
        logging.warning(f"【SYN Flood攻击】源IP={ip}，大量无效SYN包")
        df.loc[df["src_ip"] == ip, ["is_anomaly", "anomaly_type"]] = [True, "SYN Flood攻击"]
        malicious_ips.append(ip)

    # 4. 暴力破解检测（单IP对单端口高频访问）
    brute_force = df.groupby(["src_ip", "dst_port"]).size().reset_index(name="count")
    brute_ips = brute_force[brute_force["count"] > 30]["src_ip"].unique()
    for ip in brute_ips:
        logging.warning(f"【暴力破解攻击】源IP={ip}，单端口高频访问")
        df.loc[df["src_ip"] == ip, ["is_anomaly", "anomaly_type"]] = [True, "暴力破解攻击"]
        malicious_ips.append(ip)

    return list(set(malicious_ips)), df

# ====================== 生成防火墙封禁指令 ======================
def generate_firewall_rules(all_malicious_ips):
    logging.info("\n========== Linux iptables 防御指令 ==========")
    for ip in all_malicious_ips:
        rule = f"iptables -A INPUT -s {ip} -j DROP"
        logging.info(f"封禁IP {ip}：{rule}")

# ====================== 主函数 ======================
if __name__ == "__main__":
    # 1. 初始化日志系统（附加题2核心）
    log_file = setup_logger()
    logging.info(f"📝 日志文件保存路径：{os.path.abspath(log_file)}")

    # 2. 配置文件路径
    ATTACK_PCAP_PATH = "./zuoye/attack.pcap"

    # 3. 解析流量
    traffic_df = parse_pcap_to_df(ATTACK_PCAP_PATH)
    if traffic_df is None:
        logging.error("程序退出：无有效流量数据")
        exit()

    # 4. 执行多维攻击检测
    attack_ips, df1 = detect_high_freq_attack(traffic_df)
    scanner_ips, df2 = detect_port_scan(df1)
    extend_ips, final_df = detect_extended_attacks(df2)

    # 5. 汇总恶意IP并生成防御规则
    all_malicious = list(set(attack_ips + scanner_ips + extend_ips))
    if all_malicious:
        logging.info(f"\n🎯 汇总恶意IP：{all_malicious}")
        generate_firewall_rules(all_malicious)
    else:
        logging.info("\n✅ 未检测到任何攻击流量")

    logging.info("🎉 威胁检测任务完成！")
