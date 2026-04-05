#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll nd= 4;
    ll sum = 3;
    if (n == 1)
        cout << 0;
    else if (n == 2)
        cout << 1;
    else {
        for (int i = 2; i < n - 1; ++i) {
            sum += nd * 2;
            nd *= 2;
            sum %= 1000000007LL;
            nd %= 1000000007LL;
        }
        sum += nd;
        sum %= 1000000007LL;
        cout << sum;
    }
    
    
    return 0;
}