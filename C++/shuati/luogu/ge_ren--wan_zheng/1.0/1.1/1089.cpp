#include <bits/stdc++.h>
using namespace std;

int main () {
    int money = 0;
    int repect;
    int sum = 0;
    for (int i = 0; i < 12; i++) {
        money += 300;
        cin >> repect;
        money = money - repect;

        if  (money < 0) {
            cout << '-' << i+1 << endl;
            break;
        }

        int n2 = money / 100;
        sum += n2 * 100;
        money %= 100;

        if (i == 11) {
            cout << sum * 1.2 + money << endl;
        }
    }

    
    return 0;
}