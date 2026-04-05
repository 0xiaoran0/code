#include <iostream>
using namespace std;

int main () {
    int a, b, c;
    cin >> a >> b >> c;

    double v = (1.0 * a + b + c) / 3;
    if (v >= 60.0)
        cout << "NO";
    else
        cout << "YES";
    
    return 0;
}