#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);

    // char* 一次移动一个字节，便于操作
    unsigned char* curr_digit = (unsigned char*)&num;

    for (int i = 3; i >= 0; --i) {
        // 此处的输出也可以不用 %X, 自己写一个
        // 除了使用整除、取余，也可以使用位运算
        printf("%X%X", curr_digit[i] / 16, curr_digit[i] % 16);
    }
    
    return 0;
}