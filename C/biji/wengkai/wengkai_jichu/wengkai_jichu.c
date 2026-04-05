// #include <stdio.h>

// int main()
// {
//     printf("Hello World\n") ;

//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     int price = 0;

//     printf("");
//     scanf_s("%d",&price);

//     int change = 100 - price;
//     printf("%d",change);

//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     int a = 0, b = 0, c = 0, d = 0;

//     scanf_s("%d %d", &a, &b);             //*对输入的空格没有限制，不论多少都算作一个
//     scanf_s("eihei%d , %d", &c, &d);       //!需要严格按照引号内的格式，例如输入“eihei1 ,2”才可将1、2赋值给c、d

//     printf("%d %d", a, b);
    
//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     float d = 0.3048 ;
//     int a = 0, b = 0;
//     float c = 0.0;

//     scanf_s("%d %d", &a, &b);

//     c = (a + b / 12.0)* d;

//     printf("%f\n", c);                                           //*输出不需要&
    
//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     int a, b, c, d, e, f;

//     scanf_s("%d %d %d %d", &a, &b, &c, &d);

//     e = b + a * 60;
//     f = d + c * 60;

//     printf("%d", e - f);
    
//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     int a = 10;

//     printf("a++ = %d\n", a++);                                      //*++连打意为变量加一，前置后置得到的a数值相同，但++a和a++不同
//     printf("%d\n", a);

//     printf("++a = %d\n", ++a);                                      //!a++指输出加一前的数值，++a指输出加一后的数值
//     printf("%d\n", a);
    
//     return 0;
// }



// #include <stdio.h>                                                 //厘米转英尺

// int main()
// {
//     int cm, a, b;

//     scanf_s("%d", &cm);

//     float d = cm / 30.48;                                              //整形和浮点数很容易错
//     a = d/1;
//     b = (d - a) * 12;

//     printf("%d %d",a, b);
    
//     return 0;
// }



// #include <stdio.h>                                                  //判断 几点几分 过几分钟后是 几点几分

// int main()
// {
//     int a1, b1, a2, b2, c, f;

//     scanf_s("%d \n %d", &f, &c);

//     a1 = f / 100;                                                    //todo 把一个数分成前后两部分,感觉可以用来解决数值溢出,分开存储在连续输出
//     b1 = f % 100;
//     int d = a1 * 60 +b1;
//     int e = d +c;
//     a2 = e / 60;
//     b2 = e % 60;

//     printf("%d%d",a2, b2);
    
//     return 0;
// }



// #include <stdio.h>                                                    //10进制转16进制，不含abcdef

// int main()
// {
//     int a, b;

//     scanf_s("%d", &a);

//     int c = a / 16;
//     int d = a % 16;
//     b = c * 10 + d;
//     printf("%d\n", b);                                            //!不加\n不会换行，或许可以借此输出一些敏感词,以及上面的溢出数值

//     printf("%x", a);                                              //! 输出16进制数
    
//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     printf("%d\n", 5 == 4);                                                   //*关系运算有两种结果，成立为一，不成立为零
//     printf("%d\n", 5 > 3);
//     printf("%d\n", 5 < 3);
    
//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     //初始化
//     int bill, money;
//     //输入
//     scanf_s("%d %d", &bill, &money);
//     //计算找零
//     int c = bill >= money;
//     if(c == 1){
//         int d = bill - money;
//         printf("%d",d);
//     } else {
//         printf("NO");
//     }
    
//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     //比较两数的大小
//     int a, b;

//     scanf_s("%d %d", &a, &b);

//     int max = 0;                                          // int max = a;
//     if(a > b){                                            // if ( a < b ) { 
//         max = a;                                          //     max = b
//     } else {                                              // }
//         max = b;                                          //! 代码简化了两行，但理解难度上升，理解难度也是评判代码好坏的关键(和之后的在线判断算法很相似)
//     }
    
//     printf("%d", max);

//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     int a, b, c, max;

//     scanf_s("%d %d %d", &a, &b, &c);

//     if (a > b)                                              //*无花括号，简洁
//         if (a > c)
//             max = a;
//         else
//             max = c;
//     else
//         if (b > c) 
//             max = b;
//         else
//             max = c;

//     printf("%d", max);
    
//     return 0;
// }



// #include <stdio.h>                                            //分段函数

// int main()
// {
//     int x, f;

//     scanf_s("%d", &x);

//     if (x > 0)
//         f = x - 1;
//     else if (x = 0)                                            //*和python中的elif相同
//         f = 0;
//     else
//         f = x + 1;

//     printf("%d", f);
    
//     return 0;
// }



// #include <stdio.h>                                         //switch的使用

// int main()
// {
//     int a;

//     scanf_s("%d", &a);

//     int b = a / 10;

//     switch(b){
//     case 10:
//     case 9: printf("A\n"); break;                          //C语言不看缩进，所以写在一行也没有问题
//     case 8: printf("B\n"); break;                          //通过if判断也可以
//     case 7: printf("C\n"); break;
//     case 6: printf("D\n"); break;
//     default: printf("E\n"); break;
//     }
    
//     return 0;
// }



// #include <stdio.h>                                             //判断一个数是几位数

// int main()
// {
//     int a;

//     scanf_s("%d", &a);

//     int b = a / 1000, c = a / 100, d = a / 10, e = a / 1;                        //天才
//     int f = b == 0 + c == 0 + d == 0 + e == 0;                                   //todo 也可以通过if判断范围(人类怎么能想到这种东西)
//     int g = 4 - f;

//     printf("%d", g);
    
//     return 0;
// }



// #include <stdio.h>                         //判断数字是几位数

// int main()
// {
//     int a, b = 1;

//     scanf_s("%d", &a);

