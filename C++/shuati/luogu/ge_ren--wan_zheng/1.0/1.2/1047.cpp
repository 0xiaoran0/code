// #include <bits/stdc++.h>
// using namespace std;

// int main () {
//     int n, cnt;
//     cin >> n >> cnt;

//     int* tree = (int*)malloc(sizeof(int)*(n+1));

//     int* a = tree;
//     for (int i = 0; i < n+1; i++) {
//         *a++ = 1;
//     }

//     for (int i = 0; i < cnt; i++) {
//         int a, b;
//         cin >> a >> b;

//         for (int j = a; j <= b; j++) {
//             tree[j] = 0;
//         }
//     }

//     int cnt_ = 0;
//     for (int i = 0; i < n+1; i++) {
//         if (tree[i]) {
//             cnt_++;
//         }
//     }

//     cout << cnt_ << endl;
    
//     return 0;
// }



//https://www.luogu.com.cn/problem/solution/P1047
#include <iostream>
using namespace std;

int main () {               //*差分
    int n, cnt;
    cin >> n >> cnt;

    int* tree = (int*)malloc(sizeof(int)*(n+1));

    int* a = tree;
    for (int i = 0; i < n+1; i++) {
        *a++ = 0;
    }

    for (int i = 0; i < cnt; i++) {
        int a1, b;
        cin >> a1 >> b;

        tree[a1]++;
        if (b == n) {
            tree[b] -= 2;
        } else {
            tree[b+1]--;
        }
    }
    
    int cnt_ = 0;
    for (int j = 0; j < n; j++) {
        tree[j+1] += tree[j];
        if (!tree[j]) cnt_++;
    }
    if (!tree[n]) cnt_++;

    cout << cnt_ << endl;

    
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// int main () {
//     int n, cnt;
//     cin >> n >> cnt;

//     int* tree = (int*)malloc(sizeof(int)*(n+1));

//     int* a = tree;
//     for (int i = 0; i < n+1; i++) {
//         *a++ = 0;
//     }

//     for (int i = 0; i < cnt; i++) {
//         int a, b;
//         cin >> a >> b;

//         tree[a]++;
//         tree[b+1]--;


//     }
    
//     int cnt_ = 0;
//     for (int j = 0; j < n+1; j++) {
//         tree[j+1] += tree[j];
//         if (!tree[j]) cnt_++;
//     }

//     cout << cnt_ << endl;

    
//     return 0;
// }