#include <stdio.h>

void sort (int* nums, int n);

int main () {
    // 输入整数个数
    int n;
    scanf("%d", &n);
    // 依次输入整数
    int nums[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &nums[i]);

    // 选择排序
    sort(nums, n);
    // 遍历输出，控制空格的输出
    for (int i = 0; i < n; ++i) {
        printf("%d", nums[i]);
        if (i < n - 1) printf(" ");
    }

    return 0;
}

void sort (int* nums, int n) {
    // 外层遍历数组内元素
    for (int i = 0; i < n; ++i) {

        // 内层遍历外层元素后面的元素，符合要求则交换
        for (int j = i + 1; j < n; ++j) {
            
            if (nums[i] > nums[j]) {
                // 利用临时变量交换两个数值
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}