//     int i = a / 10;
//     if (i > 0 ) {
//         while (i > 0) {                         //? 这里太啰嗦了，可以直接把 while 写外面，else if 改成 if
//             i = i  / 10;
//             b++;                                                  //比 b += 1 更简洁
//         }
//     } else if (i = 0) {
//         b = 1;
//     }

//     printf("%d", b);
    
//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     int a, b = 0;

//     scanf_s("%d", &a);

//     int i = a / 10;                                           //* 使用 do while 就好了
//     b++;                                                      //解决了当 a = 0 时不成立的问题，（改变：将b的初始设为0，这里加一），也可以else if
//     while (i > 0) {
//         i = i  / 10;
//         b++;                                                  //比 b += 1 更简洁
//     }
    

//     printf("%d", b);
    
//     return 0;
// }



// #include <stdio.h>                                                     //猜数字
// #include <stdlib.h>
// #include <time.h>

// int main()
// {
//     srand(time(0));
//     int a = rand()%10;
//     int b, i;

//     do{
//         scanf_s("%d", &b);
//         if (b > a) {
//             printf ("大了\n");
//         } else if (b < a) {
//             printf ("小了\n");
//         } else {
//             printf("好\n");
//         }
//         i++;
//     } while (b != a);
    
//     printf("%d次", i);

//     return 0;
// }

//!//!//!//!//!//!//!//!//!//!//!//!//!//!//!//!//!//!/!//!//!//!//!//!//!//!//!//!//!//

// #include <stdio.h>                                                          //计算平均数，到 -1 停止

// int main()
// {
//     int a, sum;
//     double i = 0.0;

//     do {                                                                    //不能处理一开始就是 -1 的情况，需要在循环内加一个if判断， while 循环不需要
//         i++;
//         scanf_s("%d", &a);
//         sum += a;
//     } while (a != -1);

//     double a1 = (sum + 1) / (i - 1);
//     printf("%f",a1);
    
//     return 0;
// }



// #include <stdio.h>                                                     //数字倒序
// #include <math.h>

// int main()                                                             //先算出位数，再将输入数字的每一位数依次取出，乘以相应的10的次方后累加      很麻烦
// {
//     int a;

//     scanf_s("%d", &a);

//     int b = a, i = 0, n;

//     do {
//         i++;
//         n = i;
//         b /= 10;
//     } while (b != 0);

//     int c, j = 1, a1;

//     while (j <= n) {
//         int c = a % 10;
//         int d = c * pow(10 , n-j);
//         a1 += d;
//         a /= 10;
//         j++;
//     }

//     printf("%d", a1);
    
//     return 0;
// }



// #include <stdio.h>                                                         //数字倒序

// int main()                                                                 //比上面简单多了，崩溃了         重点处已设断点，这个递推厉害
// {
//     int a, b, c;                                                           //输入 700 想输出 007 可以不断取余，在循环内输出，不换行，实际上是输出了 0 0 7 三个数值，但没有换行

//     scanf_s("%d", &a);

//     while (a != 0) {
//         b = a % 10;
//         c = c * 10 + b;
//         a /= 10;
//     }

//     printf("%d", c);
    
//     return 0;
// }



// #include <stdio.h>                                                 // n 的阶乘 ( 1 )     从 1 (或2) 到 n 累乘

// int main()
// {
//     int n , j = 1, i;                                              //注意初始值，这里必须令 j = 1

//     scanf_s ("%d", &n);

//     for (i = 1; i <= n; i++) {                        // i 的初始值改为 2 可以节省一步计算，同时也可以处理 n = 1 的情况     当不满足循环条件时，不再进入循环，但会再执行一次 i++
//         j *= i;
//     }

//     printf("%d", j);
    
//     return 0;
// }



// #include <stdio.h>                                                  // n 的阶乘 ( 2 )   从 n 到 1 (或2) 累乘

// int main()
// {
//     int j = 1, n;

//     scanf_s("%d", &n);;

//     int i = n;

//     for (i = n; i >= 2; i--) {                                      //依旧取值到 2 ，减小运算量
//         j = j * i;
//     }

//     printf("%d", j);
    
//     return 0;
// }



// #include <stdio.h>                                                    // n 的阶乘 ( 3 )     再简化

// int main()
// {
//     int n, j = 1;                                                     //简化掉 i    j = 1 很关键

//     scanf_s("%d", &n);
    
//     for ( ; n >= 2; n--) {                                            //第一步 n = n 废话，不写
//         j = j * n;
//     }

//     printf("%d", j);

//     return 0;
// }



// #include <stdio.h>                                                      //判断素数，嵌套循环可实现输出 100 以内的素数，也可以输出前五十个素数

// int main()
// {
//     int n, i, a = 1;

//     while (a = 1) {
//         int b = 0;
//         scanf_s("%d", &n);
//         for (i = 2; i < n; i++) {
//             if (n % i == 0) {
//                 b = 1;
//                 break;                                                //节省
//             }
//         }

//         if (b == 1) {                                                 //注意代码的位置，写在错误的花括号内不行       天才 ： 判断条件改为 i = n，也可以运行
//                 printf("NO\n");
//             } else {
//                 printf("OK\n");
//             }
//     }
    
//     return 0;
// }



// #include <stdio.h>                                                             //一角、两角、五角拼十元的情况总数   也可输出任意钱数的组合(修改100)，在最内层循环内用 if 判断

// int main()
// {
//     int i = 1, j = 1, k = 1, count = 0;
//     int m = i + 2*j + 5*k;

//     for (i = 1; m < 100; i++) {
//         for (; m < 100; j++) {
//             for (; m < 100; k++) {
//                 count++;
//                 m = i + 2*j + 5*k;
//                 continue;
//             }
//             k = 1;                                                              //一定要重新赋值，并且一定要放在循环以后
//             continue;
//         }
//         break;
//         j = 1, k = 1;
//     }

