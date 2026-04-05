#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

class t {
    public:
        int x;
        int y;
        ll z;

        t& operator = (const t &t1) {
            x = t1.x;
            y = t1.y;
            z = t1.z;
        }
};

bool sort_ (t &t1, t &t2) {
    return t1.z > t2.z;
}

int main () {                                //* 打算先用 map 存储，排序，更改一次排序一次，然后发现不如更改依次遍历一次，然后发现不如存储最大值，只比较更改的值与存储起来的最大值
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q;
    cin >> n >> m >> q;
    map <pair<int, int>, t*> ma;
    int te;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> te;
            t* t1 = new t;
            *t1 = {i, j, te};
            ma[{i, j}] = t1;
        }
    }
    
    
    
    return 0;
}



//             d[i][j] += te;                   //* 没想到绝对值，准备一点点手打
//             if (i - 1 >= 0)
//                 d[i-1][j] += te;
//             if (i - 2 >= 0)
//                 d[i-2][j] += te;
//             if (i + 1 < n)
//                 d[i+1][j] += te;
//             if (i + 2 < n)
//                 d[i+2][j] += te;



// #include <iostream>
// #include <vector>
// #include <algorithm>
// #define endl '\n'
// typedef long long ll;
// using namespace std;

// int main () {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int n, m, q;
//     cin >> n >> m >> q;
    
//     vector <vector<ll>> d;
//     d.resize(n);
//     for (int i = 0; i < n; ++i)
//         d[i].resize(m);
//     ll te;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             cin >> te;
//             for (int k = -2; k <= 2; ++k) {
//                 if (i + k < 0 || i + k >= n)                     //! 这种判断不能放在 for 循环内部，会导致循环提前终止
//                     continue;
//                 for (int h = -2; h <= 2; ++h) {
//                     if (abs(k) + abs(h) > 2 || j + h < 0 || j + h >= m)
//                         continue;
//                     d[i + k][j + h] += te;
//                 }
//             }
//         }
//     }
    
//     ll max = -1;
//     int id[2] = {-1, -1};
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             if (max < d[i][j]) {
//                 max = d[i][j];
//                 id[0] = i;
//                 id[1] = j;
//             }
//         }
//     }
    
//     int x, y;
//     for (int i = 0; i < q; ++i) {
//         cin >> x >> y >> te;
//         x -= 1, y -= 1;
//         for (int k = -2; k <= 2; ++k) {
//             if (x + k < 0 || x + k >= n)
//                 continue;
//             for (int h = -2; h <= 2; ++h) {
//                 if (abs(k) + abs(h) > 2 || y + h < 0 || y + h >= m)
//                     continue;
//                 d[x + k][y + h] += te;
//                 if (max < d[x + k][y + h]) {
//                     max = d[x + k][y + h];
//                     id[0] = x + k;
//                     id[1] = y + h;
//                 }
//             }
//         }
        
//         cout << id[0] + 1 << " " << id[1] + 1 << endl;
//     }
    
//     return 0;
// }