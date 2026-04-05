#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int n1 = (int) sqrt(n);
    if ((n1 - 1) * n1 == n)
        cout << "YES";
    else if ((n1 + 1) * n1 == n)
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}