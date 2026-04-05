#include <iostream>
using namespace std;

int main () {
    long long m;                                        // 把 int 改成 long long 就通过了
    cin >> m;

    long long fi[3] = {0, 1, 1};
    int index =  0;
    int flag = 0;
    long long cnt = 2;
    for (int i = 0; i <= m * m; ++i) {
        ++cnt;
        fi[index % 3] = fi[(index + 1) % 3] + fi[(index + 2) % 3];
        fi[index % 3] %= m;

        if (0 == fi[index % 3]){
            flag = 1;
            ++index;
            continue;
        }

        if (1 == flag && 1 == fi[index % 3]) {
            cnt -= 1;
            break;
        } else {
            flag = 0;
        }
        ++index;
    }

    cout << cnt;
    
    return 0;
}