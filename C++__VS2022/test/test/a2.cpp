#include "a2.h"

void a2::set(int i11, int i21) {
    i1 = i11;
    i2 = i21;
}
void a2::get() {                                                        //ªÒ»°µ„
    cout << "(" << i1 << "," << i2 << ")" << endl;
}

int i1;
int i2;