#include <iostream>
#include <cmath>
using namespace std;

int main () {
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double d1 = abs(a - c) + abs(b - d);
    double d2 = sqrt((a - c) * (a - c) + (b - d) * (b - d));

    printf("%.20lf", abs(d1 - d2));
    
    return 0;
}