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

    int cnt = s.size();
    for (int i = 0; i < s.size(); ++i) {
        cout << s[i];
        --cnt;
        if (cnt % 3 == 0 && cnt != 0) {
            cout << ",";
        }
    }
    
    return 0;
}