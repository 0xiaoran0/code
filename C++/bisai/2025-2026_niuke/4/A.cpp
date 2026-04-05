#include <iostream>
#include <deque>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    deque <int> d;
    int te;
    for (int i = 0; i < n; ++i) {
        cin >> te;
        d.push_back(te);
    }
    
    sort(d.begin(), d.end());
    double de = n * 0.8;
    
    int id = (int)de - 1;
    int min = d[id];
    while (d[id] <= min && id < n) {
        ++id;
    }
    id -= 1;
    ll sum = 0;
    if (1.0 * id / (n - 1) >= 0.8) {
        for (int i = d.size() - 1; d[i] >= min && i >= 0; --i) {
            sum += d[i];
        }
    } else {
        for (int i = d.size() - 1; d[i] > min && i >= 0; --i) {
            sum += d[i];
        }
    }
    
    cout << sum;
    
    return 0;
}