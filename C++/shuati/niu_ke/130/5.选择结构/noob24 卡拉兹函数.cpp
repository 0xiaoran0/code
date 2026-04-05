#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;

    if (n % 2 == 1)
        cout << 3 * n + 1;
    else
        cout << n / 2;
    
    return 0;
}