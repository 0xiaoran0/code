#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < s.size(); ++i) {
        cout << (char)((s[i] - 'a' + n) % 26 + 'a');
    }
    
    return 0;
}