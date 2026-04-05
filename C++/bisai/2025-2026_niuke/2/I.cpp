#include <iostream>
#include <vector>
using namespace std;

int main () {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n, m;
        vector <char> v;
        cin >> n >> m;
        
        string temp;
        int cnt_0 = 0, cnt_1 = 0;
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            for (int k = 0; k < m; ++k) {
                v.push_back(temp[k]);
                if (temp[k] == '0')
                    ++cnt_0;
                if (temp[k] == '1')
                    ++cnt_1;
            }
        }
        
        for (int j = 0; j < n * m; ++j) {
            if (v[j] == '0') {
                if (cnt_0 > 1)
                    cout << 'Y';
                else
                    cout << 'N';
            } else {
                if (cnt_1 > 1)
                    cout << 'Y';
                else
                    cout << 'N';
            }
            if (j % m == m - 1)
                cout << endl;
        }
    }
    
    return 0;
}