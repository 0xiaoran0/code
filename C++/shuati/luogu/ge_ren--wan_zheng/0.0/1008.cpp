#include <iostream>
using namespace std;

int main () {
    for (int i1 = 192; i1 < 333; ++i1) {
        int nums[9];
        int i2 = i1 * 2;
        int i3 = i1 * 3;
        nums[0] = i1 % 10;
        nums[1] = i1 / 10 % 10;
        nums[2] = i1 / 100;
        nums[3] = i2 % 10;
        nums[4] = i2 / 10 % 10;
        nums[5] = i2 / 100;
        nums[6] = i3 % 10;
        nums[7] = i3 / 10 % 10;
        nums[8] = i3 / 100;
        int judge = 1;
        for (int i = 0; i < 9; ++i) {
            if (nums[i] == 0) judge = 0;
            for (int j = i+1; j < 9; ++j) {
                if (nums[i] == nums[j]) judge = 0;
            }
        }

        if (judge) cout << i1 << ' ' << i2 << ' ' << i3 << endl;
    }
    
    return 0;
}