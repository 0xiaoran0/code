#include <iostream>
#include <string>
using namespace std;

struct person {
    int dir;
    string s;
};

int main () {
    int num, cnt;
    cin >> num >> cnt;
    person per[num];
    for (int i = 0; i < num; ++i)
        cin >> per[i].dir >> per[i].s;

    int index = 0;
    int a, s;
    for (int i = 0 ; i < cnt; ++i) {
        cin >> a >> s;
        if (a == per[index].dir)
            index = (index + num - s) % num;                // 加上总数 num, 可以避免额外处理负数
        else
            index = (index + num + s) % num;
    }

    cout << per[index].s;
    
    return 0;
}