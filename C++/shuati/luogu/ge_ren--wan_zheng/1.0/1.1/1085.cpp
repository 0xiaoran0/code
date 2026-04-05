#include <bits/stdc++.h>
using namespace std;

int main () {
    int cnt = 0;
    int sum = 0;

    for (int i = 0; i < 7; i++) {
        int a, b;
        cin >> a >> b;
        int c = a + b;

        if (c > sum && c > 8) {
            cnt = i + 1;
            sum = c;
        }
    }

    cout << cnt << endl;
    
    return 0;
}