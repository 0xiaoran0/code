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

    ll te;
    int jd = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> te;
            if (i > j && te != 0) {             //* 观察
                jd = 0;
                break;
            }
        }
    }
    if (jd == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}