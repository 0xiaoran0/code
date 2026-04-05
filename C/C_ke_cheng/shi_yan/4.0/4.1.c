// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {
//     int num;
//     while ((scanf("%d", &num)) != EOF) {
//         if (num < 4 || num % 2 == 1) continue;

//         int* nums = (int*) malloc (sizeof(int) * num);
//         nums[0] = 2;
//         nums[1] = 3;
//         int index_judge = 0;
//         int index = 1;

//         for (int i = 4; i > nums[index_judge] &&  i < num; i++) {
//             int judge1 = 1;
//             for (; i >= nums[index_judge] * nums[index_judge]; ++index_judge) {
//                 if (i % nums[index_judge] == 0) judge1 = 0;
//             }
//             if (judge1) nums[++index] = i;
//             index_judge = 0;
//         }

//         int plus1 = 0, plus2 = 0;
//         int judge_exit = 0;
//         for (; num >= nums[plus1] + nums[0]; ++plus1) {
//             plus2 = 0;
//             if (judge_exit) break;

//             for (; num >= nums[plus1] + nums[plus2]; ++plus2) {
//                 if (num == nums[plus1] + nums[plus2]) {
//                     printf("%d=%d+%d\n", num, nums[plus1], nums[plus2]);
//                     judge_exit = 1;
//                     break;
//                 }
//             }
//         }

//         free(nums);
//     }
    
//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>

// 程序功能：验证哥德巴赫猜想
// 输入若干个整数
// 输出偶数为两个质数之和的形式
int main(void) {
    int target_num;
    
    // 循环读取整数，直到遇到EOF
    while ((scanf("%d", &target_num)) != EOF) {
        // 按照题目要求跳过小于4或奇数
        if (target_num < 4 || target_num % 2 == 1) {
            continue;
        }
        
        // 动态分配数组，用于构建质数表，有些情况下可以节省时间
        int* prime_nums = (int*)malloc(sizeof(int) * target_num);
        prime_nums[0] = 2;
        prime_nums[1] = 3;
        int prime_judge_index = 0;  // 用于遍历判断质数的索引
        int prime_index = 1;        // 用于存储的索引
        
        // 遍历4之后，用于筛选质数
        for (int i = 4; i < target_num && i > prime_nums[prime_judge_index]; i++) {
            int is_prime = 1;        //是否为质数标志
            
            // 判断质数
            for (; i >= prime_nums[prime_judge_index] * prime_nums[prime_judge_index]; ++prime_judge_index) {
                if (i % prime_nums[prime_judge_index] == 0) {
                    is_prime = 0;
                }
            }
            
            // 将质数存入数组
            if (is_prime) {
                prime_nums[++prime_index] = i;
            }
            prime_judge_index = 0;  // 重置索引
        }
        
        int prime1_index = 0;  // n1
        int prime2_index = 0;  // n2
        int find_flag = 0;     // 是否成立的标记
        
        // 遍历n1
        for (; target_num >= prime_nums[prime1_index] + prime_nums[0]; ++prime1_index) {
            prime2_index = 0;
            // 成立后退出
            if (find_flag) {
                break;
            }
            
            // 遍历n2
            for (; target_num >= prime_nums[prime1_index] + prime_nums[prime2_index]; ++prime2_index) {
                if (target_num == prime_nums[prime1_index] + prime_nums[prime2_index]) {
                    printf("%d=%d+%d\n", target_num, prime_nums[prime1_index], prime_nums[prime2_index]);
                    find_flag = 1;  // 成立后改变标记
                    break;
                }
            }
        }
        
        free(prime_nums);  // 释放内存，避免内存泄漏
    }
    
    return 0;
}