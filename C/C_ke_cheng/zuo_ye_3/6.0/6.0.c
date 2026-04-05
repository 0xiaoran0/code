#include <stdio.h>
#define swap(x, y) int temp_x = x;\
                    x = y;\
                    y = temp_x;

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    swap(x, y);
    printf("%d %d", x, y);

    return 0;
}