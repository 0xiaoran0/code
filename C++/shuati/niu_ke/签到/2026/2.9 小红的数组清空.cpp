#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector <int> v;
    int te;
    for (int i = 0; i < n; ++i) {
        cin >> te;
        v.push_back(te);
    }

    sort(v.begin(), v.end());
    ll out = 0;
    int last = v[0];
    int cnt = 1;
    int last_cnt = 0;
    int i;
    for (i = 1; i < v.size(); ++i) {
        if (v[i] == last) {
            ++cnt;
        } else if (v[i] == last + 1) {
            if (cnt > last_cnt) {
                out += (cnt - last_cnt);
            }
            last_cnt = cnt;
            cnt = 1;
            ++last;
        } else {
            if (cnt > last_cnt) {
                out += (cnt - last_cnt);
                last_cnt = cnt;
            }
            last = v[i];
            last_cnt = 0;
            cnt = 1;
        }
    }

    if (cnt > last_cnt) {
        out += cnt - last_cnt;
    }

    cout << out;
    
    return 0;
}