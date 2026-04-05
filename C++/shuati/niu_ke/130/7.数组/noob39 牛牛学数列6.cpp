#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a[4] = {0, 1, 1, 3};
    if (n == 1)
        cout << 0;
    else if (n == 2 || n == 3)
        cout << 1;
    else if (n > 3) {
        int i;
        for (i = 0; i < n - 3; ++i) {
            a[i % 4] = a[(i + 3) % 4] + 2 * a[(i + 2) % 4] + a[(i - 3) % 4];
        }
        cout << a[(i - 1) % 4];
    }
    
    return 0;
}