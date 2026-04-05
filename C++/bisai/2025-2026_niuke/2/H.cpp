#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main () {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector <int> v;
        map <int, int> m;
        v.reserve(n);
        int temp;
        
        for (int j = 0; j < n; ++j) {
            scanf("%d", &temp);
            v.push_back(temp);
        }
        
        long long sum = 0;
        for (int j = 0; j < n; ++j) {
            int ind;
            if (m.count(v[j]) != 0)
                ind = m[v[j]];
            else
                ind = -1;
            long long a = j - ind;
            long long b = n - j;
            long long con = a * b * (b + 1) / 2;
            sum += con;
            m[v[j]] = j;
        }
        
        cout << sum << endl;
    }
    
    return 0;
}