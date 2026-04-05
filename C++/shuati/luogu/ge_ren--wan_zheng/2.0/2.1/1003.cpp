#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int aera[n][4];                               // 也可以用栈实现，大差不差

    for (int i = 0; i < n; ++i) {
        int a, b, g, k;
        cin >> a >> b >> g >> k;

        aera[i][0] = a;
        aera[i][1] = b;
        aera[i][2] = a + g;
        aera[i][3] = b + k;
    }

    int x, y;
    cin >> x >> y;

    int ans = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (x >= aera[i][0] && x <= aera[i][2] \
            && y >= aera[i][1] && y <= aera[i][3]) {
                ans = i + 1;
                break;
            }
    }

    cout << ans << endl;
    
    return 0;
}