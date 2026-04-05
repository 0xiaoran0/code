#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[10];
    for (int i = 0; i < 10; ++i)
        a[i] = 0;
    int b[3][3];
    int te;
    int jd = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> te;
            b[i][j] = te;
            if (a[te] == 0) {
                a[te] = 1;
            } else {
                jd = 1;
                break;
            }
        }
    }

    if (jd == 1) {
        cout << "NO";
    } else {
        int s[8];
        for (int i = 0; i < 8; ++i)
            s[i] = 0;
        for (int i = 0; i < 3; ++i) {
            s[7] += b[i][i];
            s[6] += b[i][2-i];
            for (int j = 0; j < 3; ++j) {
                s[i] += b[i][j];
                s[j + 3] += b[j][i];
            }
        }

        for (int i = 0; i < 8; ++i) {
            if (s[i] != 15) {
                jd = 1;
                break;
            }
        }

        if (jd == 1) {
            cout << "NO";
        } else {
            cout << "YES";
        }
    }

    return 0;
}