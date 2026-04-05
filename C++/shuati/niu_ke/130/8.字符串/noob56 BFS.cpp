#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int st = 0, jd = 0, id = -1;
    for (int i = 0; i < s.size(); ++i) {
        switch (st) {
            case 0:
                if (s[i] == 'B' || s[i] == 'b') {
                    id = i;
                    st = 1;
                } else {
                    id = -1;
                    st = 0;
                }
                break;

            case 1:
                if (s[i] == 'o' || s[i] == 'O') {
                    st = 2;
                } else if (s[i] == 'B' || s[i] == 'b') {
                    id = i;
                    st = 1;
                } else {
                    st = 0;
                    id = -1;
                }
                break;

            case 2:
                if (s[i] == 'b' || s[i] == 'B') {
                    jd = 1;
                    cout << id;
                } else {
                    st = 0;
                    id = -1;
                }
                break;
        }

        if (jd == 1)
            break;
    }

    if (jd != 1)
        cout << -1;
    
    return 0;
}