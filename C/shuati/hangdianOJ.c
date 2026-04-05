//                                                                                                                                        航电OJ 2000
// #include <stdio.h>                                 //冗杂

// int main()
// {
//     char a, b, c;
//     while (scanf(" %c%c%c", &a, &b, &c) == 3) 
//     {
//         if (a < b) {
//             if (b < c) {
//                 printf("%c %c %c\n", a, b, c);
//             } else if (a < c && c < b) {
//                 printf("%c %c %c\n", a, c, b);
//             } else {
//                 printf("%c %c %c\n", c, a, b);
//             }
//         } else {
//             if (c > a) {
//                 printf("%c %c %c\n", b, a, c);
//             } else if (a > c && c > b) {
//                 printf("%c %c %c\n", b, c, a);
//             } else {
//                 printf("%c %c %c\n", c, b, a);
//             }
//         }
//     }
//     return 0;
// }



// deepseek 改版                      下面的排序很好，不知道怎么证明                 
// #include <stdio.h>

// int main() {
//     char a, b, c;
//     while (scanf(" %c%c%c", &a, &b, &c) == 3) {
//         // 排序三个字符
//         if (a > b) { char temp = a; a = b; b = temp; }
//         if (a > c) { char temp = a; a = c; c = temp; }
//         if (b > c) { char temp = b; b = c; c = temp; }
//         printf("%c %c %c\n", a, b, c);
//     }
//     return 0;
// }



//                                                                                                                                         航电OJ 2001
// #include <stdio.h>                             //有问题，d 定义两次；数据不能输入小数；pow 计算平方、平方根效率都不高；
// #include <math.h>

// int main()
// {
//     int x1, x2, y1, y2, d;

//     while (scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2) == 4) {
//         double d1 = pow(x1-x2, 2);
//         double d2 = pow(y1-y2, 2);
//         double d = pow(d1+d2, (double)1/2);                                        // pow 可以，但 sqrt() 是专门计算平方根的 (需要导入 <math.h> ) ，计算会比 pow 要快一点
//         printf("%.2f\n", d);
//     }

//     return 0;
// }



// #include <stdio.h>                                           //deepseek写的
// #include <math.h>

// int main() {
//     double x1, y1, x2, y2;
//     while (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != EOF) {             //deepseek说 ！= EOF不如 ==4
//         double dx = x2 - x1;
//         double dy = y2 - y1;
//         double distance = sqrt(dx * dx + dy * dy);
//         printf("%.2f\n", distance);
//     }
//     return 0;
// }



//                                                                                                                                               航电OJ 2002
// #include <stdio.h>

// int main()
// {
//     double PI = 3.1415927;
//     double r;

//     while (scanf_s("%lf", &r) == 1) {
//         double V = 4 * PI * r * r * r / 3;
//         printf("%.3f\n", V);
//     }

//     return 0;
// }



//                                                                                                                                              航电OJ 2003
// #include <stdio.h>

// int main()
// {
//     double a ;
//     while (scanf_s("%lf", &a) == 1) {
//         if (a < 0) {
//             a = -a;
//         }

//         printf("%.2f\n", a);
//     }

//     return 0;
// }



//                                                                                                                                          航电OJ 2004
// #include <stdio.h>                                 //没过    错因：忘记考虑负数，考虑不全面

// int main()
// {
//     int a;
//     while (scanf("%d", &a) == 1) {
//         int b = a / 10;

//         switch (b) {
//             case 10:
//             case 9: printf("A\n"); break;
//             case 8: printf("B\n"); break;
//             case 7: printf("C\n"); break;
//             case 6: printf("D\n"); break;
//             case 5:
//             case 4:
//             case 3:
//             case 2:
//             case 1:
//             case 0: printf("E\n"); break;
//             default: printf("Score is error!\n"); break;        /*可以先判断数字是否大于 100 ，可以简化代码，避免 0 ~ 5 的枚举*/
//         }
//     }

