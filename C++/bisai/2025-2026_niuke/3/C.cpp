// #include <iostream>
// #include <deque>
// #include <algorithm>
// #define endl '\n'
// typedef long long ll;
// using namespace std;

// int main () {                                               //! 史，这就是史
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin >> t;
    
//     for (int i = 0; i < t; ++i) {
//         int n;
//         cin >> n;
//         char* s = new char[n + 10]();
//         char* s_ = new char[n + 10]();
//         scanf("%s", s);
//         for (int j = 0; j < n; ++j) {
//             s_[j] = s[j];
//         }
        
//         char s1, s2;
//         if (s[0] == '0') s1 = '1', s2 = '0';
//         if (s[0] == '1') s1 = '0', s2 = '1';
        
//         int id = 1, jd = 0, cnt1 = 1;
//         char last = 0;
//         deque <int> id_;
//         int judge = 1;
//         while (judge) {
//             if (id % 2 == 1 && s[id] != s1) {
//                 if (jd == 0) {
//                     jd = 1;
//                     last = s[id];
//                     s[id] = s1;
//                 } else {
//                     if (s[id] != last) {
//                         last = s[id];
//                         s[id] = s1;
//                     } else {
//                         id_.push_back(id);
//                     }
//                 }
//             }
            
//             else if (id % 2 == 0 && s[id] != s2) {
//                 if (jd == 0) {
//                     jd = 1;
//                     last = s[id];
//                     s[id] = s2;
//                 } else {
//                     if (s[id] != last) {
//                         last = s[id];
//                         s[id] = s2;
//                     } else {
//                         id_.push_back(id);
//                     }
//                 }
//             }
//             ++id;
//             if (id >= n) {
//                 while (!id_.empty()) {
//                     if (id_[0] % 2 == 1 && s[id_[0]] == s1) {
//                         id_.pop_front();
//                     } else if (id_[0] % 2 == 0 && s[id_[0]] == s2) {
//                         id_.pop_front();
//                     } else {
//                         break;
//                     }
//                 }
//                 if (!id_.empty()) {
//                     id = id_.front();
//                     id_.pop_front();
//                     ++cnt1;
//                 } else {
//                     judge = 0;
//                 }
//             }
//         }
        
//         id = 1, jd = 0;
//         int cnt2 = 1;
//         id_.clear();
//         last = 0, judge = 1;
//         while (judge) {
//             if (id % 2 == 1 && s_[id] != s2) {
//                 if (jd == 0) {
//                     jd = 1;
//                     last = s_[id];
//                     s_[id] = s2;
//                 } else {
//                     if (s_[id] != last) {
//                         last = s_[id];
//                         s_[id] = s2;
//                     } else {
//                         id_.push_back(id);
//                     }
//                 }
//             }
            
//             else if (id % 2 == 0 && s_[id] != s1) {
//                 if (jd == 0) {
//                     jd = 1;
//                     last = s_[id];
//                     s_[id] = s1;
//                 } else {
//                     if (s_[id] != last) {
//                         last = s_[id];
//                         s_[id] = s1;
//                     } else {
//                         id_.push_back(id);
//                     }
//                 }
//             }
//             ++id;
//             if (id >= n) {
//                 while (!id_.empty()) {
//                     if (id_[0] % 2 == 1 && s_[id_[0]] == s2) {
//                         id_.pop_front();
//                     } else if (id_[0] % 2 == 0 && s_[id_[0]] == s1) {
//                         id_.pop_front();
//                     } else {
//                         break;
//                     }
//                 }
//                 if (!id_.empty()) {
//                     id = id_.front();
//                     id_.pop_front();
//                     ++cnt2;
//                 } else {
//                     judge = 0;
//                     break;
//                 }
//             }
//         }
        
//         cout << (cnt1 > cnt2 ? cnt2 : cnt1) << endl;
//         delete[] s;
//         delete[] s_;
//     }
    
//     return 0;
// }



//!----------------------------------------------------------------------------------------
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// int calc(const string &s, char start) {
//     int block = 0;
//     char now = start;
//     for (char c : s) {
//         if (c != now) block++;
//         now = (now == '0' ? '1' : '0');
//     }
//     return block;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         string s;
//         cin >> n >> s;
//         int a = calc(s, '0') / 2;
//         int b = calc(s, '1') / 2;
//         cout << min(a, b) << '\n';
//     }
//     return 0;
// }



//!----------------------------------------------------------------------------------------
//! 豆包，和ds一个思路，但写的字更多
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm> // 用于max函数

// using namespace std;

// // 计算差异位置在原串中字符的最长连续相同长度
// int getMaxContinuous(const string& originalStr, const vector<int>& diffIndexes) {
//     if (diffIndexes.empty()) {
//         return 0;
//     }
//     int maxLen = 1;
//     int currentLen = 1;
//     char prevChar = originalStr[diffIndexes[0]];
    
//     for (size_t i = 1; i < diffIndexes.size(); ++i) {
//         char currChar = originalStr[diffIndexes[i]];
//         if (currChar == prevChar) {
//             currentLen++;
//             maxLen = max(maxLen, currentLen);
//         } else {
//             currentLen = 1;
//             prevChar = currChar;
//         }
//     }
//     return maxLen;
// }

