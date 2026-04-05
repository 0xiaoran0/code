#include <stdio.h>
#include <math.h>
#define calc_s(a, b, c, s) s = ((a) + (b) + (c)) / 2
#define calc_area(a, b, c, s, area) area = sqrt((s)*((s)-(a))*((s)-(b))*((s)-(c)))

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    double s, area;
    calc_s(a, b, c, s);
    calc_area(a, b, c, s, area);
    printf("s=%.2f\narea=%.2f", s, area);
    
    return 0;
}