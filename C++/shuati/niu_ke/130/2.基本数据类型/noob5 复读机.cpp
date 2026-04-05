#include <iomanip>
#include <iostream>
using namespace std;

int main () {
    long long a, b;
    double c;
    char d;
    string e;
    cin >> a >> b >> c >> d >> e;

    cout << a << endl;
    cout << b << endl;
    printf("%.1lf\n", c);
    cout << d << endl;
    cout << e;
    
    return 0;
}