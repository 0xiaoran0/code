#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int count_prime_sum(vector<ll>& nums, int k) {
    int n = nums.size();
    if (k >= n) {
        for (auto i: nums) {
            cout << i << " ";
        }
        cout << endl;
        return 1;
    }
    
    vector<int> mask(n, 0);
    fill(mask.end() - k, mask.end(), 1);
    
    int cnt = 0;
    do {
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask[i]) cout << nums[i] << " ";
            ++cnt;
        }
        cout << endl;
    } while (next_permutation(mask.begin(), mask.end()));
    
    return cnt;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int res = count_prime_sum(nums, k);
    cout << res;
    
    return 0;
}