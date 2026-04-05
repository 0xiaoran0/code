// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     long long p;
//     cin >> n >> p;

//     vector<long long> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }

//     long long mod_sum = 0;
//     set<pair<long long, int>> sorted_mods;
//     sorted_mods.insert({0, 0}); // {mod_value, index}

//     long long max_result = -1;
//     int best_l = 0, best_r = 0;

//     for (int r = 1; r <= n; ++r) {
//         mod_sum = (mod_sum + a[r-1]) % p;
//         if (mod_sum < 0) mod_sum += p;

//         // Case 1: 找最大的小于 mod_sum 的元素
//         auto it_low = sorted_mods.lower_bound({mod_sum, 0});
//         if (it_low != sorted_mods.begin()) {
//             --it_low;
//             long long candidate = mod_sum - it_low->first;
//             if (candidate >= max_result) {
//                 max_result = candidate;
//                 best_l = it_low->second;
//                 best_r = r - 1;
//             }
//         }

//         // Case 2: 找最小的大于 mod_sum 的元素（关键修正：用 upper_bound）
//         auto it_high = sorted_mods.upper_bound({mod_sum, n}); // 用n确保相同值时取索引小的，不影响结果
//         if (it_high != sorted_mods.end()) {
//             long long candidate = (mod_sum - it_high->first + p) % p;
//             if (candidate >= max_result) {
//                 max_result = candidate;
//                 best_l = it_high->second;
//                 best_r = r - 1;
//             }
//         }

//         sorted_mods.insert({mod_sum, r});
//     }

//     cout << best_l << " " << best_r << " " << max_result << endl;

//     return 0;
// }



// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>

// using namespace std;

// int main() {
//     // 关键优化：关闭IO同步，加速输入输出
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     long long p;
//     cin >> n >> p;

//     vector<long long> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }

//     long long mod_sum = 0;
//     set<pair<long long, int>> sorted_mods;
//     sorted_mods.insert({0, 0}); // {mod_value, index}

//     long long max_result = -1;
//     int best_l = 0, best_r = 0;

//     for (int r = 1; r <= n; ++r) {
//         mod_sum = (mod_sum + a[r-1]) % p;
//         if (mod_sum < 0) mod_sum += p;

//         // Case 1: 找最大的小于 mod_sum 的元素
//         auto it_low = sorted_mods.lower_bound({mod_sum, 0});
//         if (it_low != sorted_mods.begin()) {
//             --it_low;
//             long long candidate = mod_sum - it_low->first;
//             if (candidate >= max_result) {
//                 max_result = candidate;
//                 best_l = it_low->second;
//                 best_r = r - 1;
//             }
//         }

//         // Case 2: 找最小的大于 mod_sum 的元素
//         auto it_high = sorted_mods.upper_bound({mod_sum, n});
//         if (it_high != sorted_mods.end()) {
//             long long candidate = (mod_sum - it_high->first + p) % p;
//             if (candidate >= max_result) {
//                 max_result = candidate;
//                 best_l = it_high->second;
//                 best_r = r - 1;
//             }
//         }

//         sorted_mods.insert({mod_sum, r});
//     }

//     cout << best_l << " " << best_r << " " << max_result << endl;

//     return 0;
// }



#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    ll p;
    cin >> n >> p;
    
    vector <ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    ll sum = -1;
    set<pair<ll, int>> m;
    m.insert({0, 0});
    ll out = 0;
    ll l = 0, r = 0;
    
    for (int i = 0; i <= n; ++i) {
        sum = (sum + a[i] + p) % p;
        
        set<pair<ll, int>>::iterator te = m.lower_bound({sum, 0});
        if (te != m.begin()) {
            --te;
            ll temp = (sum - te -> first + p) % p;
            if (temp >= out) {
                out = temp;
                l = te -> second;
                r = i - 1;
            }
        }
        
        te = m.upper_bound({sum, n});
        if (te != m.end()) {
            ll temp = (sum - te -> first + p) % p;
            if (temp >= out) {
                out = temp;
                l = te -> second;
                r = i - 1;
            }
        }
        
        m.insert({sum, r});
    }
    
    cout << l << " " << r << " " << out;
    
    return 0;
}