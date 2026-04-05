#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n, m;
        cin >> n >> m;
        
        vector <int> a;
        a.reserve(n);
        vector <int> b;
        b.reserve(m);
        int k;
        ll sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; ++j) {
            cin >> k;
            sum1 += k;
            a.push_back(k);
        }
        for (int j = 0; j < m; ++j) {
            cin >> k;
            sum2 += k;
            b.push_back(k);
        }
        
        if (sum1 == sum2) {
            cout << 1 << endl;
            continue;
        }
        
        if (sum1 < sum2) {
            ll tm = sum1;
            sum1 = sum2;
            sum2 = tm;
            a.swap(b);
        }
        
        if (sum1 > sum2) {
            sort(a.begin(), a.end());
            int cnt = 0;
            while (sum1 > sum2) {
                sum1 -= a.back();
                a.pop_back();
                ++cnt;
            }
            cout << cnt << endl;
        }
    }
    
    return 0;
}