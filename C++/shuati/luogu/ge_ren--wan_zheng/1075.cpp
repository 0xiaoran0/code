#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int n;
    cin >> n;

    for (int i = 2; i < sqrt(n) + 1; ++i) {
        if (n % i == 0) {
            printf("%d", n / i);
            break;
        }
    }
    
    return 0;
}