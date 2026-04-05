// #include <iostream>
// #include <vector>
// #include <algorithm>
// #define endl '\n'
// using ll = long long;
// using namespace std;

// int main () {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int x, y;
//     cin >> x >> y;

//     double out = 1.0;
//     ll o = 1;
//     for (int i = 0; i < x - 1; ++i) {                           //* 脑抽了用double，数值大时损失精度了
//         out *= (1.0 * (x + y - 2 - i) / (i + 1));
//         o = (ll)(out + 0.5);
//         o %= 1000000007;
//         out = (double)o;
//         o = (ll)(out + 0.3);
//     }
//     cout << o;
    
//     return 0;
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// #define endl '\n'
// using ll = long long;
// using namespace std;

// int main () {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int x, y;
//     cin >> x >> y;
//     ll o = 1;                                               //* 阶乘的结果肯定是整数，但取模破坏原有的整除性
//     for (int i = 0; i < x - 1; ++i) {
//         o *= (x + y - 2 - i) / (i + 1);
//         o %= 1000000007;
//     }
//     cout << o;
    
//     return 0;                                              //* 想用费马小定理 + 快速幂，但分母太大，用不了；
// }                                                          //! 我想到了，把分数拆开取模在相乘就可以了，但我不想写了




#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;

    vector <vector<ll>> v;
    v.resize(x);
    for (int i = 0; i < x; ++i) {
        v[i].resize(y);
    }
    for (int i = 0; i < y; ++i)
        v[0][i] = 1;
    for (int i = 0; i < x; ++i)
        v[i][0] = 1;
    for (int i = 1; i < x; ++i) {
        v[i][0] = 1;
        for (int j = 1; j < y; ++j) {
            v[i][j] = v[i - 1][j] + v[i][j - 1];
            v[i][j] %= 1000000007;
        }
    }
    cout << v[x - 1][y - 1];
    
    return 0;
}