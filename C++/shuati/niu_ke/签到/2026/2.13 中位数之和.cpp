#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

const int MOD = 1000000007;
const int MAXN = 2e5 + 10;
long long a[MAXN], ia[MAXN];

long long pow_mod(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

void func1 () {
    a[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        a[i] = a[i-1] * i % MOD;
    }
    ia[MAXN-1] = pow_mod(a[MAXN-1], MOD-2);
    for (int i = MAXN-2; i >= 0; i--) {
        ia[i] = ia[i+1] * (i+1) % MOD;
    }
}

long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return a[n] * ia[k] % MOD * ia[n - k] % MOD;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    func1();

    for (int j = 0; j < t; ++j) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        int cnt_0 = 0, cnt_1 = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) cnt_0++;
            else cnt_1++;
        }
        
        int m = (k + 1) / 2;
        int t0 = max(m, k - cnt_0);
        int t1 = min(cnt_1, k);
        long long ans = 0;
        for (int i = t0; i <= t1; i++) {
            ans = (ans + C(cnt_1, i) * C(cnt_0, k - i) % MOD) % MOD;
        }
        cout << ans << '\n';
    }
    
    return 0;
}