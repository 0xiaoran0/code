#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, t;
    cin >> l >> t;
    l += 2;
    int a[l];
    for (int i = 0; i < l; ++i) {
        a[i] = 0;
    }

    int m, n;
    for (int i = 0; i < t; ++i) {
        cin >> m >> n;
        a[m] += 1;
        a[n + 1] += -1;
    }

    int cnt = 0, sum = 0;
    for (int i = 0; i < l - 1; ++i) {
        sum += a[i];
        if (sum == 0) {
            ++cnt;
        }
    }
    cout << cnt << endl;
    
    return 0;
}