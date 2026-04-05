//! 这是田忌赛马一换一的思路
// #include <iostream>
// using namespace std;

// const long long m = 998244353;

// int main () {
//     int t;
//     cin >> t;

//     for (int i = 0; i < t; ++i) {
//         int n;
//         cin >> n;

//         int* state = new int[2 * n];

//         int temp = 0;
//         for (int j = 0; j < n; ++j) {
//             cin >> temp;
//             state[temp-1] = 1;
//         }
//         for (int j = 0; j < n; ++j) {
//             cin >> temp;
//             state[temp-1] = 0;
//         }

//         long long a = 0, b = 1;
//         for (int j = 2 * n - 1; j >= 0; --j) {
//             if (1 == state[j]) {
//                 ++a;
//             } else {
//                 if (a > 0) {
//                     b *= a;
//                     b %= m;
//                     --a;
//                 }
//             }
//         }

//         while (a > 0) {
//             b *= a;
//             b %= m;
//             --a;
//         }

//         cout << b << endl;
//     }
    
//     return 0;
// }



//! 还是田忌赛马的思路
//! 我决定分块处理，用队列存储块，遇到可以赢的牌就从大块中任取，遇到不能赢的牌就从小块中任取(小排的处理有问题，必输的数量是固定的，应该统计最后乘以排列数)
//! 要注意处理块的合并，处理边界条件(块内是否为0，队列是否为空)，还用的状态机写的，很乱，太过麻烦，放弃
// #include <iostream>
// #include <deque>
// #include <algorithm>
// #define endl '\n'
// using ll = long long;
// using namespace std;

// int t[200200];
// const ll MOD = 998244353;

// int main () {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin >> T;

//     while (T--) {
//         int n;
//         cin >> n;

//         deque <ll> a;
//         deque <ll> b;

//         int te;
//         for (int i = 0; i < n; ++i) {
//             cin >> te;
//             t[te - 1] = 1;
//         }
//         for (int i = 0; i < n; ++i) {
//             cin >> te;
//             t[te - 1] = 0;
//         }

//         ll cnt_a = 0;
//         ll cnt_b = 0;

//         int st = 0;
//         for (int i = 2 * n - 1; i >= 0; --i) {
//             switch (st) {
//                 case 0:
//                     if (t[i] == 1) {
//                         ++cnt_a;
//                     } else {
//                         a.push_back(cnt_a);
//                         cnt_a = 0;
//                         st = 1;
//                         ++cnt_b;
//                     }
//                     break;

//                 case 1:
//                     if (t[i] == 0) {
//                         ++cnt_b;
//                     } else {
//                         b.push_back(cnt_b);
//                         cnt_b = 0;
//                         st = 0;
//                         ++cnt_a;
//                     }
//                     break;
//             }
//         }

//         if (cnt_a > 0)
//             a.push_back(cnt_a);
//         if (cnt_b > 0)
//             b.push_back(cnt_b);
            
//         int id_a = a.size() - 1;
//         int id_b = b.size() - 1;

//         ll out = 1;
//         st = 0;
//         int st1 = 0;
//         if (t[0] == 1)
//             st1 = 1;
//         while (a.size() > 0 && b.size() > 0) {
//             switch (st) {
//                 case 0:
//                     if (a[0] > 0) {
//                         out *= a[0];
//                         out %= MOD;
//                         --a[0];

//                         if (b[0] > 0) {
//                             --b[0];
//                         } else {
//                             b.pop_front();
//                             --id_b;
//                             --b[0];
//                             a[1] += a[0];
//                             a.pop_front();
//                             --id_a;
//                         }
//                     } else {
//                         a.pop_front();
//                         --id_a;
//                         st = 1;
//                     }
//                     break;

//                 case 1:
//                     if (b[0] > 0) {
//                         --b[0];

//                         if (a[id_a] > 0) {
//                             out *= a[id_a];
//                             out %= MOD;
//                             --a[id_a];
//                         } else {
//                             a.pop_back();
//                             --id_a;
//                             if (id_a >= 0) { 
//                                 --a[id_a];
//                             } else {
//                                 break;
//                             }

