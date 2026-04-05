#include <iostream>
#include <deque>
#include <algorithm>
#include <random>
using namespace std;

const int X0 = 20;
const int Y0 = 20;                                           // 没想到起个 y0 的名字还重名了

class sna {
    public:
        sna (int x_, int y_) {
            x = x_;
            y = y_;
        }

        int x;
        int y;
};

char map_[X0][Y0];
void map_start(char (*map_) [Y0]);
void print_map (char (*map_) [Y0]);
void clear_screen();

int main () {
    deque <sna> d;
    map_start(map_);
    
    int x1 = rand() % X0;
    int y1 = rand() % Y0;
    map_[x1][y1] = '*';
    sna s1(x1, y1);
    d.push_front(s1);
    print_map(map_);

    int ipt;
    cin >> ipt;
    while (ipt != 'p') {
        
    }

    return 0;
}

void map_start(char (*map_) [Y0]) {
    for (int i = 0; i < X0; ++i) {
        for (int j = 0; j < Y0; ++j) {
            map_[i][j] = ' ';
        }
    }
}

void print_map (char (*map_) [Y0]) {
    for (int i = 0; i < X0; ++i) {
        for (int j = 0; j < Y0; ++j) {
            cout << map_[i][j];
            if (j != Y0 - 1) cout << " ";
        }
        cout << endl;
    }
}

void clear_screen() {
    // \033[2J：清屏；\033[1;1H：光标移到左上角
    cout << "\033[2J\033[1;1H";
    cout.flush();  // 强制刷新输出缓冲区，避免画面延迟
}