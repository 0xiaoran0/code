#include <iostream>
#define endl '\n'
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        if (n == 2) {
            cout << "Yes" << endl;
            continue;
        }

        if (n == 1 || n % 2 == 0){
            cout << "No" << endl;
            continue;
        }

        int jd = 0;
        for (int j = 2; j * j <= n; ++j) {
            if (n % j == 0) {
                jd = 1;
            }
        }
        if (jd == 1) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    
    return 0;
}