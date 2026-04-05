#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    ll a, b, c, d;
    for (int i = 0; i < t; ++i) {
        cin >> a >> b >> c >> d;
        ll out = (abs(a - c) + 1LL) * (abs(b - d) + 1LL);                    //* 小心数据溢出
        cout << out << endl;
    }
    
    return 0;
}