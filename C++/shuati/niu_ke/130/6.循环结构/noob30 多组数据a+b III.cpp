#include <iostream>
#define endl '\n'
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    while (!(a == 0 && b == 0)) {
        cout << a + b << endl;
        cin >> a >> b;
    }
    
    return 0;
}