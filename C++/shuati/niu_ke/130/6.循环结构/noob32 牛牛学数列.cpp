#include <iostream>
#define endl '\n'
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int f = 1;
    int sum = 0;
    for (int i = 1; i < n + 1; ++i) {
        sum += f * i;
        f *= -1;
    }

    cout << sum;
    
    return 0;
}