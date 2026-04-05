#include <iostream>
using namespace std;

int main () {
    int a, b;
    cin >> a >> b;
    printf("%.3lf%%", (1.0 * b / a * 100));
    
    return 0;
}