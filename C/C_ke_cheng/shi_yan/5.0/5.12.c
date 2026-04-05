// #include<stdio.h>
// #define M 10
// #define N 3
// int main(void)
// {
//     int a[M], b[M];
//     int i, j, k;
//     for(i = 0; i < M; i++)
//         a[i] = i + 1;
//     for(i = M, j = 0; i > 1; i--){
//         for(k = 1; k <= N; k++)
//             if(++j > i - 1)
//                 j = 0;
//         b[M-i] = j ? a[j-1] : a[i-1];
//         if(j)
//             for(k = --j; k < i-1; k++)
//                 a[k] = a[k+1];
//     }
//     for(i = 0; i < M-1; i++)
//         printf("%6d", b[i]);
//     printf("%6d\n", a[0]);
//     return 0;
// }


// #include<stdio.h>
// #define M 10
// #define N 3
// int main (void)
// {
//     int a [M];
//     int b[M];
//     int i, j, count, num;
//     // 初始化编号 1-M
//     for (i = 0; i < M; i++)
//         a [i] = i + 1;
//     count = 0;
//     j = -1;
//     num = 0;
//     while (count < M-1){
//         j = (j + 1) % M;
//         if (a [j] == 0)
//             continue;
//         num++;
//         if (num == N){
//             b [count++] = a [j];
//             a [j] = 0;
//             num = 0; 
//         }
//     }
//     // 输出出圈编号
//     for (i = 0; i < M-1; i++)
//         printf ("%6d", b [i]);
//     // 找到最后一人并输出
//     for (i = 0; i < M; i++){
//         if (a [i] != 0){
//             printf ("%6d\n", a [i]);
//             break;
//         }
//     }
//     return 0;
// }

#include<stdio.h>
#define M 10
#define N 3
int main (void)
{
    int a [M];
    int b[M];
    int i, j, count, num;
    // 初始化编号 1-M
    for (i = 0; i < M; i++)
        a [i] = i + 1;
    count = 0;
    j = -1;
    num = 0;
    while (count < M-1){
        j = (j + 1) % M;
        if (a [j] == 0)
            continue;
        num++;
        if (num == N){
            b [count++] = a [j];
            a [j] = 0;
            num = 0; 
        }
    }
    // 输出出圈编号
    for (i = 0; i < M-1; i++)
        printf ("%6d", b [i]);
    // 找到最后一人并输出
    for (i = 0; i < M; i++){
        if (a [i] != 0){
            printf ("%6d\n", a [i]);
            break;
        }
    }
    return 0;
}
