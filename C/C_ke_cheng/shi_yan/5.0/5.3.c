// #include <stdio.h>

// int main () {
//     char num_2[129];
//     int num_16[8];
//     int index = 0;
//     scanf("%s", num_2);

//     // 将二进制数据分段求和存入新数组
//     for (int i = 0; i < 8; ++i) {
//         int sum = 0;
//         for (int j = 0; j < 16; ++j) {
//             int current_num = num_2[i * 16 + j] - '0';
//             sum = sum * 2 + current_num;
//         }
//         num_16[index] = sum;
//         ++index;
//     }

//     // 存储当前连续的 0 的个数和最大的连续的 0 的个数
//     // 指针指向连续的 0 的第一位，同理，一个当前，一个最大
//     int cnt = 0;
//     int cnt_ = 0;
//     int index_ = -1;
//     index = -1;
//     int state = 0;

//     for (int i = 0; i < 8; ++i) {
//         // 状态机判断
//         switch (state) {
//             case 0: if (0 == num_16[i]) {
//                         state = 1;
//                         ++cnt_;
//                         index_ = i;
//                     }
//                     break;

//             case 1: if (0 == num_16[i]) {
//                         ++cnt_;
//                     } else {
//                         // 看情况更新最大值
//                         if (cnt_ > 1 && cnt_ > cnt) {
//                             cnt = cnt_;
//                             index = index_;
//                         }
//                         // 更新状态
//                         cnt_ = 0;
//                         index_ = -1;
//                         state = 0;
//                     }
//                     break;
//         }
//     }

//     // 输出
//     for (int i = 0; i < 8; ++i) {

//         if (cnt > 1 && i >= index && i <= index + cnt - 1) {
//             if (i == index + cnt - 1) printf(":");
//             continue;
//         } else {
//             printf("%x", num_16[i]);
//             if (i < 7) printf(":");
//         }
//     }

//     return 0;
// }



// 解决了开头、结尾连续零的情况，以及全部是零的情况
#include <stdio.h>

int main () {
    char num_2[129];
    int num_16[8];
    int index = 0;
    scanf("%s", num_2);

    // 将二进制数据分段求和存入新数组
    for (int i = 0; i < 8; ++i) {
        int sum = 0;
        for (int j = 0; j < 16; ++j) {
            int current_num = num_2[i * 16 + j] - '0';
            sum = sum * 2 + current_num;
        }
        num_16[index] = sum;
        ++index;
    }

    // 存储当前连续的 0 的个数和最大的连续的 0 的个数
    // 指针指向连续的 0 的第一位，同理，一个当前，一个最大
    int cnt = 0;
    int cnt_ = 0;
    int index_ = -1;
    index = -1;
    int state = 0;

    for (int i = 0; i < 8; ++i) {
        // 状态机判断
        switch (state) {
            case 0: if (0 == num_16[i]) {
                        state = 1;
                        ++cnt_;
                        index_ = i;
                    }
                    break;

            case 1: if (0 == num_16[i]) {
                        ++cnt_;
                    } else {
                        // 看情况更新最大值
                        if (cnt_ > 1 && cnt_ > cnt) {
                            cnt = cnt_;
                            index = index_;
                        }
                        // 更新状态
                        cnt_ = 0;
                        index_ = -1;
                        state = 0;
                    }
                    break;
        }
    }
    if (1 == state && cnt_ > 1 && cnt_ > cnt) {
        cnt = cnt_;
        index = index_;
    }

    // 打的补丁
    if (0 == index) printf(":");
    // 输出
    for (int i = 0; i < 8; ++i) {

        if (cnt > 1 && i >= index && i <= index + cnt - 1) {
            if (i == index) printf(":");
            continue;
        } else {
            printf("%x", num_16[i]);
            if (i < 7) printf(":");
        }
    }

    return 0;
}