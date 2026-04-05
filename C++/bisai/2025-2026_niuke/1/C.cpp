#include <iostream>
using namespace std;

int main () {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        long long* a = new long long[n];;
        long long max = 0;
        for (int j = 0; j < n; ++j){
            cin >> a[j];
            if (a[j] > max) {
                max = a[j];
            }
        }
        
        long long sum = a[0] + a[n-1] + max * (n-2);
        cout << sum << endl;
        delete[] a;
    }
    
    return 0;
}