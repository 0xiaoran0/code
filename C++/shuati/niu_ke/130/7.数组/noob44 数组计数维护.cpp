#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;

        int te;
        int s = 0, c = 0;
        for (int j = 0; j < n; ++j) {
            cin >> te;
            if (te >= k) {
                s += te;
            } else if (te == 0 && s >= 1) {
                s -= 1;
                c += 1;
            }
        }

        cout << c << endl;
    }
    
    return 0;
}