//     printf("%d", count);
    
//     return 0;
// }



// #include <stdio.h>                                                              // n 分之一求和

// int main()
// {
//     int i, n;
//     double s = 0.0;                                                             //浮点数初始值也要是浮点数

//     scanf_s("%d", &n);

//     for (i = 1; i <= n; i++) {
//         s += 1.0 / i;                                                           //整形相除不行，于是将 1 换成 1.0
//     }

//     printf("%d", s);
    
//     return 0;
// }



// #include <stdio.h>                                                                // n 分之一求和，奇数项为正，偶数项为负

// int main()
// {
//     int i, n;
//     double m = 1.0, s = 0.0;

//     scanf_s("%d", &n);

//     for (i = 1; i <= n; i++) {
//         s += m / i;                                                               //这两步天才
//         m = -m;
//     }

//     printf("%f", s);
    
//     return 0;
// }



// #include <stdio.h>                                                            //将数字每一位顺序输出，并用空格隔开，最后没有空格：

// int main()                                                                                      // 1. 先逆序，再逆序输出   不能处理末尾为 0 的数，如 700 变成 7
// {
//     int n, i = 0, k = 1;                                                                        // 2. 算出位数，再做除法输出

//     scanf_s("%d", &n);
//     int j = n;

//     do {
//         j /= 10;
//         i += 1;
//     } while (j > 0);

//     for (; i > 1; i--) {                                                                       //减少变量，减少计算
//         k *= 10;
//     }

//     for (; k > 0; k /= 10) {
//         int m = n / k;
//         printf("%d", m);
//         if (k > 9) {                                                                           //选择 k 而不选 n 可以避免 70000 这样的数字出BUG
//             printf(" ");                                                                       //可以使输出内容最后没有空格
//         }
//         n %= k;                                                                                //放在前面输出空格处会出BUG   可以通过调整代码顺序解决问题
//     }
    
//     return 0;
// }



// #include <stdio.h>                                                                               //求最大公约数     (1) 枚举

// int main()
// {
//     int a, b, i, ret;

//     scanf_s("%d %d", &a, &b);

//     int min = a;                                                                          //逻辑运算可省略此步骤
//     if (min > b) {
//         min = b;
//     }

//     for (i = 1; i < min; i++) {
//         if (a % i == 0) {                                                                //逻辑运算可简化
//             if (b % i == 0) {
//                 ret = i;
//             }
//         }
//     }

//     printf("%d", ret);

//     return 0;
// }



// #include <stdio.h>                                                                      //求最大公约数     (2) 辗转相除     我是SB(与下做对比)

// int main()
// {
//     int a, b, c, d, i;

//     scanf_s("%d %d", &a, &b);

//     do {
//         c = b % a;                                                                      //无需在意 a 与 b 的大小
//         if (c == 0) {
//             i = a;
//             break;
//         }
//         d = a % c;
//         if (d == 0) {
//             i = c;
//             break;
//         }
//         c = c % d;
//         if (c == 0) {
//             i = d;
//             break;
//         }
//         d = d % c;
//         if (d == 0) {
//             i = c;
//             break;
//         }
//     } while (c != 0, d != 0);

//     printf("%d", i);
    
//     return 0;
// }



// #include <stdio.h>                                                             //求最大公约数     (2) 辗转相除      天才

// int main()
// {
//     int a, b, i = 1;

//     scanf_s("%d %d", &a, &b);

//     while (b != 0) {                                                           //条件很关键
//         int c = a % b;
//         i = b;
//         a = b;                                                                 //这个处理让循环继续，天才
//         b = c;
//     }

//     printf("%d", i);
    
//     return 0;
// }



// #include <stdio.h>                                              //输入 6 及以下数字，利用其及其之后连续四位数，输出全部三位数共 24 个，从小到大排列，每输出六个要回车，除行尾外有空格

// int main()                                                      //其实个位、十位、百位逐渐增大就是答案，即三个循环嵌套
// {
//     int a, i, j, k;

//     scanf_s("%d", &a);

//     for (i = a; i <= a+3; i++) {
//         int count = 0;
//         for (j = a; j <= a+3; j++) {
//             for (k = a; k <= a+3; k++) {
//                 if (i != j && j != k && i != k) {
//                     printf("%d", i*100 + j*10 + k);
//                     count++;
//                     if (count < 6) {
//                         printf(" ");
//                     }
//                 }
//             }
//         }

//         printf("\n");                                            //也可以写在 if 后，写一个 else
//     }
    
//     return 0;
// }



// #include <stdio.h>                                                   //水仙花数：一个 n 位数每个数字的 n 次幂之和是他本身   要求：输入 n ，到所有 n 位数的水仙花数

// int main()                                                           //不需要想怎么让 n 位数的每一位随机，只需遍历 10 的 n-1 次方到 10 的 n 次方
// {
//     int i, j, n = 1;

//     //输入位数
//     scanf_s("%d", &i);
//     int m = i, a = i, c, s;

//     //得到 10 的 n 次方
//     for (; a > 0; a--) {
//         n *= 10;
//     }
//     int k = n;

//     //遍历 n 位数
//     for (j = n /10; j < k; j++) {
//         int e = j;
//     //取出每一位数
//         for (m = i, n = k, s = 0; m > 0; m--) {
//             int b = e * 10 / n;
//             int d = b;
//     //求每一位数的 n 次方   思路局限了，可以倒着取，不必正着取
//             for (c = i; c > 1; c--) {
//                 b *= d;                                              //这里如果写作 (b *= b) 循环两次实际上是变作四次方，故要设临时变量
//             }
//             s += b;
//             e = e  % (n/10);
//             n /= 10;
//         }
//     //判断题目条件
//         if (j == s) {
//             printf("%d\n", j);
//         } else {
//             continue;
//         }
//     }
    
