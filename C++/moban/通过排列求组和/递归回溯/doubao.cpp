#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
// 兼容老编译器的写法（C++11前），也可以保留 using ll = long long;
typedef long long ll;
using namespace std;

// 递归回溯核心函数：统计符合条件的组合数
// 参数说明：
// nums: 原始数组
// index: 当前处理到的元素下标
// selected_cnt: 已选中的元素个数
// current_sum: 已选中元素的和
// k: 需要选的元素总数
// count: 符合条件的组合数（引用传递，用于累计结果）
// sel_nums: 存储已选择的数字，用于输出
void backtrack(const vector<ll>& nums, int index, int selected_cnt, int n, int k, int& count, vector<ll>& sel_nums) {
    // 递归终止条件1：选够了k个数，判断和是否为素数
    if (selected_cnt == k) {
        for (auto i: sel_nums) {
            cout << i << " ";
        }
        cout << endl;
        ++count;
        return;
    }
    // 递归终止条件2：处理完所有元素，或剩余元素不够选满k个（剪枝）
    if (index >= nums.size() || (nums.size() - index) < (k - selected_cnt)) {
        return;
    }

    // 分支1：选择当前元素
    sel_nums.push_back(nums[index]);                                        //! 自己想的
    backtrack(nums, index + 1, selected_cnt + 1, n, k, count, sel_nums);
    
    // 分支2：不选择当前元素
    sel_nums.pop_back();
    backtrack(nums, index + 1, selected_cnt, n, k, count, sel_nums);
}

// 对外接口函数：初始化递归参数并调用回溯
int count_prime_combinations(vector<ll>& nums, int k, vector<ll>& sel_nums) {
    int n = nums.size();
    if (k > n || k <= 0) {
        for (auto i: nums) {
            cout << i << " ";
        }
        cout << endl;
        return 1;
    }
    
    int count = 0;
    // 从下标0开始，已选0个，当前和为0，目标选k个
    backtrack(nums, 0, 0, nums.size(), k, count, sel_nums);
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    
    vector<ll> sel_nums;
    int res = count_prime_combinations(nums, k, sel_nums);
    cout << res << endl;
    
    return 0;
}