// // 计算最少操作次数的核心函数
// int minOperations(const string& s) {
//     int n = s.size();
//     string t0, t1;
    
//     // 生成两个目标交替串模板：T0(0101...) 和 T1(1010...)
//     for (int i = 0; i < n; ++i) {
//         t0 += (i % 2 == 0) ? '0' : '1';
//         t1 += (i % 2 == 0) ? '1' : '0';
//     }
    
//     // 收集与两个目标串的差异位置
//     vector <int> diff0, diff1;
//     for (int i = 0; i < n; ++i) {
//         if (s[i] != t0[i]) {
//             diff0.push_back(i);
//         }
//         if (s[i] != t1[i]) {
//             diff1.push_back(i);
//         }
//     }
    
//     // 计算两种方案的最少操作数
//     int op0 = getMaxContinuous(s, diff0);
//     int op1 = getMaxContinuous(s, diff1);
    
//     return min(op0, op1);
// }

// int main() {
//     string s;
//     cout << "请输入01字符串：";
//     cin >> s;
    
//     // 输入合法性校验（可选，确保输入只有0和1）
//     for (char c : s) {
//         if (c != '0' && c != '1') {
//             cout << "输入错误：只能包含0和1！" << endl;
//             return 1;
//         }
//     }
    
//     int result = minOperations(s);
//     cout << "最少操作次数：" << result << endl;
    
//     return 0;
// }



//!----------------------------------------------------------------------------------------
//! ds
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// int solve_for_pattern(const string& s, int start) {
//     int n = s.length();
//     int max_len = 0;          // 最长连续相同奇偶性长度
//     int cur_len = 0;          // 当前连续相同奇偶性长度
//     int last_parity = -1;     // 上一个需要翻转位置的奇偶性，-1 表示尚未遇到

//     for (int i = 0; i < n; ++i) {
//         // 计算目标字符：索引 i（从0开始）对应目标为 start^(i%2)？实际上：
//         // 若 start=0，则目标为 0,1,0,1,... 即 i%2==0?0:1
//         // 若 start=1，则目标为 1,0,1,0,... 即 i%2==0?1:0
//         int target = (i % 2 == 0) ? start : 1 - start;
//         if (s[i] - '0' != target) {          // 需要翻转
//             int parity = (i + 1) % 2;        // 位置索引从1开始算奇偶性
//             if (parity == last_parity) {
//                 ++cur_len;
//                 max_len = max(max_len, cur_len);
//             } else {
//                 cur_len = 1;
//                 max_len = max(max_len, cur_len); // 新序列长度为1
//                 last_parity = parity;
//             }
//         }
//     }
//     return max_len;
// }

// int main() {
//     string s;
//     cin >> s;
//     int ans1 = solve_for_pattern(s, 0);   // 模式 0101...
//     int ans2 = solve_for_pattern(s, 1);   // 模式 1010...
//     cout << min(ans1, ans2) << endl;
//     return 0;
// }



//!----------------------------------------------------------------------------------------
//! ds本土化,没过
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// int so(const string& s, int start) {
//     int n = s.length();
//     int max_l = 0;
//     int cur_l = 0;
//     int last = -1;

//     for (int i = 0; i < n; ++i) {
//         int target = (i % 2 == 0) ? start : 1 - start;
//         if (s[i] - '0' != target) {
//             int parity = (i + 1) % 2;
//             if (parity == last) {
//                 ++cur_l;
//                 max_l = max(max_l, cur_l);
//             } else {
//                 cur_l = 1;
//                 max_l = max(max_l, cur_l);
//                 last = parity;
//             }
//         }
//     }
//     return max_l;
// }

// void an (const string &s) {
//     int ans1 = so(s, 0);
//     int ans2 = so(s, 1);
//     cout << min(ans1, ans2) << endl;
// }

// int main() {
//     int t;
//     cin >> t;

//     for (int i = 0; i < t; ++i) {
//         int n;
//         cin >> n;
//         string s;
//         cin >> s;
//         an(s);
//     }
//     return 0;
// }



//!----------------------------------------------------------------------------------------
//! 豆包本土化
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int get(const string& s1, const vector<int>& s2) {
    if (s2.empty()) {
        return 0;
    }
    int maxLen = 1;
    int curLen = 1;
    char past = s1[s2[0]];
    
    for (size_t i = 1; i < s2.size(); ++i) {
        char currChar = s1[s2[i]];
        if (currChar == past) {
            curLen++;
            maxLen = max(maxLen, curLen);
        } else {
            curLen = 1;
            past = currChar;
        }
    }
    return maxLen;
}

int mi(const string& s) {
    int n = s.size();
    string t0, t1;
    
    for (int i = 0; i < n; ++i) {
        t0 += (i % 2 == 0) ? '0' : '1';
        t1 += (i % 2 == 0) ? '1' : '0';
    }
    
    vector <int> d0, d1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t0[i]) {
            d0.push_back(i);
        }
        if (s[i] != t1[i]) {
            d1.push_back(i);
        }
    }
    
    int op0 = get(s, d0);
    int op1 = get(s, d1);
    
    return min(op0, op1);
}

int main() {
    string s;
    cin >> s;
    
    int result = mi(s);
    cout << result << endl;
    
    return 0;
}