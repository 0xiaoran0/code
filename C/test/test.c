// #include <stdio.h>

// int main()
// {
//     int a = 10;
//     double b = 3.0;
//     double c;

//     c = a / b;

//     printf("%f", c);
    
//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     double a = 10.0 / 3;

//     printf("%f", a);
    
//     return 0;
// }



// #include <stdio.h>
// #include <math.h>

// int main()
// {
//     int a = 2, b = 3;
//     double c = pow(a , b);

//     printf("%f", c);
    
//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     int b = 0;

//     if (b == 0) {
//         b = 1;
//     }

//     if (b == 0) {
//         printf("%d", b);
//     } else {
//         printf("%d", b);
//     }
    
//     return 0;
// }



// #include <stdio.h>                                  //测试赋值

// int main()
// {
//     int b = 0;

//     b = 1;

//     printf("%d", b);
    
//     return 0;
// }



// #include <stdio.h>                                                  //测试 for 循环的条件是否会先运行一次   结论：条件只会在内容运行后运行一次

// int main()
// {
//     int i = 10;

//     for (; i > 0; i /= 10) {
//         printf("%d\n", i);
//     }
    
//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     int i = 1;

//     for (i = 1; i < 4; i++) {
//         printf("%d", i);
//         printf("\n");
//     }
    
//     return 0;
// }



// #include <stdio.h>                                                  //测试 if/else 是否起作用

// int main()
// {
//     int i = 10, j, k;

//     for (j = 1; j <= i; j++) {
//         scanf("%d", &k);
//         if (k < 0) {
//             continue;
//         } else {
//             if (k < 10) {
//                 continue;
//             } else {
//                 break;
//             }
//         }
//     }
    
//     return 0;
// }



// #include <stdio.h>                                  //测试字符空格的输入

// int main()
// {
//     char a;

//     scanf_s("%c", &a);

//     printf("%d %c", a, a);
    
//     return 0;
// }



// #include <stdio.h>                                     //测试未知数直接平方，失败

// int main()
// {
//     int a = 1, b;

//     b * b = 2 * a * a;
    
//     return 0;
// }



// #include <stdio.h>                                   //测试 a++， ++a

// int main()
// {
//     int a = 0;
//     printf("%d\n", a++);                               //a++是加之前的值
//     printf("%d\n", ++a);
    
//     return 0;
// }



// #include <stdio.h>

// int main()
// {
//     int a = 10;
//     printf("%f\n", a / 3.0 * 3);
//     printf("%f\n", a / 3 * 3.0);
    
//     return 0;
// }



// #include <stdio.h>                                         //指针与数组的神奇关系

// int main ()
// {
//     int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
//     int *p = &a[4];
//     printf("%d", p[-2]);

//     return 0;
// }



// #include <stdio.h>                               //试用 \b

// int main ()
// {
//     int i;
//     printf("______\b\b\b\b\b\b");
//     scanf_s("%d", &i);                             //输入 123 ，输出 123___

//     return 0;
// }



// #include <stdio.h>
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



// #include <stdio.h>

// int main () {                                                //* 测试输入输出
//     float a = 3.1f;
//     printf("%.1f\n", a);

//     int b[10] = {0};
//     printf("%zu\n", sizeof(b));

//     return 0;
// }



// #include <stdio.h>

// int main () {
//     int a, b, c;
//     while ((scanf("%d,%d,%d", &a, &b, &c)) == 3) {                //* 测试输出格式
//         printf("%d %d %d\n", a, b, c);
//     }
 
//     return 0;
// }



// #include <stdio.h>

// int main () {
//     int a[9] = {[1] = 1, [3] = 1, [1] = 0};         //* 测试数组的特殊初始化--指定初始化器，未初始化的元素为零
//     for (int i = 0; i < 9; ++i) {
//         printf("%d", a[i]);
//     }

//     return 0;
// }



// #include <stdio.h>
// #include <string.h>

// int* test01 () {
//     static int a;
//     scanf("%d", &a);
//     return &a;
// }

// int main () {
//     char s1[2] = {'a'};
//     char s2[2] = {'b'};
//     printf("%d", strcmp(s1, s2));               //* 相同为 0,不同为 -1

//     int* b = test01();
//     printf("%d\n", *b);                          //* 测试静态变量地址

//     int a[3] = {1, 2, 3};
//     int* p = a + 1;                             //! ++a 肯定不行
//     printf("%d\n", *p);

//     int a1 = 1;
//     int b = a1++++;                             //* 果然不行
//     printf("%d", b);

//     return 0;
// }



// #include <stdio.h>

// void fun (int* b) {
//     b = (int*)0xffffffff;
// }

// int main () {
//     int a = 1;
//     int* b = &a;
//     printf("%p\n", b);
//     fun(b);                                    //* 函数传入指针记住什么可以改变，什么不可以
//     printf("%p\n", b);

//     return 0;
// }



// #include <stdio.h>

// int main () {
//     char* s = "test.txt";
//     FILE* fi = fopen(s, "wb");

//     if (fi) {
//         printf("A\n");
//         char s[] = "JUH";
//         int a = 0x3141;
//         int b = 1;
//         int* c = &b;
//         fwrite(s, sizeof(char), 3, fi);
//         fputc('a', fi);
//         fclose(fi);
//     }

//     return 0;
// }



// #include <stdio.h>
// #include <string.h>

// typedef struct A {
//     int a;
//     short b;
//     char c;
// } A;

// typedef union B {
//     char a[9];
//     int b;
// } B;

// int main () {
//     A d;
//     printf("%zu\n", sizeof(d));             //* 验证内存对齐          16

//     B e;
//     printf("%zu\n", sizeof(e));              //*      12

//     return 0;
// }



// #include <stdio.h>
// void test () {
//     printf("AS\n");
// }

// int main () {
//     printf("%d\n", (int)(-1.2));

//     int a[] = {a[2] = 9};                      //* a[2] 中的 a 可以省略
//     printf("%d\n", a[2]);

//     test();                                   //* test = *test
//     (*test)();
//     (**test)();

//     return 0;
// }



// #include <stdio.h>

// int main () {
//     printf("%.3f\n", 1.2f);
//     printf("%.3s\n", "AS");
//     printf("%06.2f\n", 1.2);

//     int s['0'] = {0};

//     return 0;
// }



#include <stdio.h>

int main () {
    int a, b;
    int max;
    scanf("%d%d", &a, &b);
    a > b ? (max = a) : (max = b);
    printf("%d", max);

    return 0;
}