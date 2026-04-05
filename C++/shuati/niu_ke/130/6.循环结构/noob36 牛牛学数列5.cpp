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

    int a[3] = {1, 1, 2};
    if (n <= 3) {
        cout << a[n-1];
    } else {
        int i;
        for (i = 0; i < n - 3; ++i) {
            a[i % 3] = a[(i + 1) % 3] + a[(i + 2) % 3];
        }
        cout << a[(i - 1) % 3];                                  //* 需要减一，因为循环结束会加一，还要取余，不然会超
    }
    
    return 0;
}