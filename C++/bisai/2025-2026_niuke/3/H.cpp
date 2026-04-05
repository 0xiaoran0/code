#include <iostream>
#define endl '\n'
typedef long double ld;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    if (b == d && abs(a - c) * abs(b) != 4)
        cout << "no answer";
    else if (b == d && abs(a - c) * abs(b) == 4)
        cout << 0;
    else {
        ld k = (ld)(b - d) / (a - c);
        ld x0 = (ld)a - (ld)b / k;
        ld x = 4.0 / (ld)abs(b - d) + x0;
        printf("%.10llf", x);
    }
    
    return 0;
}