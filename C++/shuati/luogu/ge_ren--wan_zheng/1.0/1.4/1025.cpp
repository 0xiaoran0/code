#include <iostream>
using namespace std;

int divide (int n, int k, int n_);

int main () {
    int n, k;
    cin >> n >> k;

    int cnt = divide (n, k, 1);
    cout << cnt;

    return 0;
}

int divide (int n, int k, int n_) {
    static int cnt = 0;

    if (n < 1 || n < n_)
        return 0;

    if (1 == k) {
        ++cnt;
        return 0;
    }

    for (int i = n_; i < n; ++i)
        divide (n - i, k - 1, i);

    return cnt;
}