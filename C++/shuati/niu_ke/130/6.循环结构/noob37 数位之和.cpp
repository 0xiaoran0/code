#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll m = abs(n);
    int sum = 0;
    while (m > 0) {
        sum += (m % 10);
        m /= 10;
    }
    cout << sum;
    
    return 0;
}