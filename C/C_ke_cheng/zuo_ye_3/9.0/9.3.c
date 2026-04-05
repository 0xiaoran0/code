#include <stdio.h>

// 定义结构体
typedef struct web {
    char na[20];
    char name[20];
    char url[50];
}web;

// 自己写出的字符串的复制、取长度、比大小、比较是否一致、交换
// 为了省事，此处并没有添加参数 n 防止越界
void my_strcpy(char* s1, char* s2);
int my_strlen(char* s);
int my_sort (char* s1, char*s2);
int my_strcomp(char* s, char* s1);
void str_exchange(char* s1, char* s2);

int main () {
    int n;
    scanf("%d", &n);
    web webs[n];
    // 输入
    for (int i = 0; i < n; ++i)
        scanf("%s %s %s", webs[i].url, webs[i].na, webs[i].name);

    // 通过冒泡排序对字符串进行排序
    for (int i = 0; i < n; ++i) {
        int j = n - 1;

        for (; j > i; --j) {
            if (my_sort(webs[j-1].na, webs[j].na)) {
                str_exchange(webs[j].na, webs[j-1].na);
                str_exchange(webs[j].name, webs[j-1].name);
                str_exchange(webs[j].url, webs[j-1].url);
            }
        }
    }

    char na[20];
    scanf("%s", na);

    // 顺序输出，顺便查找
    // judge 用于判断是否找到
    int judge = 0, index = 0;
    for (int i = 0; i < n; ++i) {
        printf("%s %s %s\n", webs[i].url, webs[i].na, webs[i].name);
        if (my_strcomp(na, webs[i].na)) {
            judge = 1;
            index = i;
        }
    }

    // 输出查找结果
    if (judge) 
        printf("%s", webs[index].url);

    return 0;
}

// 字符串的复制
void my_strcpy(char* s1, char* s2) {
    int index = 0;
    for (; s2[index]; ++index)
        s1[index] = s2[index];
    // 不能忘记最后的 '\0'
    s1[index] = '\0';
}

// 获得长度
int my_strlen(char* s) {
    int i = 0;
    for (; s[i]; ++i);
    return i;
}

// 比较大小
int my_sort (char* s1, char*s2) {
    // 用于标记大小关系，1: 前大于后
    int judge = 0;
    // 逐位比较
    for (int i = 0; s1[i] && s2[i]; ++i) {
        if (s1[i] > s2[i]) {
            judge = 1;
            break;
        }
    }

    // 再比较长度
    if (!judge) {
        if (my_strlen(s1) > my_strlen(s2))
            judge = 1;
    }

    return judge;
}

// 字符串一致性的比较
int my_strcomp(char* s, char* s1) {
    // 用于标记是否一致，1: 一致
    int judge = 1;

    // 先比较长度
    if (my_strlen(s) != my_strlen(s1))
        judge = 0;

    // 逐位比较
    if (judge) {
        for (int i = 0; s[i]; ++i) {
            if (s[i] != s1[i])
                judge = 0;
        }
    }

    return judge;
}

// 字符串的交换,依靠字符串的复制
void str_exchange(char* s1, char* s2) {
    char temp[50];
    my_strcpy(temp, s1);
    my_strcpy(s1, s2);
    my_strcpy(s2, temp);
}