//     return 0;
// }



// #include <stdio.h>                                             //输出九九乘法表

// int main()
// {
//     int i, j;

//     for (i = 1; i < 10; i++) {
//         for (j = 1; j <= i; j++) {
//             printf("%d * %d = %d", j, i, i*j);
//             if (i != j) {
//                 printf("\t");
//             } else {
//                 printf("\n");
//             }
//         }
//     }
//     return 0;
// }



// #include <stdio.h>                                                     //输出 M 到 N 范围内 (0 < M <= N) 的素数的个数及求和, M N 顺序输入

// int main()
// {
//     int M, N;

//     scanf_s("%d %d", &M, &N);

//     int i, j, b = 1, c = 0, s = 0;

//     for (i = M; i <= N; i++) {
//         b = 1;                                                         //重新赋值很关键
//         for (j = 2; j < i; j++) {
//             int a = i % j;
//             if (a == 0) {                                              //等号和赋值分清
//                 b = 0;
//                 break;                                                 //节省运算
//             }
//         }
//         if (b == 1) {
//             c++;
//             s += i;
//         }
//     }

//     printf("%d %d", c, s);
    
//     return 0;
// }



// #include <stdio.h>                                                       //人输入数字，让计算机去猜   题目理解有误，翁恺的题目应该是自己输入答案自己猜，但都差不多
// #include <stdlib.h>
// #include <time.h>

// int main()
// {
//     //准备
//     srand(time(0));
//     int a, i, N, c, count = 0;

//     scanf_s("%d %d", &a, &N);

//     //准备循环次数
//     for (i = 1; i <= N; i++) {
//         scanf_s("%d", &c);
//         if (c < 0) {
//             printf("Game Over\n");
//             break;
//         }
//         count++;

//     //生成数字并判断情况
//         int b = rand() % 100;
//         printf("%d\n", b);
//         if (b < a) {
//             printf("Too small\n");
//             continue;
//         } else if (b > a) {
//             printf("Too big\n");
//             continue;
//         } else {
//             printf("Bingo\n");
//             if (count <= 3) {
//                 printf("Luck You\n");
//             } else {
//                 printf("Good Guess\n");
//             }
//             break;
//         }
//     }
    
//     return 0;
// }



// #include <stdio.h>                                              //分数求和，首项是 2/1 ，之后的每一项的分子是前一项分子分母之和，分母是前一项的分子,保留两位

// int main()
// {
//     double a = 2.0, b = 1.0;
//     double c, d, s = 0.0;
//     int i;

//     scanf_s("%d", &i);

//     for (; i > 0; i--) {
//         d = a / b;
//         s += d;                                                   //写作 s += a / b 可以少设一个变量
//         c = a + b;
//         b = a;
//         a = c;
//     }

//     printf("%.2f", s);

//     return 0;
// }



// #include <stdio.h>                                                   //念数字，例如输入 -600 ，输出"fu liu ling ling ",如果要末尾没有空格也可以做，但会多一些代码

// int main()
// {
//     //准备
//     int a, i = 0;
//     scanf_s("%d", &a);

//     //处理特殊情况 (a为负数)
//     if (a < 0) {
//         printf("fu ");
//         a = -a;
//     }

//     int b = a;                                                        //临时变量不能设早了

//     //计算位数，分离各位数字
//     do {
//         i++;
//         b /= 10;
//     } while (b > 0);

//     int j, k = 1;

//     for (j = 1; j < i; j++) {
//         k *= 10;
//     }

//     for (; j > 0; j--) {
//         int c = a / k;
//         switch (c) {                                                   //学会使用这个
//             case 0: printf("ling "); break;
//             case 1: printf("yi "); break;
//             case 2: printf("er "); break;
//             case 3: printf("san "); break;
//             case 4: printf("si "); break;
//             case 5: printf("wu "); break;
//             case 6: printf("liu "); break;
//             case 7: printf("qi "); break;
//             case 8: printf("ba "); break;
//             case 9: printf("jiu "); break;
//         }
//         a = a % k;
//         k /= 10;
//     }
    
//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     int a, n, i, b, s = 0, j;
//     scanf_s("%d %d", &a, &n);

//     for (i = 1; i <= n; i++) {
//         b = a;                                                       //要记得定义，而且定义的位置要注意
//         for (j = 2; j <= i; j++) {
//             b = b * 10 + a;
//         }
//         s += b;                                                      //把他移进第二个循环内，就可以删除第一个循环
//     }

//     printf("%d", s);
    
//     return 0;
// }



// #include <stdio.h>                                    //数据类型基础
// #include <math.h>

// int main()
// {
//     double a = 1.0 / 3;
//     printf("%f\n", a);
//     printf("%.10f\n", a);                             //输出小数点后十位

//     double b, c, d;
//     b = 1.23f;                                      //后不加 f / F 则数据类型自动转为 double     不知为何
//     c = 1.23f;
//     d = 2.46f;
//     if (fabs(b + c - d) < 1e8) {                    // (1) fabs() 表示绝对值    (2) 浮点数存储都有误差所以一般不会真正相等，数值在误差范围内就可以
//         printf("相等\n");                             // (3) 1e8 是 1 的 8 次方， 1e-8 是 1 的 -8 次方
//     }

//     char e, f, g;
//     e = 1;
//     f = '1';
//     printf("%d\n%c\n%d\n%c\n", e, e, f, f);
//     scanf_s("%c", &g);
//     printf("%d\n", g);

//     char h, i;
//     scanf_s("%d %c", &h, &i);                                                   //无法输入 i 为空格，需要单独输入或像下面一样不要间距，但下面的输入方式不好用
//     printf("h = %d, i = %d, i = '%c'\n", h, i, i);

