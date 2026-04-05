// 58



// #include <stdio.h>                              //* 各种数据类型都兼容的交换函数
// #include <stdlib.h>

// void swap (void* a, void* b, int len);

// int main () {
//     int a = 1, b = 2;
//     swap (&a, &b, 4);

//     printf("%d %d\n", a, b);

//     return 0;
// }

// void swap (void* a, void* b, int len) {        //todo 通过 void* 指针加步长实现了数据类型的兼容 (核心是一个字节一个字节的交换)
//     char* p1 = a;
//     char* p2 = b;

//     for (int i = 1; i < len; ++i) {
//         int temp = *p1;
//         *p1 = *p2;
//         *p2 = temp;

//         ++p1;
//         ++p2;
//     }
// }



// #include <stdio.h>
// #include <stdlib.h>

// int main () {                         //! arr 大多数情况下是指第一位的地址，但在使用 sizeof 或 & 时表现为整体
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     printf("%zu\n", sizeof(arr));

//     int* p1 = arr;
//     int (*p) [9] = &arr;

//     printf("%d %d\n", *p1, *p[0]);

//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// int main () {
//     int a1[3] = {1, 2, 3};
//     int a2[4] = {1, 2, 3};
//     int a3[5] = {1, 2, 3};
//     int len[3] = {sizeof(a1) / sizeof(int), sizeof(a2) / sizeof(int), sizeof(a3) / sizeof(int)};
//     int* a[3] = {a1, a2, a3};                            //todo 通过地址实现对不同数组的整合，但是需要单独存储长度

//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < len[i]; ++j) {
//             printf("%d ", *(a[i]++));
//         }
//         printf("\n");
//     }

//     return 0;
// }


// 128
// #include <stdio.h>
// #include <stdlib.h>

// int main () {

//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// int main () {

//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// typedef union {              //! 联合体，公用一块内存，所以同时只能使用其中一个变量，因为连续赋值会覆盖
//     char name[20];           //! 满足内存对齐，总内存要大于最大数据类型的内存且是最大数据类型的内存的整数倍
//     int age;                 //* eg: 这里的内存应为20；不是 double 的整数倍，所以应该是 24
//     double grade;            //* 用法类似结构体
// } stu;

// int main () {
//     stu st;
//     st.age = 10;
//     printf("%d\n", st.age);

//     printf("%zu\n", sizeof(st.age));
//     printf("%zu\n", sizeof(st.grade));
//     printf("%zu\n", sizeof(st.name));
//     printf("%zu\n", sizeof(st));

//     return 0;
// }



// 149
// #include <stdio.h>
// #include <stdlib.h>

// int main () {

//     return 0;
// }



// 157 文件
// #include <stdio.h>                            // 文件的读取
// #include <stdlib.h>

// int main () {
//     char* fi = "test.txt";

//     FILE* file = fopen(fi, "r");           // 指向已打开文件
//     for (int i = 0; i < 23; ++i) {
//         int c = fgetc(file);               // 读取文件
//         printf("%c", c);
//     }
//     printf("\n");

//     file = fopen(fi, "r");
//     char s[20] = {0};
//     for (int i = 0; i < 4; ++i) {
//         fgets(s, 20, file);
//         for (int j = 0; j < 20; ++j) {
//             printf("%d\t", s[j]);            // 读取整行并输出
//         }
//         printf("\n");
//     }

//     file = fopen(fi, "r");
//     for (int i = 0; i < 8; ++i) {
//         int n = fread (s, 1, 3, file);
//         for (int j = 0; j < n; ++j) {
//             printf("%c", s[j]);
//         }
//     }

//     fclose(file);
//     file = NULL;                              // 习惯性置空

//     return 0;
// }



#include <stdio.h>                          // 文件的写入
#include <stdlib.h>

int main () {
    char* fi = "test.txt";
    FILE* file = fopen(fi, "w");           // 指向已打开文件

    char ch;
    scanf("%c", &ch);
    fputc(ch, file);
    fputc('\n', file);
    printf("%c\n", ch);

    char s[100];
    scanf("%s", s);
    fputs(s, file);
    printf("%s\n", s);

    scanf("%s", s);
    int n = fwrite(s, 1, 3, file);
    for (int i = 0 ; i < n; ++i)
        printf("%c", s[i]);
    printf("\n");

    fclose(file);
    file = NULL;                              // 习惯性置空

    return 0;
}