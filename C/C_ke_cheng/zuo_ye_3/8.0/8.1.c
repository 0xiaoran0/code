#include <stdio.h>

void sort (int* nums, int count);

int main () {
    // 输入数的个数
    int count;
    scanf("%d", &count);

    // 输入数组
    int nums[count];
    for (int i = 0; i < count; ++i)
        scanf("%d", &nums[i]);

    // 排序
    sort(nums, count);

    // 输出
    for (int i = 0; i < count; ++i) {
        printf("%d", nums[i]);
        if (i < count - 1) printf(" ");
    }

    return 0;
}

void sort (int* nums, int count) {
    // 控制次数，防止重复交换
    int cnt;
    if (0 != count % 2) cnt = count / 2 + 1;
    else cnt = count / 2;

    // 前后交换
    for (int i = 0; i < count / 2; ++i) {
        // 采用了不使用临时变量的交换方式
        if (2 * i + 1 != count) {
            nums[count - i - 1] = nums[count - i - 1] + nums[i];
            nums[i] = nums[count - i - 1] - nums[i];
            nums[count - i - 1] = nums[count - i - 1] - nums[i];
        }
    }
}