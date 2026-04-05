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
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '5') cout << '*';
        else cout << s[i];
    }
    
    return 0;
}