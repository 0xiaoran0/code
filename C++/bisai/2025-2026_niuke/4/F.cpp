#include <iostream>
#include <deque>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;
 
void ans (ll a, ll b, char c1, char c2) {
    int t1 = a / (b + 1);
    int t2 = a % (b + 1);
 
    for (int j = 0; j < t2; ++j) {
        for (int k = 0; k < t1 + 1; ++k) cout << c1;
        cout << c2;
    }
    for (int j = 0; j < b - t2; ++j) {
        for (int k = 0; k < t1; ++k) cout << c1;
        cout << c2;
    }
    for (int k = 0; k < t1; ++k) cout << c1;
}
 
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     
    int t;
    cin >> t;
     
    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;
         
        char c1, c2;
        if (a > b) {
            ans(a, b, '0', '1');
        } else {
            ans(b, a, '1', '0');
        }
        cout << endl;
    }
     
     
    return 0;
}