#include <iostream>
using namespace std;

void fun (int n);
int cnt = 1;
int mo[1000];

int main () {
    int n;
    cin >> n;

    fun (n);
    cout << cnt << endl;
    
    return 0;
}

void fun (int n) {
    if (1 == n) return;

    if (0 != mo[n]) {
        cnt += (mo[n] - 1);
        return;
    }

    for (int i = 1; i <= n / 2; ++i) {
        int cnt_ = cnt;
        ++cnt;
        fun(i);
        if (0 == mo[i]) mo[i] = cnt - cnt_;
    }
}

    // for (int i = 0; i < n+1; ++i) {
    //     cout << mo[i] << " ";
    // }
    // cout << endl;