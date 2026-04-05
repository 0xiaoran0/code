#include <stdio.h>
#include <stdlib.h>

void swap (int nums[], int n) {
    int m1, n1, m2, n2;
    scanf("%d %d %d %d", &m1, &n1, &m2, &n2);
    // 通过遍历将数组前半部分的内容按照交换后的顺序复制到后半部分
    // 复制的过程有些复杂，需要人判断复制到后半部分时的下标
    for (int i = 0; i < n; ++i) {
        if (i < m1) {
            nums[n+i] = nums[i];
        } else if (i >= m1 && i <= n1) {
            nums[n + n2 - n1 + i] = nums[i];
        } else if (i > n1 && i < m2) {
            nums[n + m1 + n2 - m2 + i - n1] = nums[i];
        } else if (i >= m2 && i <= n2) {
            nums[n + m1 + i - m2] = nums[i];
        } else {
            nums[n + i] = nums[i];
        }
    }
}

int main () {
    int n;
    scanf("%d", &n);
    // 开辟一个数组，长度为 2n(便于操作)
    int* nums = (int*) malloc (sizeof(int) * n * 2);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }

    swap(nums, n);
    // 遍历输出后半部分
    for (int i = n; i < 2 * n; ++i) {
        printf("%d", nums[i]);
        if (i < 2 * n - 1) printf(" ");
    }
    // 释放内存
    free(nums);

    return 0;
}