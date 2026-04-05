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
    vector <int> v;
    v.resize(n);
    int te = 0;
    for (int i = 0; i < n; ++i) {
        cin >> te;
        v[i] = te;
        int cnt = 0;
        for (int j = 0; j < i; ++j) {
            if (v[j] < v[i])
                ++cnt;
        }
        cout << cnt << " ";
    }

    return 0;
}