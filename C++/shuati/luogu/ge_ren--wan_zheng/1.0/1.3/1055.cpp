#include <iostream>
#include <string>
using namespace std;

int main () {
    string ch;
    int sum = 0;
    int i_ = 0;
    cin >> ch;
    for (int i = 0; i < 12; ++i) {
        if (ch[i] == '-') continue;

        sum += (ch[i] - '0') * (++i_);
    }

    int n = sum % 11;
    char c;
    if (n == 10) {
        c = 'X';
    } else {
        c = n + '0';
    }
    if (c == ch[12]) {
        cout << "Right" << endl;
    } else {
        for (int i = 0; i < 12; ++i) {
            cout << ch[i];
        }
        cout << c << endl;
    }

    return 0;
}