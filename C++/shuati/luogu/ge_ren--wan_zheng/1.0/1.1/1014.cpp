#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            for (int n1 = i, n2 = 1; n1 > 0; n1--, n2++) {
                cnt++;
                if (cnt == n) {
                    cout << n1 << '/' << n2 << endl;
                    break;
                }
            }
        } else {
            for (int n1 = 1, n2 = i; n2 > 0; n1++, n2--) {
                cnt++;
                if (cnt == n) {
                    cout << n1 << '/' << n2 << endl;
                    break;
                }
            }
        }
        if (cnt == n) break;
    }
    
    return 0;
}