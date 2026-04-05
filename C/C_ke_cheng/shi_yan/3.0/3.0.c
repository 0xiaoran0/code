// #include <stdio.h>

// int main(void) {
//     char ch;
//     int judge = 1;
//     while ((ch = getchar()) != EOF) {
//         if (judge == 1) {
//             if (ch == ' ') {
//                 printf(" ");
//                 judge = 2;
//                 continue;
//             } else {
//                 printf("%c", ch);
//                 continue;
//             }
//         }

//         if (judge == 2) {
//             if (ch == ' ') {
//                 continue;
//             } else {
//                 printf("%c", ch);
//                 judge = 1;
//             }
//         }
//     }
    
//     return 0;
// }



#include <stdio.h>

int main(void) {
    char ch;
    int state = 0;
    while ((ch = getchar()) != EOF) {
        switch (state) {
            case 0: if (ch == ' ') {
                        printf(" ");
                        state = 1;
                        continue;
                    } else {
                        printf("%c", ch);
                        continue;
                    }
                    break;

            case 1: if (ch == ' ') {
                        continue;
                    } else {
                        printf("%c", ch);
                        state = 0;
                    }
                    break;
        }
    }
    
    return 0;
}



// #include <stdio.h>
// #

// int fun (int x) {
//     int cnt = 0;
//     while (x != 0) {
//         x /= 10;
//         cnt++;
//     }

//     return cnt;
// }

// int main(void) {
//     int n;
//     scanf("%d", &n);

//     int nums[n+1][n+1];

//     for (int row = 0; row <= n; row++) {
//         int column = row;

//         for (int column = 0; column <= row; column++) {
//             if (column == 0 || column == row) nums[row][column] = 1;
//             else nums[row][column] = nums[row-1][column-1] + nums[row-1][column];
//         }

//         for (int i = 0; i < 3*n-2*row; i++) {
//             printf(" ");
//         }

//         for (int i = 0; i <= column; i++) {
//             printf("%d", nums[row][i]);

//             for (int j = 0; j < (4-fun(nums[row][i])); j++) {
//                 printf(" ");
//             }
//         }

//         printf("\n");
//     }
    
//     return 0;
// }



// #include <stdio.h>
// #

// int main(void) {
//     int n;
//     scanf("%d", &n);

//     int nums[n+1][n+1];

//     for (int row = 0; row <= n; row++) {
//         int column = row;

//         for (int column = 0; column <= row; column++) {
//             if (column == 0 || column == row) nums[row][column] = 1;
//             else nums[row][column] = nums[row-1][column-1] + nums[row-1][column];
//         }

//         for (int i = 0; i < 3*n-2*row; i++) {
//             printf(" ");
//         }

//         for (int i = 0; i <= column; i++) {
//             printf("%-4d", nums[row][i]);                             //! 通过程序化输出对代码进行简化
//         }

//         printf("\n");
//     }
    
//     return 0;
// }



// #include <stdio.h>
// #

// int main(void) {
//     for (int num = 100; num < 1000; num++) {
//         int num_ = num*num;
//         if (num_ % 1000 == num) {
//             printf("%d\n", num);
//         }
//     }
    
//     return 0;
// }



// #include <stdio.h>

// int main(void) {
    
//     return 0;
// }