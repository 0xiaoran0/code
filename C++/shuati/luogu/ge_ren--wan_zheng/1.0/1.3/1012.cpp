// #include <iostream>
// #include <string>
// using namespace std;

// int main () {
//     int n;
//     cin >> n;
//     string si[n];
//     for (int i = 0; i < n; ++i) {
//         string s;
//         cin >> s;
//         si[i] = s;
//     }

//     string answer = "";
//     for (int i = n-1; i >= 0; --i) {
//         for (int j = 0; j < i; ++j) {
//             if (si[j] > si[j+1]) {
//                 string s_ = si[j];
//                 si[j] = si[j+1];
//                 si[j+1] = s_;
//             }
//         }
//         answer += si[i];
//     }
    
//     cout << answer << endl;
//     return 0;
// }



#include <iostream>
#include <string>
using namespace std;

int main () {
    int n;
    cin >> n;
    string si[n];
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        si[i] = s;
    }

    string answer = "";
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (si[j] + si[j+1] > si[j+1] + si[j]) {
                string s_ = si[j];
                si[j] = si[j+1];
                si[j+1] = s_;
            }
        }
        if (si[i] == "0") {
            cout << "0" << endl;
            break;
        } else {
            cout << si[i];
        }
    }

    return 0;
}