#include <stdio.h>

int main () {
    int counts[3] = {0};
    char ch;
    // 循环输入
    while ((scanf("%c", &ch) == 1)) {
        if (ch >= '0' && ch <= '9') {
            ++counts[0];
        // 判断字母拆为两行防止过长影响阅读与理解
        } else if (ch >= 'a' && ch <= 'z') {
            ++counts[1];
        } else if (ch >= 'A' && ch <= 'Z') {
            ++counts[1];
        } else {
            ++counts[2];
        }
    }

    // 输出
    printf("%d %d %d", counts[0], counts[1], counts[2]);

    return 0;
}