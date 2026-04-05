#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int fi (string &s1, string s[4]) {
    int i;
    for (i = 0; i < 4; ++i) {
        if (s[i] == s1) {
            return i;
        }
    }
    return -1;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s[4] = {"elephant", "tiger", "cat", "mouse"};
    string s1, s2;
    cin >> s1 >> s2;

    int id1 = fi(s1, s);
    int id2 = fi(s2, s);
    if ((id1 + 1) % 4 == id2) {
        cout << "win";
    } else if ((id1 + 3) % 4 == id2) {
        cout << "lose";
    } else {
        cout << "tie";
    }
    
    return 0;
}