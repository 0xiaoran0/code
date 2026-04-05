#include <iostream>
#define endl '\n'
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    
    int a, b;
    for (int i = 0; i < t; ++i) {
        cin >> a >> b;
        cout << a + b << endl;
    }
    
    return 0;
}