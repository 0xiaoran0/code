// #include <stdio.h>

// int main(void) {
//     char ch;
//     while ((ch = getchar()) != EOF) {
//         if (ch >= 'A' && ch <= 'Z') {
//             putchar(ch - 'A' + 'a');
//         } else {
//             putchar(ch);
//         }
//     }
    
//     return 0;
// }



// #include <stdio.h>

// int main(void) {
//     unsigned short num;
//     scanf("%x", &num);

//     int m, n;
//     scanf("%d", &m);
//     scanf("%d", &n);

//     int mask = 1;
//     for (int i = 0; i < n; i++) {
//         mask = mask*2 + 1;
//     }

//     if ( m < 0 || n + m > 16 || n <= 0 || m > 16) {
//         printf("error");
//     } else {
//         num = ((num >> m) & mask) << (16 - n);
//         printf("%x", num);
//     }
    
//     return 0;
// }



// #include <stdio.h>

// int main(void) {
//     unsigned long num;
//     while((scanf("%lu", &num)) != EOF) {
//         for (int i = 0; i < 4; i++) {
//             unsigned int n = (num >> (3-i)*8) & 0x00ff;
//             printf("%u", n);
//             if (i < 3) {
//                 printf(".");
//             }
//         }
//         printf("\n");
//     }

//     return 0;
// }



#include <stdio.h>

int math (unsigned long x, unsigned short mask, int cnt) {
    unsigned int i = x & mask;
    x = x >> 8;
    x = x & 0x00ffffff;
    cnt--;
    if (cnt > 0) {
        math(x, mask, cnt);
    }
    printf("%u", i);
    if (cnt < 3) {
        printf(".");
    }
    return 0;
}

int main(void) {
    unsigned long num;
    unsigned short mask = 0x00ff;
    int cnt = 4;
    while((scanf("%lu", &num)) != EOF) {
        math(num, mask, cnt);
        printf("\n");
    }

    return 0;
}