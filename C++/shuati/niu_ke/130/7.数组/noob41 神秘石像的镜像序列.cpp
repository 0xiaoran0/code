#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector <ll> v;
    ll n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        v.push_back(n);
    }
    for (int i = v.size() - 1; i >= 0; --i) {
        cout << v[i] << " ";
    }
    
    return 0;
}