#include <iostream>
#include <deque>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q, s;
    cin >> n >> q >> s;
    deque <ll> d;
    d.push_back(s);
    ll te;
    for (int i = 0; i < n; ++i) {
        cin >> te;
        d.push_back(d[i] + te);
    }
    
    ll m, p;
    for (int i = 0; i < q; ++i) {
        cin >> m >> p;
        te = d[m - 1] + p - 1;
        cout << te << endl;
    }
    
    return 0;
}