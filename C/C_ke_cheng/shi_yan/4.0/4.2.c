// #include <stdio.h>
// int nums[10000];

// int fun (int x, int* index) {
//     *index = -1;
//     int sum = 0;
//     int judge = 0;

//     for (int x_ = 1; x_ < x; ++x_) {
//         if (x % x_ == 0) {
//             nums[++*index] = x_;
//         }
//     }

//     for (int i = 0; i <= *index; ++i) {
//         sum += nums[i];
//     }

//     if (x == sum) judge = 1;
//     return judge;
// }

// int main(void) {
//     for (int i = 2; i <= 10000; ++i) {
//         int cnt;
//         int judge = fun(i, &cnt);
//         if (judge) {
//             printf("%d=%d", i, nums[0]);
//             for (int i = 1; i <= cnt; ++i) {
//                 printf("+%d", nums[i]);
//             }
//             printf("\n");
//         }
//     }
    
//     return 0;
// }



#include <stdio.h>

#define MAX_NUM 10000  // 范围上限
int factor_array[MAX_NUM];  // 存储真因子

int is_perfect_number(int target_num, int* factor_index) {
    *factor_index = -1;  // 用于返回因子个数
    int factor_sum = 0;
    int is_perfect = 0;  // 完数的标记

    // 遍历真因子，并存入数组
    for (int divisor = 1; divisor < target_num; ++divisor) {
        if (target_num % divisor == 0) {
            factor_array[++*factor_index] = divisor;
        }
    }

    // 计算真因子的和
    for (int i = 0; i <= *factor_index; ++i) {
        factor_sum += factor_array[i];
    }

    // 更改标记
    if (target_num == factor_sum) {
        is_perfect = 1;
    }

    return is_perfect;
}

int main(void) {
    // 遍历2到MAX_NUM并判断完数
    for (int i = 2; i <= MAX_NUM; ++i) {
        int factor_count;  // 因子个数，通过指针更改
        
        int is_perfect = is_perfect_number(i, &factor_count);

        // 是完数则输出对应格式
        if (is_perfect) {
            printf("%d=%d", i, factor_array[0]);
            
            // 遍历输出因子
            for (int j = 1; j <= factor_count; ++j) {
                printf("+%d", factor_array[j]);
            }
            printf("\n");
        }
    }

    return 0;
}