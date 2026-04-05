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
    for (int i = 1; i <= n; ++i) {
        if (i % 4 == 0) {
            continue;
        }
        int n_ = i;
        int jd = 1;
        while (n_ > 0) {                              //* 不要不小心把 n 、i 改了
            if (n_ % 10 == 4) {
                jd = 0;
                break;
            }
            n_ /= 10;
        }

        if (jd == 1)
            cout << i << endl;
    }
    
    return 0;
}