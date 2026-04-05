#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    ll te;
    ll sum = 0;
    for (int i = 0; i < n * m; ++i) {
        cin >> te;
        sum += te;
    }

    cout << sum;
    
    return 0;
}