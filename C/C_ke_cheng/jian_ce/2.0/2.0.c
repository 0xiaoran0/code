#include <stdio.h>

int main () {
    unsigned k, p;
    scanf("%x %x", &k, &p);
    unsigned mask_k = 0x00ff;
    unsigned mask_p = 0xff00;
    k = (k >> 8) & mask_k;
    p = p & mask_p;
    unsigned answer = k | p;
    printf("%x", answer);

    return 0;
}