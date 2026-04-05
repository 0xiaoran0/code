#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int count_prime_sum(vector<ll>& nums, int k) {
    int n = nums.size();
    if (k > n) {
        for (auto i: nums) {
            cout << i;
        }
        cout << endl;
    } // 边界：k大于数组长度，一个组合
    
    // 1. 生成组合的标记数组：前k个为1（选），后n-k个为0（不选）
    vector<int> mask(n, 0);
    fill(mask.end() - k, mask.end(), 1);
    
    int count = 0;
    do {
        // 2. 遍历标记数组，累加选中的k个数的和
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask[i]) cout << nums[i];
        }
        cout << endl;
        //! next_permutation 在 algorithm 中
    } while (next_permutation(mask.begin(), mask.end())); // 生成下一个组合
    
    return count;
}

int main() {
    // 测试示例：输入数组和k
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int res = count_prime_sum(nums, k);
    
    return 0;
}