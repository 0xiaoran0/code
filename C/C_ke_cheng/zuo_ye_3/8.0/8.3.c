#include <stdio.h>

int isiden (int (*ma)[5]);

int main () {
    // 定义与输入
    int matrix[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 直接输出结果
    printf("%d", isiden(matrix));

    return 0;
}

int isiden (int (*ma)[5]) {
    int out = 1;
    // 遍历判断
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            // 检查主对角线是否为 1，及对角线之外是否为 0
            if (i != j) {
                if (0 != ma[i][j])
                    out = 0;
            } else {
                if (1 != ma[i][j])
                    out = 0;
            }
        }
    }

    return out;
}