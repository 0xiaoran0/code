// #include <stdio.h>

// int main(void) {
//     int nums;
//     scanf("%d", &nums);
//     int nums_ = nums;
//     int num = nums % 10;
//     int judge = 1;

//     while (num) {

//         if (num == 1 && num == 2) {
//             judge = 0;
//         } else {
//             int judgement = 0;
//             for (int i = 2; i < num; ++i) {
//                 if (num % i == 0) judgement = 1;
//             }

//             if (!judgement) judge = 0;
//         }

//         nums /= 10;
//         num = nums % 10;
//     }

//     if (judge) printf("%d是纯粹合数", nums_);
//     else printf("%d不是纯粹合数", nums_);
    
//     return 0;
// }



// #include <stdio.h>                       // 修改后的
// int main(void) {
//     int input_num;
//     scanf("%d", &input_num);
//     int original_num = input_num;
//     int current_digit = input_num % 10;  // 当前正在判断的数字
//     int is_pure = 1;      // 标记是否为纯粹合数

//     while (current_digit != 0) {
//         if (current_digit == 1 || current_digit == 2) {
//             is_pure = 0;
//         } else {
//             int is_div = 0;  // 标记当前数字是否为合数

//             for (int i = 2; i < current_digit; ++i) {
//                 if (current_digit % i == 0) {
//                     is_div = 1;
//                 }
//             }

//             if (!is_div) is_pure = 0;
//         }

//         // 更新
//         input_num /= 10;
//         current_digit = input_num % 10;
//     }

//     // 输出
//     if (is_pure) {
//         printf("%d是纯粹合数", original_num);
//     } else {
//         printf("%d不是纯粹合数", original_num);
//     }
    
//     return 0;
// }



// #include <stdio.h>        // 发现写错了，但答案对了，又改一下
// int main(void) {
//     int input_num;
//     scanf("%d", &input_num);
//     int original_num = input_num;
//     int current_digit = input_num;  // 当前正在判断的数字
//     int is_pure = 1;      // 标记是否为纯粹合数

//     while (current_digit != 0) {
//         if (current_digit == 1 || current_digit == 2) {
//             is_pure = 0;
//         } else {
//             int is_div = 0;  // 标记当前数字是否为合数

//             for (int i = 2; i < current_digit; ++i) {
//                 if (current_digit % i == 0) {
//                     is_div = 1;
//                 }
//             }

//             if (!is_div) is_pure = 0;
//         }

//         // 更新
//         input_num /= 10;
//         current_digit = input_num / 10;
//     }

//     // 输出
//     if (is_pure) {
//         printf("%d是纯粹合数", original_num);
//     } else {
//         printf("%d不是纯粹合数", original_num);
//     }
    
//     return 0;
// }



#include<stdio.h>                   // 帮别人改的
int main()
{
    int n = 0;
    scanf_s("%d", &n);
    int k = n;
    int flag = 0;
    if (n == 1 || n == 2)
    {
        flag++;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            n = n / 10;
            i = 2;
            continue;
        }

        if (i == n - 1)
        {
            flag++;
            break;
        }
    }

    if (flag != 0)
        printf("%d不是纯粹合数", k);
    if (flag == 0)
        printf("%d是纯粹合数", k);
}