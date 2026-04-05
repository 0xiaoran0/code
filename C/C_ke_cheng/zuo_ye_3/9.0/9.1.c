#include <stdio.h>
// 存储每月日期
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 建立结构体
typedef struct {
    int ye;
    int mon;
    int da;
} dates;

int main () {
    // 输入
    dates date;
    scanf("%d %d %d", &date.ye, &date.mon, &date.da);
    int day = 0;

    // 处理特殊情况
    if (0 == date.ye % 4 && 0 != date.ye % 100 || 0 == date.ye)
        days[1] = 29;
    else
        days[1] = 28;

    // 处理越界
    if (date.da > days[date.mon - 1]) {
        printf("error");
    } else {
        // 循环求和
        for (int i = 0; i < date.mon - 1; ++i)
            day += days[i];
        day += date.da;
        printf("%d", day);
    }

    return 0;
}