//     char j, k;                                                               //讨论有无空格的区别
//     scanf_s("%d%c", &j, &k);                                                 //极其诡异，前面的代码不注释 k 就无法输入，建议输入数值不论如何用空格隔开
//     printf("j = %d, k = %d, k = '%c'\n",j,  k, k);

//     char l = 'A';                                                               //只能用单引号，不能用双引号，甚是诡异
//     l++;
//     printf("%c", l);            //输出 B 

//     char m = 'a', n = 'A';
//     printf("%d\n", n-m);                                                 //计算两字母在 ASCLL表 的距离
//     printf("%c %c\n", m+'A'-'a', m-32);                                           //将字母小写转大写
//     printf("%c %c\n", n+'a'-'A', n+32);                                           //将字母大写转小写

//     return 0;
// }



// #include <stdio.h>                                                        //数据类型强制转换

// int main()
// {
//     int a = 1, b = 3;

//     double i = (double) (a / b);
//     double j = (double) a / b;

//     printf ("%f %f", i, j);
    
//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     int a = 1 , b = 1;
//     if (a > 1 && a++ > 0) {                                    //逻辑运算中 && 若前面的条件不成立，则后面的就不会进行
//         printf("%d", a);
//     }
//     if (b > 0 && b++ > 0) {                                    //b++ 执行了，所以 b 变成了2
//         printf("%d", b);
//     }

//     getchar();
    
//     return 0;
// }



// #include <stdio.h>                 //定义函数

// int sum (int a, int b)
// {
//     int i = a, s = 0;
//     for (; i <= b; i++) {
//         s += i;
//     }
//     // return s;                              //这行代码执行的同时会结束函数，导致后面无法运行
//     printf("%d", s);                          //可以让后面少一次变量的定义、赋值、打印。同时不用写上一行代码
// }

// int main(void)
// {
//     sum (10, 20);
    
//     return 0;
// }



// #include <stdio.h>                             //随机输入 1 ~ 9 的数字，统计各个数字出现多少次，输入 -1 结束

// int main(void)
// {
//     int i, count[10]; 

//     for (int j = 0; j < 10; j++) {
//         count[j] = 0;
//     }

//     scanf_s("%d", &i);
//     while (i != -1) {
//         if (i > 0 && i < 10) {
//             count[i]++;
//         }
//         scanf_s("%d", &i);
//     }

//     for (int k = 0; k < 10; k++) {
//         printf("%d %d次\n", k, count[k]);
//     }

//     getchar();
//     getchar();
    
//     return 0;
// }



// #include <stdio.h>                                     //寻找一个数字在数组中的位置，不知道怎样让黑框停住

// int find (int a, int b[], int c);

// int main(void)
// {
//     int i;
//     int num[10];

//     for (i = 0; i < 10; i++) {
//         num[i] = i*5;
//     }

//     int a;
//     scanf_s("%d", &a);
//     find(a, num, 10);                                 //这里 num 后不加 [] ，好像涉及指针
    
//     return 0;
// }

// int find (int a, int b[], int c) {
//     int d = 0, i = 0;
//     for (; i < c; i++) {
//         if (b[i] == a) {                                //不用 if / else ，else 的语句会多次执行
//             d = 1;
//             break;
//         }
//     }

//     if (d) {
//         printf("%d\n", i);
//     }
// }



// #include <stdio.h>                                        //出问题了，但暂时不知道在哪里，但求素数的方法很好：看一个数是不是素数的倍数，这需要先有一张素数表

// int isPrime (int a, int num[], int b);

// int main(void)
// {
//     int a;
//     while (scanf_s("%d", &a) == 1) {
//         int num[a];                                        //长度不定的数组不能用 {} 定义
//         int b = a;
//         num[0] = 2;                                        //这里的 2 好像没填进去

//         if (isPrime(a, num, b)) {
//             printf("YES\n");
//         } else {
//             printf("NO\n");
//         }
//     }
    
//     return 0;
// }

// int isPrime (int a, int num[], int b) {
//     int c = 1;                                                        //代码到这里的 num 很奇怪，好像涉及指针
//     for (int i = 0, j = 2; i < b, num[i] * num[i] < j; j++) {         //后一个条件可以减少循环
//         if (j % num[i++] == 0) {                                      //条件中的 i++ 的设计使代码少写一行,但这里出现了三次，导致了BUG
//             c = 0;
//         }

//         if (c) {
//             num[i] = j;
//         }
//     }

//     int d = 0;
//     for (int i = 0; i < b; i++) {
//         if (a == num[i]) {
//             d = 1;
//         }
//     }

//     return d;
// }



// #include <stdio.h>                                      //进行修改   成功

// int isPrime (int a, int num[], int b);

// int main(void)
// {   
//     //输入
//     int a;
//     while (scanf_s("%d", &a) == 1) {
//     //定义数组，通过长度为 a 是判断范围不死板
//         int num[a];
//     //填充数组
//         for (int i = 0; i < a; i++) {                                      //达到和 num = [10] = {2} 类似的效果，但可以用于数组长的不定
//             num[i] = 2;
//         }

//     //判断是否是素数
//         if (isPrime(a, num, a)) {
//             printf("YES\n");
//         } else {
//             printf("NO\n");
//         }
//     }
    
//     return 0;
// }

// int isPrime (int a, int num[], int b) {
//     int k = 0;                                                                   //k 放外面计数
//     //第一层循环，用于遍历数字，条件：数组内数字替换完毕，通过记录替换的次数实现，或者说通过记录已经替换到哪个数，看是否超出范围
//     for (int j = 3; k < b; j++) {
//         int c = 1;                                                            //c = 1要定义在里面
//     //第二层循环，通过遍历得到的数字除以数组内的质数判断是否是素数
//         for (int i = 0; i < b && j > num[i]; i++) {                              //这里 i < b 不好，会将数组遍历，但后面都是 2，改为 i < k 可以不进行后面的无效计算
//             if (j % num[i] == 0) {
//                 c = 0;
//             }
//         }

