// #include <stdio.h>

// int main(void) {
//     char ch;
//     scanf("%c", &ch);

//     if (ch >= '0' && ch <= '9') printf("%d", ch - '0');
//     else if (ch >= 'a' && ch <= 'f') printf("%d", ch - 'a' + 10);
//     else if (ch >= 'A' && ch <= 'F') printf("%d", ch - 'A' + 10);
//     else printf("%c", ch);
    
//     return 0;
// }



// #include <stdio.h>

// int main(void) {
//     unsigned short num;
//     scanf("%hu", &num);
//     num = (num >> 12) & 0x000f | (num << 12) & 0xf000 | num & 0x0ff0;
//     printf("%hu", num);
    
//     return 0;
// }



// #include "stdio.h"
// #include<limits.h>

// void bit_print(short x)
// {
//     int i = 0;
//     int n = sizeof(short) * CHAR_BIT; /* CHAR_BIT 在limits.h中定义 */
//     int mask = 1 << (n-1);         /* 逻辑尺mask=100……0 */

//     for ( i=1; i<=n; ++i ) {
//          putchar ( ! ( x & mask ) ? '0': '1');
//          x<<=1;
//          if ( ! ( i % CHAR_BIT ) && i<n )
//              putchar(' ');
//     }
// }
// int main(void)
// {
//     short num;
//     scanf("%d", &num);
//     bit_print(num);
//     return 0;
// }