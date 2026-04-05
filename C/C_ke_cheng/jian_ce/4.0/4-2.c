#include <stdio.h>
// 求最大值
#define MAX(n1, n2, n3, max_n) max_n = (max_n > n1 ? max_n : n1);\
                            max_n = (max_n > n2 ? max_n : n2);\
                            max_n = (max_n > n3 ? max_n : n3);

// 求平均数
#define AVER(n1, n2, n3, aver_d) aver_d = (double)(n1 + n2 + n3) / 3.0;

int main () {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int max_n = n1;
    MAX(n1, n2, n3, max_n);

    double aver_d;
    AVER(n1, n2, n3 ,aver_d);

    // 对平均数进行四舍五入
    int aver_n;
    if (aver_d < 0) {
        aver_d *= -1;
        aver_n = (int) (aver_d + 0.5);
        aver_n *= -1;
    } else
        aver_n = (int) (aver_d + 0.5);

    printf("最大值: %d, 平均值: %d", max_n, aver_n);

    return 0;
}