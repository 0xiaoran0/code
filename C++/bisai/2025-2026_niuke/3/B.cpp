#include <iostream>
#define endl '\n'
typedef long long ll;
using namespace std;

int gcd (ll a, ll b) {
    while (b != 0) {
        a = a % b;
        a ^= b;
        b ^= a;
        a ^= b;
    }

    return a;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n_;
        cin >> n_;

        ll *n = new ll[n_]();
        for (int j = 0; j < n_; ++j) {
            cin >> n[j];
        }

        int jd = 0;
        int j, k;
        for (j = 0; j < n_; ++j) {
            for (k = j+1; k < n_; ++k) {
                jd = gcd(n[j], n[k]);
                if (jd > 1)
                    break;
            }
            if (jd > 1)
                break;
        }

        if (jd > 1) {
            cout << n[j] << " " << n[k] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}