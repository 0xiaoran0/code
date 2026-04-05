#include <stdio.h>

int main(void) {
    char ch;
    int state = 0;
    while ((ch = getchar()) != EOF) {
        switch (state) {
            case 0: if (ch == ' ') {
                        printf(" ");
                        state = 1;
                        continue;
                    } else {
                        printf("%c", ch);
                        continue;
                    }
                    break;

            case 1: if (ch == ' ') {
                        continue;
                    } else {
                        printf("%c", ch);
                        state = 0;
                    }
                    break;
        }
    }
    
    return 0;
}