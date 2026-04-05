#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IP_LENGTH 16
typedef struct IPRecord {
    char target_ip[IP_LENGTH]; // 目标设备IP地址，用点分十进制表示
    int packet_count; //发往目标设备的包数量
    int TCP_count; //发往目标设备的使用TCP传输协议的包数量
    struct IPRecord *next;
} IPRecord;

// 从整行数字中获取 ip 地址和 tcp 协议
void ip_out (char* in_con, char* ips);
void tcp_out (char* in_con, char* ycp);
int num_re (int x);
char* num_ch (int x);
int num_n (int x);

int main () {
    // 打开需要读取和写入的文件
    char* fi_in = "input.txt";
    char* fi_out = "output.txt";
    FILE* file_in = fopen (fi_in, "r");
    FILE* file_out = fopen (fi_out, "w");

    // 初始化链表
    IPRecord* head = (IPRecord*) malloc (sizeof(IPRecord));
    head -> next = NULL;
    IPRecord* index = head -> next;
    IPRecord* tail = head;
    int cnt = 0;       // 记录 IP 的个数

    // 存储获取的整行数字、IP地址
    char in_con[120] = {0};
    char ips[16] = {[3] = '.', [7] = '.', [11] = '.'};
    // 存储 tcp 协议以及目标
    char tcp[3] = {0};
    char tg_tcp[3] = "06";

    // 开始循环读取
    fgets(in_con, 120, file_in);
    while (in_con[0] != 0) {
        // 获取 IP 和 tcp协议，并标记是否相同
        ip_out(in_con, ips);
        int isip = -1;
        tcp_out(in_con, tcp);
        int istcp = strcmp(tg_tcp, tcp);

        while (index != NULL) {
            // 判断是否相同
            isip = strcmp(index -> target_ip, ips);
            // 相同则更新数据
            if (0 == isip) {
                ++(index -> packet_count);
                if (0 == istcp)
                    ++(index -> TCP_count);

                break;
            }
            index = index -> next;
        }

        if (-1 == isip) {
            // 不同则新建节点
            IPRecord* p = (IPRecord*) malloc (sizeof(IPRecord));
            ++cnt;
            // 初始化节点
            strcpy(p -> target_ip, ips);
            p -> packet_count = 1;
            if (0 == istcp)
                p -> TCP_count = 1;
            else
                p -> TCP_count = 0;
            p -> next = NULL;
            // 将节点添加至链表
            if (tail == head) {
                head -> next = p;
                tail = p;
            } else {
                tail -> next = p;
                tail = tail -> next;
                tail -> next = NULL;
            }
        }

        // 将数据复原，并读取数据进入下一次循环
        index = head -> next;
        in_con[0] = 0;
        fgets(in_con, 120, file_in);
    }

    // 用数组存储各个节点，便于排序
    IPRecord* sort[cnt];
    for (int i = 0; i < cnt; ++i) {
        sort[i] = index;
        index = index -> next;
    }

    // 使用冒泡排序
    for (int i = cnt-1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (sort[j]->packet_count < sort[j+1]->packet_count || \
                sort[j]->packet_count == sort[j+1]->packet_count && \
                sort[j]->TCP_count < sort[j+1]->TCP_count) {
                IPRecord* p = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = p;
            }
        }
    }

    // 输入上方名词
    fputs("target_IP        packet_cnt  TCP_cnt\n", file_out);
    for (int i = 0; i < cnt; ++i) {
        // 标记 IP 中的 0，防止".001"的形式，并统计IP的位数用于输入空格
        int state = 0;
        int cnt_ip = 0;
        // 循环输入 IP 地址
        for (int j = 0; j < 15; ++j) {
            if (0 == state) {
                if ('0' != sort[i]->target_ip[j]) {
                    fputc(sort[i]->target_ip[j], file_out);
                    ++cnt_ip;
                    state = 1;
                }
                continue;
            }
            if (1 == state) {
                fputc(sort[i]->target_ip[j], file_out);
                ++cnt_ip;
                if ('.' == sort[i]->target_ip[j])
                    state = 0;
                continue;
            }
        }
        // 输入 IP 后的空格
        for (int j = 0; j < 17-cnt_ip; ++j)
            fputc(' ', file_out);

        // 输入包的个数
        fwrite(num_ch(sort[i]->packet_count), 1, 12, file_out);
        // 输入是使用 tcp 协议的个数
        int tcp_cnt = num_n(sort[i]->TCP_count);
        // 处理特殊情况 0
        if (0 == sort[i]->TCP_count)
            tcp_cnt = 1;
        fwrite(num_ch(sort[i]->TCP_count), 1, tcp_cnt, file_out);
        // 处理换行
        if (i < cnt - 1)
            fputc('\n', file_out);
    }

    // 关闭文件并置空指针
    fclose(file_in);
    fclose(file_out);
    file_in = file_out = NULL;

    return 0;
}

// 取出 IP 地址
void ip_out (char* in_con, char* ips) {
    // 存储ip地址的一个字节和其中一位数字
    int ip_ns = 0;
    int ip_n = 0;
    // 内容与ip 的下标
    int index_con = 48;
    int index_ips = 2;
    // 遍历四个字节
    for (int i = 0; i < 4; ++i) {
        // 将字节逐个取出，并转换为十进制
        for (int j = 0; j < 2; ++j) {
            if (in_con[index_con] >= '0' && in_con[index_con] <= '9')
                ip_n = in_con[index_con] - '0';
            if (in_con[index_con] >= 'A' && in_con[index_con] <= 'F')
                ip_n = in_con[index_con] - 'A' + 10;
            ip_ns = ip_ns * 16 + ip_n;
            ++index_con;
        }
        index_con += 1;
        //将内容逆序输入字符串
        for (int j = 0; j < 3; ++j) {
            int i = ip_ns % 10;
            ips[index_ips] = i + '0';
            ip_ns /= 10;
            --index_ips;
        }
        index_ips += 7;
    }
}

// 取出 tcp协议
void tcp_out (char* in_con, char* tcp) {
    int index = 27;
    for (int i = 0; i < 2; ++i)
        tcp[i] = in_con[index++];
}

// 将数字逆序输出，用于将数字转为字符串
int num_re (int x) {
    int x_re = 0;
    while (x > 0) {
        x_re = x_re * 10 + x % 10;
        x /= 10;
    }
    return x_re;
}

// 将数字转为字符串
char* num_ch (int x) {
    x = num_re(x);
    // 在堆区开辟，用于返回指针
    char* x_ch = (char*) malloc (sizeof(char) * 12);
    // 从低位开始输入字符串
    for (int i = 0; i < 12; ++i) {
        if (0 == i && x == 0) {
            x_ch[i] = '0';
            continue;
        }
        if (x > 0) {
            x_ch[i] = x % 10 + '0';
            x /= 10;
            continue;
        } else {
            x_ch[i] = ' ';
        }
    }

    return x_ch;
}

// 返回正数的位数
int num_n (int x) {
    int cnt = 0;
    while (x > 0) {
        ++cnt;
        x /= 10;
    }
    return cnt;
}