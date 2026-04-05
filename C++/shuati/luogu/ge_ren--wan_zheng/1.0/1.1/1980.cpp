#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        int j = i;

        while (j != 0) {
            int j_ = j % 10;
            if (j_ == k) cnt++;
            j /= 10;
        }
    }

    cout << cnt << endl;
    
    return 0;
}