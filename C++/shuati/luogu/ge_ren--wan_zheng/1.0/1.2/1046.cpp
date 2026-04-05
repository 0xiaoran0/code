// #include <bits/stdc++.h>
// using namespace std;

// int main () {
//     int array[10];
//     for (int i = 0; i < sizeof(array)/sizeof(int); i++) {
//         int n;
//         cin >> n;
//         array[i] = n;
//     }

//     int n_;
//     int cnt = 0;
//     cin >> n_;

//     for (int i = 0; i < sizeof(array)/sizeof(int); i++) {
//         if (array[i] <= n_+30) {
//             cnt++;
//         }
//     }

//     cout << cnt << endl;
    
//     return 0;
// }



// https://www.luogu.com.cn/problem/solution/P1046
#include <iostream>
using namespace std;
int height[20],H,s;
int main()
{
    for(int i=0;i<10;i++)cin >> height[i];
    cin >> H;
    H += 30;
    for(int i=0;i<10;i++)s+=!(H<height[i]);
    cout << s;
}