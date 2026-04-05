// #include <iostream>
// #include <vector>
// #include <algorithm>
// #define endl '\n'
// using ll = long long;
// using namespace std;

// int main () {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, k, m;
//     cin >> n >> k >> m;

//     int ln = n + 1;
//     int a[ln];
//     a[n + 1] = n;
//     for (int i = 0; i < n; ++i) {
//         a[i] = 1;
//     }

//     while (a[ln] > 1) {
//         if (a[ln] == n) {
//             for (int i = 0; i < m-1; ++i) {
//             while(a[(++k) % n] == 0);
//             k %= n;
//             }
//         } else {
//             for (int i = 0; i < m; ++i) {
//                 while(a[(++k) % n] == 0);
//                 k %= n;
//             }
//         }
//         a[k] = 0;
//         --a[ln];
//     }
//     for (int i = 0; i < n; ++i) {
//         if (a[i] == 1) {
//             cout << i;
//             break;
//         }
//     }
    
//     return 0;
// }



#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    int ln = n + 1;
    int a[ln];
    a[n + 1] = n;
    for (int i = 0; i < n; ++i) {
        a[i] = 1;
    }

    while (a[ln] > 1) {
        while (a[k] == 0) {                                  //* 先跳过 0，确保初始站在 1 的位置，统一了开始 与 去除人之后 的情况
            k = (k + 1) % n;
        }
            for (int i = 0; i < m - 1; ++i) {
                while(a[(++k) % n] == 0);
                k %= n;
            }
        a[k] = 0;
        --a[ln];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            cout << i;
            break;
        }
    }
    
    return 0;
}