//     //通过上面的结果在数组内进行替换
//         if (c ) {
//             num[k++] = j;
//         }
//     }

//     //判断输入数字是否在数组内
//     int d = 0;
//     for (int i = 0; i < b; i++) {
//         if (a == num[i]) {
//             d = 1;
//         }
//     }

//     return d;
// }



// #include <stdio.h>                                 //输出素数表可以先在数组内填充一定范围内所有整数，则一遍遍将 i 的倍数替换为 0 (i逐渐增大)，最后输出不是 0 的元素

// int main(void)                                     //不想写了，先不写了
// {
    
//     return 0;
// }



// #include <stdio.h>                                            //二维数组的遍历输入

// int main(void)
// {
//     int a[2][3];
//     int i = 0;
//     for (; i < 2; i++) {
//         for (int j = 0; j < 3; j++) {                          //这里必须初始化为 0，不然就有问题
//             scanf_s("%d", &a[i][j]);
//             printf("%d\n", a[i][j]);
//         }
//     }
    
//     return 0;
// }



// #include <stdio.h>                                              //二维数组的初始化

// int main(void)
// {
//     int a[][5] = {                                              //可以不写行数，但不能不写列数
//         {1, 2, 3, 4, 5},
//         {6, 7, 8, 9, 10}
//     };

//     for (int i = 0; i < 2; i++) {
//         for (int j = 0; j < 5; j++) {
//             printf("%d\n", a[i][j]);
//         }
//     }
    
//     return 0;
// }



// #include <stdio.h>

// int main(void)
// {
//     int a  = 0;
//     printf("%zu\n", sizeof(a));                                   // sizeof 的输出使用 %zu
//     printf("%zu\n", sizeof(int));
    
//     int b = 0;
//     int p = (int)&b;                                              //强制转换有问题，不能这么做
//     printf("%p\n", &b);
//     printf("%X\n", p);
//     printf("%zu\n", sizeof(int));
//     printf("%zu\n", sizeof(&b));

//     return 0;
// }



// #include <stdio.h>                    //初试指针，通过指针写函数修改主函数的值

// void f(int* a);

// int main(void)
// {
//     int a = 5;
//     f(&a);
    
//     return 0;
// }

// void f(int* a) {
//     *a += 1;
//     printf("%d", *a);
// }



// #include <stdio.h>                                    //通过指针实现数值的交换

// void exchange(int *a, int *b);

// int main(void)
// {
//     int a = 1, b = 2;
//     exchange(&a, &b);
//     printf("%d,%d\n", a, b);
    
//     return 0;
// }

// void exchange(int *a, int *b) {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }



// #include <stdio.h>

// int main(void)
// {
//     int a = 1, b = 1;
//     const int* p = &a;                                    //int* p是常量，即指针指向定值，不可通过 *p 修改，但可以指向其他变量
//     int* const q = &b;                                    //q 是个定值，及内存位置一定(指向变量一定)，不能指向其他变量，但可修改变量值
//     p = &b;
//     *q = 10;
//     printf("%d\n", *p);
//     printf("%d\n", b);
    
//     return 0;
// }



// #include <stdio.h>                                      //指针的加减运算

// int main(void)
// {
//     int a[] = {1, 2, 3, 4, 5, 6, -1};
//     int* p = a;
//     printf("%d\n", *(p + 1));

//     while (*p != -1) {
//         printf("%d\t", *p++);                            // *p++ 好像会比写一句 p++ 要快，且 p++ 的值是加之前的
//     }
//     printf("\n");
    
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>                                    //内存的动态管理

// int main(void)
// {
//     int n;
//     int i = 0;
//     scanf_s("%d", &n);
//     int* a = (int*) malloc (n * sizeof(int));               //申请可变的空间

//     for (; i < n; i++) {
//         scanf_s("%d", &a[i]);
//     }

//     for (; i > 0; i--) {
//         printf("%d\t", a[n-i]);
//     }
//     printf("\n");

//     free(a);                                               //释放内存
    
//     return 0;
// }



// #include <stdio.h>                                      //测试大概能申请多少内存:50000 MB 左右
// #include <stdlib.h>

// int main(void)
// {
//     int c = 0;
//     void* p = 0;                                        //初始化，好习惯
//     while ( (p = malloc(1024 * 1024))) {
//         c++;
//     }

//     printf("共申请 %dMB 的内存", c);
//     free(p);                                         //一定有借有还
    
//     return 0;
// }



// #include <stdio.h>                                             //不要释放错内存
// #include <stdlib.h>

// int main ()
// {
//     int* a;
//     a = (int*)malloc(2*sizeof(int));
//     for (int i = 0; i < 2; i++) {
//         scanf_s("%d", &a[i]);
//     }

//     for (int i = 0; i < 2; i++) {
//         printf("%d\n", a[i]);
//     }
//     a++;
//     free(a-1);                                                 //如果进行运算，需要还原后再释放内存

//     return 0;
// }



// #include <stdio.h>                                             //初试字符串

// int main(void)
// {
//     char a[] = {"H", "E", "L", "L", "O", 0};
    
    
//     return 0;
// }



// #include <stdio.h>

// int main(void) {                            //* %s 输入字符串会自动添加隐含的 0 ，这一元素可能会被挤到相邻数组第 0 位，导致相邻数组无法输出
//     char a[2] = {0};
//     char b[2] = {0};
//     scanf("%s%s", &a, &b);
//     printf("%s\n%s\n", a, b);

//     printf("%c\n", a[0]);
//     printf("%c\n", a[1]);

//     char* p1 = a;
//     char* p2 = b;
//     printf("%zu\t%zu\n", p1, p2);            //* %zu 用于指针
    
