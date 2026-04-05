//* 用到了快速幂、分数取模，分析灯泡的状态用到的是概率计算，整体不难



#include <iostream>
using namespace std;

const long long m = 998244353;
const int num = 7;
const int num_cnt = 10;
long long jk (int jk, long long q[10]);
long long fast_pow(long long base, long long e, long long mod);

int main () {
    int t;
    cin >> t;

    int c;
    long long p[num+1];
    long long q[num_cnt] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    long long inv100 = fast_pow(100, m - 2, m);
    for (int i = 0; i < t; ++i) {
        long long q1 = 0;
        long long q2 = 0;
        long long q3 = 0;
        long long q3_ = 0;
        cin >> c;

        for (int j = 0; j < num; ++j){
            cin >> p[j+1];
            p[j+1] = (p[j+1] * inv100 % m) % m;
            q1 = q1 || p[j+1];
            q1 %= m;
        }
        if (0 == q1) {
            cout << 0 << endl;
            continue;
        }

        q[0] = p[1] * p[2] % m * p[3] % m * (m + 1 - p[4]) % m * p[5] % m * p[6] % m * p[7] % m;
        q[1] = (m + 1 - p[1]) * (m + 1 - p[2]) % m * p[3] % m * (m + 1 - p[4]) % m * (m + 1 - p[5]) % m * p[6] % m * (m + 1 - p[7]) % m;
        q[2] = p[1] * (m + 1 - p[2]) % m * p[3] % m * p[4] % m * p[5] % m * (m + 1 - p[6]) % m * p[7] % m;
        q[3] = p[1] * (m + 1 - p[2]) % m * p[3] % m * p[4] % m * (m + 1 - p[5]) % m * p[6] % m * p[7] % m;
        q[4] = (m + 1 - p[1]) * p[2] % m * p[3] % m * p[4] % m * (m + 1 - p[5]) % m * p[6] % m * (m + 1 - p[7]) % m;
        q[5] = p[1] * p[2] % m * (m + 1 - p[3]) % m * p[4] % m * (m + 1 - p[5]) % m * p[6] % m * p[7] % m;
        q[6] = p[1] * p[2] % m * (m + 1 - p[3]) % m * p[4] % m * p[5] % m * p[6] % m * p[7] % m;
        q[7] = p[1] * (m + 1 - p[2]) % m * p[3] % m * (m + 1 - p[4]) % m *(m + 1 - p[5]) % m * p[6] % m * (m + 1 - p[7]) % m;
        q[8] = p[1] * p[2] % m * p[3] % m * p[4] % m * p[5] % m * p[6] % m * p[7] % m;
        q[9] = p[1] * p[2] % m * p[3] % m * p[4] % m * (m + 1 - p[5]) % m * p[6] % m * p[7] % m;

        for (int j = 0; j < num_cnt; ++j){
            q[j] %= m;
            q2 = q2 || q[j];
        }

        if (0 == q2) {
            cout << 0 << endl;
            continue;
        }

        for (int j = 0; j <= c / 2; ++j) {
            int k = c - j;
            if (j >= 0 && j <= 9999 && k >= 0 && k <= 9999) {
                long long qj = jk(j, q);
                long long qk = jk(k, q);
                q3_ = qj * qk;
                q3_ %= m;
                
                if (j * 2 != c) {
                    q3_ *= 2;
                    q3_ %= m;
                }

                q3 += q3_;
                q3 %= m;
            }
        }

        if (0 == q3) {
            cout << 0 << endl;
            continue;
        }
        cout << q3 << endl;
    }
    
    return 0;
}

long long jk (int jk, long long q[10]) {
    int j[4];
    j[0] = jk % 10;
    j[1] = jk / 10 % 10;
    j[2] = jk / 100 % 10;
    j[3] = jk / 1000 % 10;

    long long q_ = 1;
    for (int i = 0; i < 4; ++i) {
        q_ *= q[j[i]];
        q_ %= m;
    }

    return q_;
}

long long fast_pow(long long base, long long e, long long mod) {
    long long result = 1;
    base %= mod;
    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        e /= 2;
    }
    return result;
}

//     int c, p1, p2, p3, p4, p5, p6, p7;

        // cin >> c >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> p7;

// #include <iostream>
// using namespace std;

// const long long m = 998244353;
// const int SEG_NUM = 7;
// const int DIGIT_NUM = 10;
// const int FOUR_DIGIT_MAX = 10000;

// // 定义0-9对应的七段数码管点亮状态（索引0-6对应数码管1-7）
// int seg[DIGIT_NUM][SEG_NUM] = {
//     {1,1,1,0,1,1,1}, // 0
//     {0,0,1,0,0,1,0}, // 1
//     {1,0,1,1,1,0,1}, // 2
//     {1,0,1,1,0,1,1}, // 3
//     {0,1,1,1,0,1,0}, // 4
//     {1,1,0,1,0,1,1}, // 5
//     {1,1,0,1,1,1,1}, // 6
//     {1,0,1,0,0,1,0}, // 7
//     {1,1,1,1,1,1,1}, // 8
//     {1,1,1,1,0,1,1}  // 9
// };

// long long fast_pow(long long base, long long e, long long mod) {
//     long long result = 1;
//     base %= mod;
//     while (e > 0) {
//         if (e % 2 == 1) {
//             result = (result * base) % mod;
//         }
//         base = (base * base) % mod;
//         e /= 2;
//     }
//     return result;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     long long inv100 = fast_pow(100, m-2, m);
//     int t;
//     cin >> t;

//     while (t--) {
//         int C;
//         cin >> C;
//         int p[SEG_NUM];
//         for (int i = 0; i < SEG_NUM; ++i) {
//             cin >> p[i];
//         }

//         // 步骤1：计算每个数字0-9的显示概率
//         long long prob[DIGIT_NUM] = {1};
//         for (int d = 0; d < DIGIT_NUM; ++d) {
//             prob[d] = 1;
//             for (int i = 0; i < SEG_NUM; ++i) {
//                 if (seg[d][i] == 1) {
//                     // 该数码管需要点亮：概率 p[i]/100
//                     prob[d] = prob[d] * (p[i] * inv100 % m) % m;
//                 } else {
//                     // 该数码管需要不点亮：概率 (100-p[i])/100
//                     prob[d] = prob[d] * ((100 - p[i]) * inv100 % m) % m;
//                 }
//             }
//         }

//         // 步骤2：预处理所有四位数的概率（0000~9999）
//         long long f[FOUR_DIGIT_MAX] = {0};
//         for (int x = 0; x < FOUR_DIGIT_MAX; ++x) {
//             int d0 = x % 10;
//             int d1 = x / 10 % 10;
//             int d2 = x / 100 % 10;
//             int d3 = x / 1000 % 10;
//             f[x] = prob[d3] * prob[d2] % m;
//             f[x] = f[x] * prob[d1] % m;
//             f[x] = f[x] * prob[d0] % m;
//         }

//         // 步骤3：计算所有满足A+B=C的四位数对的概率和
//         long long ans = 0;
//         for (int A = 0; A < FOUR_DIGIT_MAX; ++A) {
//             int B = C - A;
//             if (B >= 0 && B < FOUR_DIGIT_MAX) {
//                 ans = (ans + f[A] * f[B] % m) % m;
//             }
//         }

//         cout << ans << '\n';
//     }

//     return 0;
// }