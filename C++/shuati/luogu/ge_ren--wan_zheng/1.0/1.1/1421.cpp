#include <bits/stdc++.h>
using namespace std;

int main () {
    int a, b;
    cin >> a >> b;

    int price = 19;
    int money = a*10 + b;

    int cnt = money / price;
    cout << cnt << endl;
    
    return 0;
}