// #include <stdio.h>

// int main () {
//     int cnt;
//     scanf("%d", &cnt);
//     int nums[cnt];
//     for (int i = 0; i < cnt; ++i) {
//         scanf("%d", &nums[i]);
//     }
//     for (int i = 0; i < cnt; ++i) {
//         for (int j = i; j < cnt; ++j) {
//             if (nums[i] > nums[j]) {
//                 int temp = nums[i];
//                 nums[i] = nums[j];
//                 nums[j] = temp;
//             }
//         }

//         printf("%d", nums[i]);
//         if (i < cnt-1) printf(" ");
//     }

//     return 0;
// }



#include <stdio.h>

int main() {
    int count;
    scanf("%d", &count);
    int nums[count];
    
    for (int i = 0; i < count; ++i) {
        scanf("%d", &nums[i]);
    }
    
    // 外层循环固定一位数字
    for (int i = 0; i < count; ++i) {
        // 内层循环寻找最小值
        for (int j = i; j < count; ++j) {
            // 若左大右小，交换数字
            if (nums[i] > nums[j]) {
                int temp_val = nums[i];
                nums[i] = nums[j];
                nums[j] = temp_val;
            }
        }
        // 借机输出
        printf("%d", nums[i]);
        // 判断空格输出
        if (i < count - 1) {
            printf(" ");
        }
    }
    
    return 0;
}