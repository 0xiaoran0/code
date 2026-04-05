#include <stdio.h>

int main(void) {
    char ch;
    int judge = 1;
    while ((ch = getchar()) != EOF) {
        if (judge == 1) {
            if (ch == ' ') {
                printf(" ");
                judge = 2;
                continue;
            } else {
                printf("%c", ch);
                continue;
            }
        }

        if (judge == 2) {
            if (ch == ' ') {
                continue;
            } else {
                printf("%c", ch);
                judge = 1;
            }
        }
    }
    
    return 0;
}