//     return 0;
// }



// #include <stdio.h>

// int main(int argc, char const *argv[]) {                //! 探寻main函数的参数，翁恺建议看 busybox
//     for (int i = 0; i < argc; i++) {
//         printf("%s", argv[i]);
//     }

//     return 0;
// }



// #include <stdio.h>

// int main(void) {
//     char i;
//     while (scanf("%c", &i) != EOF) {
//         printf("%c", i);
//     }
    
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int my_strlen(char *x) {
//     char* i = x;
//     int cnt = 0;
//     while (*i != '\0') {
//         cnt++;
//         *i++;
//     }
//     return cnt;
// }

// char* my_strcpy(char *x, char *y) {
//     char* i = x;
//     while (*i++ = *y++);                 //*只是看起来很厉害，但电脑还是会再初始化两个值，并对那两个值进行操作
//     i = '\0';                            //!保证字符串最后是 '\0'
//     return x;                            //*保证链式表达式能进行下去
// }

// char* my_strcat(char* x, char* y) {
//     char* i = x;
//     i += my_strlen(x);
//     printf("%zu\n", sizeof(x));                      //! 这里的长度是指针的长度 8 ，并不是字符串占用的总内存(并且在函数内不可得到)
//     while (*y) {                                     //! 导致此函数不能解决拷贝时溢出的问题，故 strncat 需要多传入一个参数
//         *i++ = *y++;
//     }
//     i = '\0';
//     return x;
// }

// char* my_strchr(char* x, int c) {                    //! 字符常量是通过整型储存的，所以此处是 int
//     char* i = x;
//     char ch = c;
//     while (*i != c) {
//         i++;
//     }
//     return i;
// }

// char* my_strrchr(char* x, int c);                    //*从右向左查找，不想写了

// int main(void) {
//     char a[] = "Hello";
//     printf("%d\n", my_strlen(a));

//     char *b = (char*)malloc(strlen(a) + 1);
//     my_strcpy(b, a);
//     printf("%s\n", b);

//     char c1[12] = "Hello ";
//     char* c2 = "World";
//     printf("%d\n", sizeof(c1));
//     my_strcat(c1, c2);
//     printf("%s\n", c1);

//     char* d = "Hello";
//     char* p = my_strchr(d, 'l');
//     printf("%s\n", p);
//     p = my_strchr(p+1, 'l');                            //* 用于查找第二个字母，同理可以查询第 n 个，注意 p+1
//     printf("%s\n", p);
    
//     return 0;
// }



// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char a[] = "Hello World";                                   //! char* a 定义的是字符串常量，char a[] 定义的可以修改
//     char* p = strchr(a, 'l');
//     *p = '\0';                                            //todo 实现字符串的截断
//     printf("%s\n", a);
//     *p = 'l';
//     printf("%s\n", a);                                      //* 截断可恢复

//     char *b = strstr(a, "lo");
//     printf("%s\n", b);

//     ;// char *c = strcasestr(a, "Wo");                     //todo 一个特殊函数，可忽略大小写查找，但此处暂时使用不了(可通过先全部转换为小写在查找)
//     ;// printf("%s\n", c);
    
//     return 0;
// }



// #include <stdio.h>                            //枚举变量

// enum color {red, yellow, blue};

// void test (enum color c);                     //? 不好用，而且已经不能检查是否在枚举变量范围内了

// int main(void) {

//     enum color t = red;
//     scanf("%d", &t);
//     test(t);
    
//     return 0;
// }

// void test (enum color c) {
//     printf("%d", c);
// }



// #include <stdio.h>

// struct A {
//     int a;
//     int b;
// };

// int main(void) {
//     struct A a1;
//     a1.a = 1;
//     printf("%d %d\n", a1.a, a1.b);

//     struct A a2 = (struct A){0, 1};               //*小括号内可以不写
//     struct A a3 = a2;
//     printf("%d %d\n", a3.a, a3.b);
    
//     return 0;
// }



// #include <stdio.h>                             //结构体指针

// struct A {
//     int a;
//     int b;
// };

// int main(void) {
//     struct A a1 = {0, 1};
//     struct A* p = &a1;
//     printf("%d %d", p->a, p->b);
    
//     return 0;
// }




// #include <stdio.h>
// #include <stdlib.h>

// struct A {
//     int a;
//     int b;
// };

// void test01 (struct A* x);

// struct A test02 ();

// struct A* test03 (struct A* x);

// int main(void) {
//     struct A a1 = {0, 0};

//     test01 (&a1);                                           //*指针作为参数应传入参数
//     printf("%d %d\n", a1.a, a1.b);

//     a1 = test02();                                          //*一种奇怪的赋值方式
//     printf("%d %d\n", a1.a, a1.b);

//     *test03(&a1) = (struct A) {3, 3};
//     printf("%d %d\n", a1.a, a1.b);                         //todo 通过返回的指针直接修改数值，很新奇的方式，也可链式编程
    
//     return 0;
// }

// void test01 (struct A* x) {
//     *x = (struct A){1, 1};                                //* *x 才是传入的 a1
// }

// struct A test02 () {
//     struct A x = (struct A) {2, 2};
//     return x;
// }

// struct A* test03 (struct A* x) {
//     *x = (struct A){1, 0};
//     return x;
// }



// #include <stdio.h>
// #include <stdlib.h>

// struct B {
//     int b;
//     char c;
// };

// struct A {
//     int a;
//     struct B b1;
// };

// int main(void) {
//     struct A a1;
//     a1 = (struct A){0, 1, 'c'};
//     printf("%c\n", a1.b1.c);

//     struct A a2[] = {0, 0, 'a', 1, 1, 'b'};
//     printf("%d %d %c\n", a2[0].a,  a2[0].b1,  a2[0].b1);
    
//     return 0;
// }



// #include <stdio.h>

// typedef struct {
//     int a;
//     int b;
// } A;                                                    //* 避免了冗杂的说明

// typedef int inte;                                       //! 类型定义后，inte 代替原本 int 的功能

// int main(void) {
//     A a1 = {0, 1};
//     printf("%d %d\n", a1.a, a1.b);
    
//     inte i = 0;
//     printf("%d\n", i);
    
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {                                       //? 一个知识点：联合，不知道有什么用
    
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// int a1 = 0;                                         //* 全局变量如果不进行初始化会有默认的 0 值，只能使用编译时刻已知的数值对全局变量进行初始化

// void test01 (int x);

// void test02 (int* x);

// int main(void) {
//     printf("%s %d\n", __func__, a1);                //todo __func__ 输出当前函数的名字
//     test01(a1);

//     int a2 = 2;
//     test02(&a2);

//     int b1[10] = {0};
//     int b2[10] = {0};
//     printf("%p\n", b1);
//     printf("%p\n", &b1[1]);
//     printf("%p\n", b2);
    
//     return 0;
// }

// void test01 (int x) {
//     printf("%s %d\n", __func__, a1);
// }

// void test02 (int* x) {
//     int a3 = 0;
//     static int a4 = 0;

//     int b1[10] = {0};
//     int b2[10] = {0};

//     printf("%p\n", &a1);
//     printf("%p\n", x);
//     printf("%p\n", &a3);
//     printf("%p\n", &a4);

//     printf("%p\n", b1);
//     printf("%p\n", &b1[1]);
//     printf("%p\n", b2);
// }



// #include <stdio.h>
// #include <stdlib.h>

// int* f(void);
// void g(void);

// int main(void) {
//     int* p = f();                                       //todo 已经无法接收了，会报错
//     printf("%p\n", p);
    
//     g();
    
//     return 0;
// }

// int* f(void) {
//     int i = 0;
//     return &i;
// }

// void g(void) {
//     int k = 0;
//     printf("%p", &k);
// }



// #include <stdio.h>
// #include <stdlib.h>

// #define PI 3.1415926
// #define a PI*PI                           //* 宏定义内可以有其他宏定义，空格会被当作宏定义的一部分，注释不会
// #define PRI printf("%lf\n", PI); \
//             printf("%lf\n", a)              //? 也可以预处理一些语句，可通过 \ 换行，不能写在上面，会报错，不知为何

// #define _DEBUG                              //! 定义一个没有值的宏，可用于之后的条件编译

// int main(void) {
//     printf("%lf\n", PI);                       //! 使用 %d 结果很奇怪；区分 %10、%.10、%10.10
//     printf("%lf\n", a);
//     ;//printf("%s", a);                         //? 类型不匹配

//     PRI;
    
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {
//     printf("%s\n%d\n", __FILE__, __LINE__);
//     printf("%s\n%s\n", __DATE__, __TIME__);
    
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// #define cube(x) (x*x*x)                      //! 宏实现类似函数的效果,一定要记得加括号

// int main(void) {
//     printf("%d\n", cube(6));

//     int i = 6;
//     printf("%d\n", cube(i));

//     int num = 0;
//     printf("%d %n", 12345, &num);                  //? %n 用不了，不知道为什么
//     printf("%d\nnn", num);
    
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {                                    //! scanf() 中有一个 [] 的用法没有学习
    
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {
//     FILE* fp = fopen("test.txt", "r");                  //* 定位文件
//     if (fp) {
//         int num;
//         fscanf( fp, "%d", &num);                        //* 读取文件
//         printf("%d", num);
//         fclose(fp);                                     //* 记得关闭
//     } else {
//         printf("error");
//     }
    
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {                            //! 文件的读写没有学习
    
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {                                    //! 13.2.3 单片机没有学习
    
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {                                    //! 位段，与底层有关，没学明白
    
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int size;
//     int* array; 
// } list;

// list creat (int size) {
//     list a;
//     a.size = size;
//     a.array = (int*) malloc(sizeof(int) * a.size);
//     return a;
// }


// int main(void) {                                    //*实现可变数组，感觉没用，写一半不想写了
    
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _node {
//     int num;
//     struct _node* next;
// } node;

// int main(void) {                                              //* 初始链表
//     node* head = NULL;
//     int num;
//     while ((scanf("%d", &num)) == 1) {
//         if (num == -1) break;
//         node* p = (node*)malloc(sizeof(node));
//         p->num = num;
//         p->next = NULL;
//         node* last = head;
//         if (!last) {
//             head = p;                                           //! 这里必须写 head ，不然 head 永远指向空
//         } else {
//             while (last -> next) {
//                 last = last ->next;
//             }
//             last -> next = p;
//         }
//     }

//     node* last = head; 
//     while (last) {
//         printf("%d\n", last->num);
//         last = last -> next;
//     }
    
//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _node {                                            //! C语言不能把定义放在后面，但可以使用头文件简化
//     int num;
//     struct _node* next;
// } node;

// typedef struct list {
//     node* head;
//     node* tail;
// } list;

// void add (list* li, int num);

// int main(void) {
//     list li;
//     li.head = li.tail = NULL;

//     int num;
//     while ((scanf("%d", &num)) == 1) {
//         add (&li, num);
//     }

//     for (node* p = li.head; p; p = p->next) {
//         printf("%d\n", p -> num);
//     }
    
//     return 0;
// }

// void add (list* li, int num) {
//     node* p = (node*) malloc(sizeof(node));
//     p -> num = num;
//     p -> next = NULL;
//     if (!(li -> head)) {
//         li -> head = p;
//         li -> tail = p;
//     } else {
//         li -> tail -> next = p;
//         li -> tail = p;
//     }
// }



// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {
    
//     return 0;
// }