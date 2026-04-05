#include <iostream>
#define endl '\n'
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int max = -100000, min = 100000;
    int n;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        if (min > n)
            min = n;
        if (max < n)
            max = n;
    }

    cout << max - min;
    
    return 0;
}