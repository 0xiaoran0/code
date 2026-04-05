// #include <stdio.h>

// int main () {
//     int n, k;
//     scanf("%d %d", &n, &k);
//     int u[n];

//     // 偷懒的输入法，直接从第 n-k 位开始输入，并通过取余输入前面的内容，避免了之后的换位
//     for (int i = n - k; i < 2 * n - k; ++i) {
//         scanf("%d", &u[i % n]);
//     }

//     // 顺序输出并判断空格
//     for (int i = 0; i < n; ++i) {
//         printf("%d", u[i]);
//         if (i < n-1) printf(" ");
//     }

//     return 0;
// }



#include <stdio.h>

void swap (int u[], int n, int k) {
    // 偷懒的输入法，直接从第 n-k 位开始输入，并通过取余输入前面的内容，避免了之后的换位
    for (int i = n - k; i < 2 * n - k; ++i) {
        scanf("%d", &u[i % n]);
    }
    return ;
}

int main () {
    int n, k;
    scanf("%d %d", &n, &k);
    int u[n];

    swap(u, n, k);

    // 顺序输出并判断空格
    for (int i = 0; i < n; ++i) {
        printf("%d", u[i]);
        if (i < n-1) printf(" ");
    }

    return 0;
}