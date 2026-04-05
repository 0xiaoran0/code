#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义一个比较字符串的函数
int my_strcmp(char* s1, char* s2);
void strsort(char **strs, int n);

int main () {
    int n;
    scanf("%d", &n);

    // 输入
    char* str[n];
    for (int i = 0; i < n; ++i) {
        str[i] = (char*) malloc(sizeof(char) * 100);
        scanf("%s", str[i]);
    }

    // 排序输出，输出也可以整合到函数里
    strsort(str, n);
    for (int i = 0; i < n; ++i) {
        printf("%d: %s", i+1, str[i]);
        if (i < n-1)
            printf("\n");
    }

    return 0;
}

// 先逐个字符比较，再比长度
int my_strcmp(char* s1, char* s2) {
    int judge = 0;
    for (int i = 0; s1[i] && s2[i]; ++i) {
        if (s1[i] > s2[i]) {
            judge = 1;
            break;
        }
        if (s1[i] < s2[i]) {
            judge = -1;
            break;
        }
    }

    if (0 == judge) {
        if (strlen(s1) > strlen(s2))
            judge = 1;
        if (strlen(s1) < strlen(s2))
            judge = -1;
    }

    return judge;
}

// 冒泡排序
void strsort(char **strs, int n) {
    char s_[100];
    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j > i; --j) {
            if (my_strcmp(strs[j], strs[j-1]) > 0) {
                strcpy(s_, strs[j]);
                strcpy(strs[j], strs[j-1]);
                strcpy(strs[j-1], s_);
            }
        }
    }
}