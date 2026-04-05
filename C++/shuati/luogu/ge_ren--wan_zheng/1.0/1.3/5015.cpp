#include <iostream>
using namespace std;

int main () {
    char ch;
    int cnt = 0;
    while ((scanf("%c", &ch)) == 1) {
        if (ch == ' ' || ch == '\n') continue;
        cnt++;
    }

    cout << cnt << endl;
    
    return 0;
}