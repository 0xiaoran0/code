#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector <int> v;
        v.resize(n);
        ll te;
        ll min = 100000, max = 0, sum = 0;
        for (int j = 0; j < n; ++j) {
            cin >> te;
            v[j] = te;
            sum += te;
            if (min > te)
                min = te;
            if (max < te)
                max = te;
        }

        double n_ = 1.0 * sum / n;
        double x = 0.0;
        for (int j = 0; j < n; ++j) {
            x += ((v[j] - n_) * (v[j] - n_));
        }

        x /= n;
        x = (double)((ll)((x * 1000) + 0.50) * 1.0 / 1000);                   //* 题目没有检测，必须保留三位且不能错，通过第四位四舍五入得到
        cout << max - min << " " ;
        printf("%.3lf\n", x);                                                 //* 不删除上面的同步 或者 强制清楚缓冲区 会错位
    }
    
    return 0;
}