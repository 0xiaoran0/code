// #include <stdio.h>

// // 转置函数
// void turn (int* nums, int* nums_turn, int x, int y);

// int main(void) {
//     int x, y;
//     scanf("%d %d", &x, &y);

//     // 一个原矩阵，一个转置后的
//     int nums[x * y];
//     int nums_turn[y * x];

//     turn(nums, nums_turn, x, y);

//     // 转置矩阵与题目要求有差异，所以倒序输出
//     for (int i = y - 1; i >= 0; --i) {
//         for (int j = 0; j < x; ++j) {
//             printf("%d", nums_turn[i * x + j]);
//             if (j < x - 1) printf(" ");
//         }
//         if (i > 0) printf("\n");
//     }
    
//     return 0;
// }

// void turn (int* nums, int* nums_turn, int x, int y) {
//     for (int i = 0; i < x; ++i) {
//         for (int j = 0; j < y; ++j) {
//             scanf("%d", &nums[i * y + j]);
//             nums_turn[j * x + i] = nums[i * y + j];
//         } 
//     }
// }



#include <stdio.h>

// 转置函数
void turn (int* nums, int* nums_turn, int x, int y);

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);

    // 一个原矩阵，一个转置后的
    int nums[x * y];
    int nums_turn[y * x];

    // 这里直接那数组名传入作为指针值
    turn(nums, nums_turn, x, y);

    // 转置矩阵与题目要求有差异，所以倒序输出
    for (int i = y - 1; i >= 0; --i) {
        for (int j = 0; j < x; ++j) {
            printf("%d", nums_turn[i * x + j]);
            if (j < x - 1) printf(" ");
        }
        if (i > 0) printf("\n");
    }
    
    return 0;
}

void turn (int* nums, int* nums_turn, int x, int y) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            scanf("%d", &nums[i * y + j]);
            nums_turn[j * x + i] = nums[i * y + j];
        } 
    }
}