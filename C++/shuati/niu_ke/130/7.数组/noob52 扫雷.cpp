#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

char a[1010][1010];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    char te;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> te;
            a[i][j] = '0';
            if (te == '*') {
                a[i][j] = '*';
                for (int k = -1; k <= 1; ++k) {
                    if (i + k < 0 || i + k >= n) {
                        continue;
                    }
                    for (int h = -1; h <= 1; ++h) {
                        if (j + h < 0 || j + h >= m || (k == 0 && h == 0) || a[i + k][j + h] == '*') {
                            continue;
                        }
                        ++a[i + k][j + h];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
    
    return 0;
}