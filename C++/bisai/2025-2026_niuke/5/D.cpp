// #include <iostream>
// #include <list>
// #include <algorithm>
// #define endl '\n'
// using ll = long long;
// using namespace std;

// struct st {
//     int c;
//     int w;

//     st (int c1, int w1): c(c1), w(w1) {};
// };

// bool so (st &s1, st &s2) {
//     return s1.w < s2.w;
// }

// int main () {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin >> t;
//     list <st> l;
//     ll n, m;
    
//     for (int i = 0; i < t; ++i) {
//         cin >> n >> m;
//         st s1(n, m);
//         l.push_back(s1);
//     }
//     l.sort();
    
//     int k = l.size();
//     ll sum = 0;
//     ll mn;
//     while (k > 1) {
//         list <st>::iterator bgn = l.begin();
//         n = *bgn;
//         m = *++bgn;
//         mn = m + n;
//         sum += mn;
//         sum %= 1000000007;
//         l.pop_front();
//         l.pop_front();

//         int jd = 1;
//         for (list <int>::iterator bgn_ = l.begin(); bgn_ != l.end(); ++bgn_) {
//             if (*bgn_ >= mn) {
//                 l.insert(bgn_, mn);
//                 jd = 0;
//                 break;
//             }
//         }
//         if (jd == 1) {
//             l.push_back(mn);
//         }
//         --k;
//     }
    
//     cout << sum;
    
//     return 0;
// }



#include <iostream>
#include <list>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

struct st {
    ll c;
    ll w;

    st (ll c1, ll w1): c(c1), w(w1) {};
};

bool so (st &s1, st &s2) {
    return s1.w < s2.w;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    list <st> l;
    ll n, m;
    
    for (int i = 0; i < t; ++i) {
        cin >> n >> m;
        st s1(n, m);
        l.push_back(s1);
    }
    l.sort(so);
    
    ll sum = 0;
    const ll MOD = 1000000007;
    
    // 只要还有多于1个堆，就继续合并
    while (l.size() > 1) {
        auto it = l.begin();
        ll c1 = it->c;
        ll w1 = it->w;
        
        if (c1 > 1) {
            // 批量合并当前重量的堆
            if (c1 % 2 == 0) {
                // 偶数：全部两两合并
                sum = (sum + c1 * w1) % MOD;
                ll new_c = c1 / 2;
                ll new_w = w1 * 2;
                l.erase(it);
                // 插入新堆
                bool inserted = false;
                for (auto jt = l.begin(); jt != l.end(); ++jt) {
                    if (jt->w == new_w) {
                        jt->c += new_c;
                        inserted = true;
                        break;
                    } else if (jt->w > new_w) {
                        l.insert(jt, st(new_c, new_w));
                        inserted = true;
                        break;
                    }
                }
                if (!inserted) {
                    l.push_back(st(new_c, new_w));
                }
            } else {
                // 奇数：先合并c1-1个（偶数），剩下1个
                sum = (sum + (c1 - 1) * w1) % MOD;
                ll new_c = (c1 - 1) / 2;
                ll new_w = w1 * 2;
                it->c = 1; // 剩下1个当前重量的堆
                // 插入合并后的新堆
                if (new_c > 0) {
                    bool inserted = false;
                    for (auto jt = l.begin(); jt != l.end(); ++jt) {
                        if (jt->w == new_w) {
                            jt->c += new_c;
                            inserted = true;
                            break;
                        } else if (jt->w > new_w) {
                            l.insert(jt, st(new_c, new_w));
                            inserted = true;
                            break;
                        }
                    }
                    if (!inserted) {
                        l.push_back(st(new_c, new_w));
                    }
                }
            }
        } else {
            // 当前堆只有1个，必须和下一个最小堆合并
            auto next_it = next(it);
            ll w2 = next_it->w;
            ll c2 = next_it->c;
            
            // 合并代价
            sum = (sum + w1 + w2) % MOD;
            ll new_w = w1 + w2;
            ll new_c = 1;
            
            // 移除当前1个堆
            l.erase(it);
            // 处理下一个堆：如果c2>1，就减1，否则移除
            if (c2 > 1) {
                next_it->c -= 1;
            } else {
                l.erase(next_it);
            }
            // 插入合并后的新堆
            bool inserted = false;
            for (auto jt = l.begin(); jt != l.end(); ++jt) {
                if (jt->w == new_w) {
                    jt->c += new_c;
                    inserted = true;
                    break;
                } else if (jt->w > new_w) {
                    l.insert(jt, st(new_c, new_w));
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                l.push_back(st(new_c, new_w));
            }
        }
    }
    
    cout << sum % MOD << endl;
    return 0;
}