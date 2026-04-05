#include <iostream>
using namespace std;

int main () {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;

        int* num = new int[n+1]();
        for (int j = 0; j < n; ++j)
            cin >> num[j];
        num[n] = k;

        long long max = k + num[0];
        for (int j = 0; j < n+1; ++j) {
            long long max_ = num[j] + num[(j+1)%(n+1)];
            if (max < max_)
                max = max_;
        }

        cout << max << endl;
    }
    
    return 0;
}