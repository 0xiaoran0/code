#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// N 指字符串的个数，SIZE 是预估字符串的长度
#define N 2000
#define SIZE 50

int my_strlen (char *s);
void my_strcpy (char *s, char* s_po);
char* find_max (char (*s)[SIZE], int n, int* length);

int main () {

    char (*s)[SIZE] = (char(*)[SIZE]) malloc (sizeof(char) * N * SIZE);

    // 输入
    int index = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%s", s[i]);
        if (s[i][0] == '\0')
            break;
        else
            ++index;
    }

    // 执行函数，长度 length 由指针返回
    int length;
    char* s_po = find_max (s, index, &length);

    printf("%s %d", s_po, length);
    // 及时释放内存
    free (s);

    return 0;
}

// 自己复现了两个字符串函数
int my_strlen (char *s) {
    int length = 0;
    for (int j = 0; s[j]; ++j)
        ++length;

    return length;
}

void my_strcpy (char *s, char* s_po) {
    for (int i = 0; s[i] && i < SIZE; ++i) {
        s_po[i] = s[i];
        s_po[i + 1] = '\0';
    }
}

char* find_max (char (*s)[SIZE], int n, int* length) {
    // 用于储存最大值
    int max = 0;
    // 申请堆区内存，避免函数返回无效地址
    char* s_ret = (char*) malloc (sizeof(char) * SIZE);

    for (int i = 0; i < n; ++i) {
        int max_ = my_strlen (s[i]);
        if (max_ > max) {
            max = max_;
            my_strcpy (s[i], s_ret);
        }
    }

    // 处理返回值
    *length = max;
    return s_ret;
}