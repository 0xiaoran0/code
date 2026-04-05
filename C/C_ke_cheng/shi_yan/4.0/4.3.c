// #include <stdio.h>
// int nums[100];

// int main(void) {
//     int k;
//     scanf("%d", &k);
//     while (k != 0) {
//         int start = 1;
//         int end = 10;
//         int index = 0;

//         for (int i = 0; i < k-1; ++i) {
//             start *= 10;
//             end *= 10;
//         }

//         for (int num = start; num < end; ++num) {
//             int sum = 0;
//             int n = num;
//             int num_ = num % 10;

//             while (num != 0) {
//                 int _ = num_;
//                 for (int i = 0; i < k-1; ++i) num_ *= _;
//                 sum += num_;
//                 num /= 10;
//                 num_ = num % 10;
//             }

//             num = n;
//             if (sum == num) {
//                 nums[index++] = num;
//             }
//         }

//         printf("%d位的水仙花数有:", k);
//         for (int i = 0; i < index; ++i) {
//             printf("%d,", nums[i]);
//         }
//         printf("共%d个\n", index);

//         scanf("%d", &k);
//     }
    
//     return 0;
// }



#include <stdio.h>
int nums[100];  // 存储找到的各种数字

int isnum (int current_num, int k) {
    int sum = 0;  // 存储 k 次幂之和
    int original_num = current_num;
    int current_digit = current_num % 10;

    while (current_num != 0) {
        int temp_digit = current_digit;  // 临时存储当前位数字，用于计算幂次

        for (int i = 0; i < k - 1; ++i) {
            current_digit *= temp_digit;
        }
        sum += current_digit;  // 累加
        current_num /= 10;     //更新数字
        current_digit = current_num % 10;
    }

    if (sum == original_num) return 1;
    else return 0;
}

int main(void) {
    int k;
    scanf("%d", &k);

    while (k != 0) {
        int start = 1;    // 目标位数数字的起始
        int end = 10;     // 目标位数数字的结束
        int index = 0;      // 索引
        
        // 计算目标数字范围
        for (int i = 0; i < k - 1; ++i) {
            start *= 10;
            end *= 10;
        }
        
        // 遍历 k 位数的所有数字
        for (int current_num = start; current_num < end; ++current_num) {
            int sum = 0;  // 存储 k 次幂之和
            int current_digit = current_num % 10;

            if (isnum(current_num, k)) {
                nums[index++] = current_num;
            }
        }
        
        // 输出
        switch (k) {
            case 3:printf("%d位的水仙花数有:", k); break;
            case 4:printf("%d位的四叶玫瑰数有:", k); break;
            case 5:printf("%d位的五角星数有:", k); break;
            case 6:printf("%d位的六合数有:", k); break;
            case 7:printf("%d位的北斗星数有:", k); break;
            case 8:printf("%d位的八仙数有:", k); break;
        }
        for (int i = 0; i < index; ++i) {
            printf("%d,", nums[i]);
        }
        printf("共%d个\n", index);
        
        // 读取下一个数
        scanf("%d", &k);
    }
    
    return 0;
}