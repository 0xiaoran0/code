//! 库函数全排列
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #define endl '\n'
// using ll = long long;
// using namespace std;

// ll qpow(ll a, ll n, ll p) 
// {
//     ll ans = 1;
//     while (n) {
//         if (n & 1)
//             ans = ans * a % p;
//         a = a * a % p;
//         n >>= 1;
//     }
//     return ans;
// }

// bool is_prime(ll x) {
//     if (x < 3) 
//         return x == 2;
//     if (x % 2 == 0) 
//         return false;
    
//     ll A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
//     ll d = x - 1, r = 0;
    
//     while (d % 2 == 0) 
//         d /= 2, ++r;

//     for (auto a : A) {
//         if (a >= x)
//             continue;
        
//         ll v = qpow(a, d, x); 
//         if (v <= 1 || v == x - 1) 
//             continue;
        
//         bool flag = false;
//         for (int i = 0; i < r - 1; ++i) {
//             v = v * v % x;
//             if (v == x - 1) {
//                 flag = true;
//                 break;
//             }
//             if (v == 1)  
//                 return false;
//         }
//         if (!flag && v != 1)
//             return false;
//     }
//     return true;
// }

// int my_sum(vector<ll>& nums, int k) {
//     int n = nums.size();
//     if (k > n) return 0;
    
//     vector<int> mask(n, 0);
//     fill(mask.end() - k, mask.end(), 1);
    
//     int cnt = 0;
//     do {
//         ll sum = 0;
//         for (int i = 0; i < n; ++i) {
//             if (mask[i]) sum += nums[i];
//         }
//         if (is_prime(sum)) cnt++;
//     } while (next_permutation(mask.begin(), mask.end()));
    
//     return cnt;
// }

// int main() {
//     int n, k;
//     cin >> n >> k;
//     vector<ll> nums(n);
//     for (int i = 0; i < n; ++i)
//         cin >> nums[i];
    
//     int ans = my_sum(nums, k);
//     cout << ans << endl;
    
//     return 0;
// }



//! 递归回溯
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

ll qpow(ll a, ll n, ll p) 
{
    ll ans = 1;
    while (n) {
        if (n & 1)
            ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}

bool is_prime(ll x) {
    if (x < 3) 
        return x == 2;
    if (x % 2 == 0) 
        return false;
    
    ll A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ll d = x - 1, r = 0;
    
    while (d % 2 == 0) 
        d /= 2, ++r;

    for (auto a : A) {
        if (a >= x)
            continue;
        
        ll v = qpow(a, d, x); 
        if (v <= 1 || v == x - 1) 
            continue;
        
        bool flag = false;
        for (int i = 0; i < r - 1; ++i) {
            v = v * v % x;
            if (v == x - 1) {
                flag = true;
                break;
            }
            if (v == 1)  
                return false;
        }
        if (!flag && v != 1)
            return false;
    }
    return true;
}
void backtrack(const vector<ll>& nums, int id, int cur_cnt, ll cur_sum, int k, int& cnt) {
    if (cur_cnt == k) {
        if (is_prime(cur_sum)) {
            cnt++;
        }
        return;
    }
    if (id >= nums.size() || (nums.size() - id) < (k - cur_cnt)) {
        return;
    }

    //! 也可以写为下面的循环形式
    backtrack(nums, id + 1, cur_cnt + 1, cur_sum + nums[id], k, cnt);
    
    backtrack(nums, id + 1, cur_cnt, cur_sum, k, cnt);

    // for (int i = id; i < nums.size(); ++i)
    //     backtrack(nums, i + 1, cur_cnt + 1, cur_sum + nums[i], k, cnt);
}

int fun(vector<ll>& nums, int k) {
    int n = nums.size();
    if (k > n || k <= 0) return 0;
    
    int cnt = 0;
    backtrack(nums, 0, 0, 0, k, cnt);
    return cnt;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    
    int res = fun(nums, k);
    cout << res << endl;
    
    return 0;
}