//     return 0;
// }



// #include <stdio.h>                                  //简单修改，加入了负数的情况，过了

// int main()
// {
//     int a;
//     while (scanf("%d", &a) == 1) {
//         if (a < 0 ) {
//             printf("Score is error!\n");
//         } else {
//             int b = a / 10;

//             switch (b) {
//                 case 10:
//                 case 9: printf("A\n"); break;
//                 case 8: printf("B\n"); break;
//                 case 7: printf("C\n"); break;
//                 case 6: printf("D\n"); break;
//                 case 5:
//                 case 4:
//                 case 3:
//                 case 2:
//                 case 1:
//                 case 0: printf("E\n"); break;
//                 default: printf("Score is error!\n"); break;
//             }
//         }
//     }

//     return 0;
// }


//                                                                                                                      航电OJ 2005
// #include <stdio.h>

// int main()
// {
//     int a, b, c;
//     while (scanf_s("%d/%d/%d", &a, &b, &c) == 3) {
//         int d = c;
//         int i = 0;
//         if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0) {
//             i = 1;
//         }

//         switch (b) {
//             case 12: d += 30;
//             case 11: d += 31;
//             case 10: d += 30;
//             case 9: d += 31;
//             case 8: d += 31;
//             case 7: d += 30;
//             case 6: d += 31;
//             case 5: d += 30;
//             case 4: d += 31;
//             case 3: 
//                 if (i) {
//                     d += 29;
//                 } else {
//                     d += 28;
//                 }
//             case 2: d += 31; break;
//         }

//         printf("%d\n", d);
//     }

//     return 0;
// }



// #include <stdio.h>                                  //可以通过数组解决，我不想写了

// int main()
// {

//     return 0;
// }



//                                                                                                                       航电OJ 2006
// #include <stdio.h>                                 //Output Limit Exceeded

// int main()
// {
//     while (1) {
//         int count;
//         scanf_s("%d", &count);

//         int b = 1;
//         for (int i = 0; i < count; i++) {
//             int a;
//             scanf_s("%d", &a);
//             if (a % 2 == 1) {
//                 b *= a;
//             }
//         }
//         printf("%d\n", b);
//     }

//     return 0;
// }



// #include <stdio.h>

// int main()
// {

//     int count;
//     while (scanf_s("%d", &count) == 1) {                            //改进了循环条件，不使用死循环
//         int b = 1;
//         for (int i = 0; i < count; i++) {
//             int a;
//             scanf_s("%d", &a);
//             if (a % 2 == 1) {
//                 b *= a;
//             }
//         }
//         printf("%d\n", b);
//     }

//     return 0;
// }



//                                                                                                                       航电OJ 2006
// #include <stdio.h>                                                      //未考虑 a 、b 的大小关系

// int main()
// {
//     int a, b;
//     while (scanf_s("%d %d", &a, &b) == 2) {
//         int m = 0, n = 0;

//         for (int i = a; i <= b; i++) {
//             if (i % 2 == 0) {
//                 int x = i;
//                 x = x * x;
//                 m += x;
//             } else {
//                 int x = i;
//                 x = x * x * x;
//                 n += x;
//             }
//         }

//         printf("%d %d\n", m, n);
//     }

//     return 0;
// }



#include <stdio.h>

int main()
{
    int a, b;
    while (scanf_s("%d %d", &a, &b) == 2) {
        if (a > b) {                                                  //加入了对 a > b 的处理
            int i = a;
            a = b;
            b = i;
        }
        int m = 0, n = 0;

        for (int i = a; i <= b; i++) {
            if (i % 2 == 0) {
                int x = i;
                x = x * x;
                m += x;
            } else {
                int x = i;
                x = x * x * x;
                n += x;
            }
        }

        printf("%d %d\n", m, n);
    }

    return 0;
}




// #include <stdio.h>

// int main()
// {

//     return 0;
// }