//                             if (st1 == 0) {
//                                 st1 = 1;
//                                 b[id_b - 1] += b[id_b];
//                                 b.pop_back();
//                                 --id_b;
//                             } else if (st1 == 1) {
//                                 st1 = 0;
//                             }
//                         }
//                     } else {
//                         b.pop_front();
//                         st = 0;
//                     }
//             }
//         }

//         cout << out << endl;
//     }
    
//     return 0;
// }



//! 田忌赛马思路
//! 使用 pair对 来定义队列，同时存储最大数和块的大小，比较时更直观地得到谁赢，避免了状态机
// #include <iostream>
// #include <deque>
// #include <vector>
// #include <algorithm>
// #define endl '\n'
// using ll = long long;
// using namespace std;

// #define MOD 998244353

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin >> T;

//     while (T--) {
//         int n;
//         cin >> n;

//         vector<int> t(2 * n, 0);
//         int te;

//         for (int i = 0; i < n; ++i) {
//             cin >> te;
//             t[te - 1] = 1;
//         }
//         for (int i = 0; i < n; ++i) {
//             cin >> te;
//             t[te - 1] = 0;
//         }

//         deque<pair<ll, ll>> a;
//         deque<pair<ll, ll>> b;
//         ll cnt = 0;
//         int st = -1;
//         ll max_n = 0;

//         for (int i = 2 * n - 1; i >= 0; --i) {
//             ll _n = i + 1;
//             int state = t[i];
//             if (st == -1) {
//                 st = state;
//                 cnt = 1;
//                 max_n = _n;
//             } else if (st == state) {
//                 cnt++;
//             } else {
//                 if (st == 1) {
//                     a.push_back({max_n, cnt});
//                 } else {
//                     b.push_back({max_n, cnt});
//                 }
//                 st = state;
//                 cnt = 1;
//                 max_n = _n;
//             }
//         }
//         if (st != -1) {
//             if (st == 1) {
//                 a.push_back({max_n, cnt});
//             } else {
//                 b.push_back({max_n, cnt});
//             }
//         }

//         ll ans = 1;
//         int id_a = 0, id_b = 0;
//         while (!a.empty() && !b.empty() && id_a < a.size() && id_b < b.size()) {
//             auto& a_ = a[id_a];
//             auto& b_ = b[id_b];

//             if (a_.first > b_.first) {
//                 ans = (ans * a_.second) % MOD;
//                 a_.second--;
//                 b_.second--;

//                 if (a_.second == 0) {
//                     id_a++;
//                     if (id_a >= a.size()) break;
//                 }
//                 if (b_.second == 0) {
//                     id_b++;
//                     if (id_b >= b.size()) break;
//                 }
//             } else {
//                 auto& last_a_ = a.back();
//                 ans = (ans * last_a_.second) % MOD;
//                 last_a_.second--;
//                 if (last_a_.second == 0) {
//                     a.pop_back();
//                 }
//                 if (id_b < b.size()) {
//                     b_.second--;
//                     if (b_.second == 0) {
//                         id_b++;
//                         if (id_b >= b.size()) break;
//                     }
//                 }
//             }
//         }

//         cout << ans << endl;
//     }

//     return 0;
// }



//! 终于读懂题了，大数打出，小数留下
//! 大于对方最小数的牌都可以打出，要将这些排放在前面，避免自己的小牌在前让对方的小牌被打出，所以大于对方最小牌的牌在前面排列，其余在后面排列
// #include <iostream>
// #include <deque>
// #include <vector>
// #include <algorithm>
// #define endl '\n'
// using ll = long long;
// using namespace std;

// #define MOD 998244353

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin >> T;

//     while (T--) {
//         int n;
//         cin >> n;

//         vector<int> a;
//         a.reserve(n);
//         int te;

//         for (int i = 0; i < n; ++i) {
//             cin >> te;
//             a.push_back(te);
//         }

//         int min_b = 2 * n;
//         for (int i = 0; i < n; ++i) {
//             cin >> te;
//             if (te < min_b)
//                 min_b = te;
//         }

//         int cnt = 0;
//         for (int i = 0; i < n; ++i) {
//             if (a[i] > min_b)
//                 ++cnt;
//         }

//         ll out = 1;
//         for (int i = 2; i <= cnt; ++i)
//             out = out * i % MOD;
//         for (int i = 2; i <= n - cnt; ++i)
//             out = out * i % MOD;

//         cout << out << endl;
//     }

//     return 0;
// }