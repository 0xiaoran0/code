#include <iostream>
#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>
void my_swap (T &a, T &b) {
    T te = a;
    a = b;
    b = te;
}

int main () {                       //* 函数模板
    int a = 1, b = 0;
    my_swap(a, b);                             //* 编译器自己识别类型
    cout << a << " " << b << endl;

    my_swap <int> (a, b);                      //* 手动输入类型
    cout << a << " " << b << endl;
    
    return 0;
}



// #include <iostream>
// #define endl '\n'
// typedef long long ll;
// using namespace std;

// int main () {
    
//     return 0;
// }



// #include <iostream>
// #define endl '\n'
// typedef long long ll;
// using namespace std;

// int main () {
    
//     return 0;
// }