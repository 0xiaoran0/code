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
    
    int a[2][n + 1];
    int t = 0;
    for (int i = 0; i < n; ++i) {
        a[0][i] = 1;
        a[1][i] = 1;
        if (i > 0)
            cout << "1 ";
        for (int j = 1; j < i; ++j) {
            a[t][j] = a[(t + 1) % 2][j - 1] + a[(t + 1) % 2][j];             //* 竟然不用改就对了
            cout << a[t][j] << " ";
        }
        t = (t + 1) % 2;
        cout << "1\n";
    }
    
    return 0;
}