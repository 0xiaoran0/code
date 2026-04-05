// #include <stdio.h>

// int main(void) {
//     printf("Hello World!");
    
//     return 0;
// }



// #include <stdio.h>
// #include <math.h>

// int main(void) {                           //* 1.2 "=="打成"="，再加168堪称加168
//     for (int i = 21; i <= 100000; i++) {
//         int x = 0, y = 0;
//         int a = (int)sqrt(i);
//         for (; a*a <= i+268; a++) {
//             if (a * a == i + 100) {
//                 x = 1;
//             }
//             if (a * a == i + 268) {
//                 y = 1;
//             }
//         }
//         if (x && y) {
//             printf("%d\n", i);
//         }
//     }
    
//     return 0;
// }



// #include <stdio.h>

// int main(void) {                             // 2.0
//     char x;
//     int cnt = 0;
//     int line = 0;
//     while (scanf("%c", &x) == 1) {
//         if (x == '\n') {
//             line++;
//         }else if(x == 'z') {            //*按情况设计停止条件
//             break;
//         } else {
//             cnt++;
//         }
//     }
//     printf("%d %d", cnt, line);
    
//     return 0;
// }



// #include <stdio.h>

// int isPerfect (int x) {                    // 3.0
//     int judgement = 0;
//     int sum = 0;
//     int a[x];
//     for (int _ = 1; _ < x; _++) {
//         if (x % _ == 0) {
//             sum += _;
//         }
//     }
//     if (sum == x) judgement = 1;
//     return judgement;
// }

// int main(void) {
//     for (int x = 1; x <= 1000; x++) {
//         int judgement = isPerfect(x);
//         if (judgement) printf("%d\n", x);
//     }
    
//     return 0;
// }



#include <stdio.h>

int main(void) {
    unsigned short a = 0xff00, b = 0xff00;
    unsigned short c = (a>>8 & 0x00ff) ^ (b & 0xff00);
    printf("%x\n", c);
    
    return 0;
}



// #include <stdio.h>

// int main(void) {
    
//     return 0;
// }