#include <iostream>
#define endl '\n'
typedef long long ll;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    for (int k = 0; k < t; ++k) {
        ll n, q;
        cin >> n >> q;

        ll d = 0, n_ = n;
        while (n_ != 0) {
            n_ /= 2;
            ++d;
        }

        ll x;
        for (ll i = 0; i < q; ++i) {
            cin >> x;
            ll d_ = 0, x_ = x;
            while (x_ != 0) {
                x_ /= 2;
                ++d_;
            }
            ll n1 = 1LL << (d_ - 1);
            ll n2 = n - (1LL << (d_ - 1)) + 1;
            if (d_ != d) {
                cout << n1 << endl;
            } else {
                cout << n2 << endl;
            }
        }
    }
    
    return 0;
}