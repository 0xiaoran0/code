#include <bits/stdc++.h>
using namespace std;

int main () {
    int num;
    cin >> num;

    int cnt, price, min;
    for (int i = 0; i < 3; i++) {
        cin >> cnt >> price;

        int n;
        if (num % cnt) n = num / cnt + 1;
        else n = num / cnt;
        int money = n * price;

        if (i == 0) min = money;
        else min = (min > money ? money : min);
    }
    cout << min << endl;
    
    return 0;
}