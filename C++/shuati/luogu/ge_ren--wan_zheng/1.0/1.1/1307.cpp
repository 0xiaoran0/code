#include <bits/stdc++.h>
using namespace std;

int main () {
    long n;
    cin >> n;
    long n1 = 0;

    while (n != 0) {
        long i = n % 10;
        n1 = n1 * 10 + i;
        n /= 10;
    }

    cout << n1 << endl;
    
    return 0;
}