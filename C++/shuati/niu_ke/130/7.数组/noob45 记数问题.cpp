#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int i_ = i;
        while (i_ > 0) {
            int m = i_ % 10;
            if (m == x) {
                ++cnt;
            }
            i_ /= 10;
        }
    }

    cout << cnt;
    
    return 0;
}

//! 想到一个排列组合的想法，先判断每位数字与 k 的关系，但那样有点麻烦，不想写