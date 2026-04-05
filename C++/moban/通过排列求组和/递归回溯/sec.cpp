#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

void back_track(const vector<ll>& nums, int id, int sel_cnt, int n, int k, int& cnt, vector<ll>& sel_nums) {
    if (sel_cnt == k) {
        for (auto i: sel_nums) {
            cout << i << " ";
        }
        cout << endl;
        ++cnt;
        return;
    }
    if (id >= nums.size() || (nums.size() - id) < (k - sel_cnt)) {
        return;
    }

    sel_nums.push_back(nums[id]);
    back_track(nums, id + 1, sel_cnt + 1, n, k, cnt, sel_nums);
    
    sel_nums.pop_back();
    back_track(nums, id + 1, sel_cnt, n, k, cnt, sel_nums);
}

int comb(vector<ll>& nums, int k, vector<ll>& sel_nums) {
    int n = nums.size();
    if (k > n || k <= 0) {
        for (auto i: nums) {
            cout << i << " ";
        }
        cout << endl;
        return 1;
    }
    
    int cnt = 0;
    back_track(nums, 0, 0, nums.size(), k, cnt, sel_nums);
    return cnt;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    
    vector<ll> sel_nums;
    int ans = comb(nums, k, sel_nums);
    cout << ans << endl;
    
    return 0;
}