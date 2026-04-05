import dpkt
# from dpkt import sll, sll2
import socket
import pandas as pd

def extract_metadata(pcap_path):
    results = []
    protocol_names = {6: 'TCP', 17: 'UDP', 1: 'ICMP'}   # 一些常用的传输层协议号
    # {1: 'ICMP', 2: 'IGMP', 4: 'IP', 6: 'TCP', 8: 'EGP', 9: 'IGP', 17: 'UDP', 41: 'IPv6', 50: 'ESP', 51: 'AH', 58: 'ICMP-IPv6', 89: 'OSPF'}
    with open(pcap_path, 'rb') as f:
        pcap = dpkt.pcap.Reader(f)
        for ts, buf in pcap:        # ts表示时间戳，buf是报文数据
            if pcap.datalink() == dpkt.pcap.DLT_EN10MB: # Ethernet以太网帧格式
                eth = dpkt.ethernet.Ethernet(buf)       # 解析以太网帧
                if isinstance(eth.data, dpkt.ip.IP):
                    ip = eth.data                   # 解析IP数据包格式
                    metadata = {
                        "timestamp": ts,
                        "src_ip": socket.inet_ntoa(ip.src),
                        "dst_ip": socket.inet_ntoa(ip.dst),
                        "protocol": protocol_names.get(ip.p, ip.p),
                        "ttl": ip.ttl,
                        "length": ip.len
                    }

                    if ip.p == dpkt.ip.IP_PROTO_TCP:    # 解析传输层TCP报文格式
                        flag_stats = {'SYN': 0, 'ACK': 0, 'PSH': 0, 'FIN': 0, 'RST': 0}
                        tcp = ip.data
                        flags = tcp.flags
                        if flags & dpkt.tcp.TH_ACK:
                            flag_stats['ACK'] += 1
                        elif flags & dpkt.tcp.TH_PUSH:
                            flag_stats['PSH'] += 1
                        elif flags & dpkt.tcp.TH_RST:
                            flag_stats['RST'] += 1
                        elif flags & dpkt.tcp.TH_SYN:
                            flag_stats['SYN'] += 1
                        elif flags & dpkt.tcp.TH_FIN:
                            flag_stats['FIN'] += 1

                        metadata.update({
                            "src_port": tcp.sport,      # 记录TCP通信的端口
                            "dst_port": tcp.dport,
                            "tcp_flags": flag_stats     # 记录TCP报文的标志位
                        })

                    elif ip.p == dpkt.ip.IP_PROTO_UDP:
                        udp = ip.data
                        metadata.update({
                            "src_port": udp.sport,      # 记录UDP通信的端口
                            "dst_port": udp.dport
                        })
                    results.append(metadata)

            elif pcap.datalink() == dpkt.pcap.DLT_LINUX_SLL or pcap.datalink() == dpkt.pcap.DLT_LINUX_SLL2:    # Linux 特有的伪链路层格式
                print("DLT_LINUX_SLL or DLT_LINUX_SLL2")
            else:
                continue
    df = pd.DataFrame(results)
    print("\nTop 5 Source IPs:")
    print(df['src_ip'].value_counts().head())
    print("\nProtocol Distribution:")
    print(df['protocol'].value_counts())
    return results

extract_metadata("zuoye/http.pcap")