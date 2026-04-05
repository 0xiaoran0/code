#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);

    // 初始化数组
    int fabonacci[n];
    fabonacci[0] = 1;
    fabonacci[1] = 1;
    int isplus = 1;
    int sn = 0;

    // 计算数组元素同时求和，利用一个数字确定正负号
    for (int i = 2; i < n; ++i) {
        fabonacci[i] = fabonacci[i - 1] + fabonacci[i - 2];
        sn += fabonacci[i] * isplus;
        isplus *= -1;
    }

    // 处理一下特殊情况
    if (1 ==  n) sn = 1;

    printf("%d", sn);

    return 0;
}