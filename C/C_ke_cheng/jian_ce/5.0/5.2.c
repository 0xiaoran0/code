#include <stdio.h>
#include <stdlib.h>

int main () {
    int n, m;
    scanf("%d %d", &n, &m);

    int men[n];
    for (int i= 0; i < n; ++i)
        men[i] = i + 1;

    int num = n;
    int m_ = m;
    int index = -1;
    while (num != 1) {

        index = (index + 1) % n;
        if (!men[index])
            continue;

        m_ -= 1;

        if (m_ == 0 && men[index]) {
            printf("%d", index + 1);
            if (num > 2)
                printf(" ");
            else
                printf("\n");
            
            men[index] = 0;
            num -= 1;
            m_ = m;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (men[i]) {
            printf("%d", i+1);
            break;
        }
    }

    return 0;
}