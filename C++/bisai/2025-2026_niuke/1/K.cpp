#include <iostream>
using namespace std;

int main () {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        switch (n) {
            case 1: cout << "YES\n1\n"; break;
            case 3: cout << "YES\n1 2 3\n"; break;
            default: cout << "NO\n"; break;
        }
    }
    
    return 0;
}