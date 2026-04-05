#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        
        
        vector <long long> v (n);
        vector <long long> v1;
        vector <int> s;
        int cnt = 0;
        long long max_num;
        
        for (int j = 0; j < n; ++j) {
            long long temp;
            scanf("%lld", &temp);
            
            v[j] = temp;
            s.push_back(0);
        }
        
        v1 = v;
        sort(v1.begin(), v1.end(), greater <long long>());
        max_num = v1[0];
        for (vector <long long>::iterator bgn = v1.begin(); bgn != v1.end(); ++bgn) {
            if (max_num != *bgn) {
                break;
            }
            if (max_num == *bgn) {
                ++cnt;
            }
        }
        
        int index = -1;
        for (vector <long long>::iterator bgn = v.begin(); bgn != v.end(); ++bgn) {
            ++index;
            if (cnt % 2 == 1) {
                if (*bgn == max_num) {
                    s[index] = 1;
                }
            } else {
                if (*bgn != max_num) {
                    s[index] = 1;
                }
            }
        }
        
        for (vector <int>::iterator bgn = s.begin(); bgn != s.end(); ++bgn) {
            printf("%d", *bgn);
        }
        printf("\n");
    }
    
    return 0;
}