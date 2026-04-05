// #include <iostream>
// using namespace std;

// int main () {
//     char ch;
//     cin >> ch;
//     int l_cnt = 0;
//     int r_cnt = 0;
//     int cnt = 0;
//     while ( ch != 'E') {
//         ++cnt;
//         if ('W' ==  ch)
//             ++l_cnt;
//         if ('L' == ch)
//             ++r_cnt;
            
//         cin >> ch;
//     }
//     for (int i = 11; i < 22; i += 10) {
//         int l = l_cnt, r = r_cnt;
//         while (l != 0 || r != 0) {
//             if (l >= i) {
//                 cout << i;
//                 l -= i;
//             } else {
//                 cout << l;
//                 l = 0;
//             }
//             cout << ":";
//             if (r >= i) {
//                 cout << i;
//                 r -= i;
//             } else {
//                 cout << r;
//                 r = 0;
//             }
//             cout << endl;
//         }
//         if (i == 11)
//             cout << endl;
//     }
    
//     return 0;
// }



#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int _11[6000][2] = {0};
int _21[3500][2] = {0};

int main () {
    char ch;
    cin >> ch;
    int in_11 = 0;
    int in_21 = 0;
    long long cnt = 0;

    while (ch != 'E') {
        if ('W' ==  ch){
            ++(_11[in_11][0]);
            ++(_21[in_21][0]);
        }
        if ('L' == ch){
            ++(_11[in_11][1]);
            ++(_21[in_21][1]);
        }
        ++cnt;

        if (max(_11[in_11][0],_11[in_11][1])>=11 && abs(_11[in_11][0]-_11[in_11][1])>=2)
            ++in_11;
        if (max(_21[in_21][0],_21[in_21][1])>=21 && abs(_21[in_21][0]-_21[in_21][1])>=2)
            ++in_21;

        cin >> ch;
    }

    for (int i = 0; i <= in_11; ++i) {
        cout << _11[i][0] << ":" << _11[i][1] << endl;               // 没想到最后一局的 0:0 也要输出
    }
    cout << endl;

    for (int i = 0; i <= in_21; ++i) {
        cout << _21[i][0] << ":" << _21[i][1] << endl; 
    }

    return 0;
}