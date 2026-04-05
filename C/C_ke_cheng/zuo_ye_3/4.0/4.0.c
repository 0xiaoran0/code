// #include <stdio.h>
// #

// int main(void) {
//     int date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
//     int year, month, day;

//     int days = 0;

//     scanf("%d %d %d", &year, &month, &day);
//     if (year%4 == 0 && year%100 != 0 || year%400 == 0) {
//         date[1] = 29;
//     }

//     for (int i = month; i > 1; i--) {
//         days += date[i-2];
//     }

//     days += day;
//     printf("%d\n", days);

//     return 0;
// }



// #include <stdio.h>
// #

// int main(void) {
//     double sum = 0.0;
//     int a = 1;
//     int cnt = 1; 
//     double n = 1.0 / a;
//     while (n > 1e-5 || n < -1e-5) {
//         sum += n;
//         if (a > 0) a += 2;
//         else a -= 2;
//         a = -a;

//         n = 1.0 / a;
//     }
//     printf("%lf", sum*4);
    
//     return 0;
// }



// #include <stdio.h> 
// int main(void)
// {
//     double pi = 1.0;
//     int n = 1;
//     double a = 1.0;
//     int b = 1;
//     for(;n < 100000;)                             //! 循环判断有问题，应该为 n+2
//     {
//         n = n + 2;
//         a = 1.0 / n;
//         b = -b;
//         pi = pi + a*b;
//     }
//     printf("%f", pi*4);
//         return 0;
// }



// #include <stdio.h>

// int main(void) {
//     int n1, n2;
//     scanf("%d %d", &n1, &n2);

//     if (n1 < n2) {
//         int i = n1;
//         n1 = n2;
//         n2 = i;
//     }

//     int x = n1 % n2;
//     int n1_ = n1;
//     int n2_ = n2;
//     if (x != 0) {
//         while (x != 0) {
//             n1_ = n2_;
//             n2_ = x;
//             x = n1_ % n2_;
//             if (x == 0) {
//                 x = n2_;
//                 break;
//             }
//         }
//     } else {
//         x = n2;
//     }

//     n1 = n1 / x;
//     n2 = n2 / x;
//     int y = n1 * n2 * x;
//     printf("%d %d", x, y);
    
//     return 0;
// }



// #include <stdio.h>

// int main(void) {
//     int num;
//     int nums[10];
//     int cnt = 0;
//     while ((scanf("%d", &num)) == 1) {

//         if (num > 10000 || num % 7 != 0) continue;

//         else 
//         {
//             int num_ = num;
//             int n = num_ % 10;
//             while (num_ != 0) {

//                 if (n == 5) {
//                     nums[cnt++] = num;
//                     break;
//                 }

//                 else {
//                     num_ /= 10;
//                     n = num_ % 10;
//                 }
//             }
//         }
//     }

//     if (cnt == 0) printf("0");

//     else {
//         int cnt_ = 0;
//         while (cnt_ < cnt) {
//             printf("%d", nums[cnt_++]);

//             if (cnt_ < cnt) {
//                 printf(" ");
//             }
//         }
//     }
    
//     return 0;
// }



// #include <stdio.h>

// int main(void) {
//     int N;
//     scanf("%d", &N);
//     int cnt = 0;
//     int judge = 0;

//     for (int num_sqrt = 4; num_sqrt * num_sqrt < N; num_sqrt++) {
//         int num = num_sqrt * num_sqrt;
//         for (int b = 1; b*b <= num / 10; b++) {
//             judge = 0;

//             for (int c = 1; b*b*10 + c*c <= num; c++) {
//                 if (b*b*10 + c*c == num) {
//                     judge = 1;
//                     cnt++;
//                     break;
//                 }
//             }
//             if (judge) break;
//             else continue;
//         }

//         if (judge) {
//             if (cnt == 1) printf("%d", num);

//             else printf(" %d", num);
//         }
//     }
    
//     return 0;
// }



// #include <stdio.h>

// int main(void) {
    
//     return 0;
// }