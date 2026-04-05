#include <stdio.h>

int main (void) {
    int num;
    int count = 0, min = 9;
    scanf("%d", &num);
    while (num != 0) {
        int i = num % 10;
        if (i == 8) {
            count++;
        }
        if (i < min) {
            min = i;
        }
        num /= 10;
    }
    printf("该数有%d个8，最小数字是%d\n",count,min);

    return 0;
}