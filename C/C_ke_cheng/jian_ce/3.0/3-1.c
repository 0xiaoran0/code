#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);

    if (num == 1 && num == 2) {
        printf("%d不是合数", num);
    } else {
        int judgement = 0;
        for (int i = 2; i < num; ++i) {
            if (num % i == 0) judgement = 1;
        }

        if (judgement) printf("%d是合数", num);
        else printf("%d不是合数", num);
    }
    
    return 0;
}



// #include <stdio.h>

// int main(void) {
    
//     return 0;
// }