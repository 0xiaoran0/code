// #include <iostream>
// using namespace std;

// void step(int n, int k, int* ans, int* nums);

// int main () {
//     int n, k;
//     scanf("%d %d", &n, &k);

//     int* nums = (int*) malloc (sizeof(int) * (n+1));
//     for (int i = 0; i < n + 1; nums[i++] = 0);

//     int ans = 0;
//     step(n, k, &ans, nums);
//     printf("%d", ans);
    
//     return 0;
// }

// void step(int n, int k, int* ans, int* nums) {
//     if (1 == n || 0 == n) {
//         (*ans)++;
//         return;
//     }

//     for (int i = 1; i <= k; ++i) {
//         if (n - i < 0)
//             continue;

//         if (0 != nums[n-i]) {
//             *ans += nums[n-i];
//             continue;
//         } else {
//             int ans_ = *ans;
//             step(n-i, k, ans, nums);
//             nums[n-i] = *ans - ans_;
//         }
//     }
// }



#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    long long* dp = (long long*)malloc(sizeof(long long) * (n+1));
    dp[0] = 1;
    dp[1] = 1;
    
    for (int m = 2; m <= n; m++) {
        dp[m] = 0;
        for (int i = 1; i <= k && (m - i) >= 0; i++) {
            dp[m] += dp[m - i];
            dp[m] %= 100003;
        }
    }
    
    cout << dp[n] << endl;
    free(dp);
    return 0;
}