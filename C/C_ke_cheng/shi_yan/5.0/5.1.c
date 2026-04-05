#include <stdio.h>

void num_2 (int num, int index, char number_2[]);

int main () {
    int num;
    char number_2[32] = {0};
    int index = 31;
    scanf("%d", &num);

    // 正负数分开处理
    if (num >= 0) {
        num_2(num, index, number_2);
    } else {
        // 负数先变为正数，-1再按位取反即可
        num = -num;
        num -= 1;
        num_2(num, index, number_2);
        for (int i = 0; i < 32; ++i) {
            if ('1' == number_2[i]) number_2[i] = '0';
            else number_2[i] = '1';
        }
    }

    // 顺序输入，空位补零
    for (int i = 0; i < 32; ++i) {
        if (number_2[i]) printf("%c", number_2[i]);
        else printf("%c", '0');
    }

    return 0;
}

void num_2 (int num, int index, char number_2[]) {
    // 逆序得到每一位并存入数组
    while (num) {
        int digit = num % 2;
        num /= 2;
        number_2[index] = digit + '0';
        --index;
    }
}