#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        vector <int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());
        cout << v[0] << v[1] << v[2];

        if (v[0] == v[1] && v[2] - v[1] <= 1 || v[2] == v[1] && v[1] - v[0] <= 1)
            cout << "YES";
        else
            cout << "NO";
    }
    
    return 0;
}