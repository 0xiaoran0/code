#include <iostream>                                  //1.1.2
#include <time.h>
using namespace std;

void p1 (int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << "\t";
    }
}

void p2 (int n) {
    static int j = n+1;                      //静态变量可以，常量不可以
    if (n) {
        cout << j - n-- << "\t";             //挺抽象的一步
        p2(n);
    }
}

void p3 (int n) {                            //正经递归比上面乱七八糟的东西好
    if (n) {
        p3(n-1);                             // n-1 可以，n-- 不行，不知为何
        cout << n << "\t";
    }
}

int main () {
    clock_t a1, b1;
    double t;
    static int m = 5000;

    a1 = clock();
    p1(m);
    b1 = clock();
    t = ((double) (b1 - a1)) / CLK_TCK;
    cout << t << endl;

    a1 = clock();
    p2(m);
    b1 = clock();
    t = ((double) (b1 - a1)) / CLK_TCK;
    cout << t << endl;

    a1 = clock();
    p3(m);
    b1 = clock();
    t = ((double) (b1 - a1)) / CLK_TCK;
    cout << t << endl;

    return 0;
}



// #include <iostream>                                //1.1.3
// #include <iomanip>
// #include <time.h>
// using namespace std;

// static int j = 100;                          //多项式最高次项系数
// static double x = 1.1;                     //自变量的值

// double fun1 (double n) {
//     double s = 0.0;
//     for (int i = 0; i <= j; i++) {                      //遍历每一项
//         double m = 1.0;
//         for (int k = 0; k < i; k++) {                  //*实现次方，之前我令 m = n,还要判断 i 是否等于一，脑抽了
//             m *= n;
//         }
//         s += m;
//     }
//     return s;
// }

// double fun2 (double n, int j, double s) {
//     if (j == 0) {
//         return 1.0;
//     }
//     double m = 1.0;
//     for (int i = 0; i < j; i++) {                                     //!在调试时一直在循环，不知道为什么
//         m *= n;
//     }
//     j--;
//     double s1 = fun2(n, j, s);                                         //!每次调用会重置 s 的值，要把 s 写作全局变量或作为参数传入
//     s += m + s1;

//     return s;

// }

// void time (clock_t a1, clock_t b1, double t) {
//     t = ((double) (b1 - a1)) / CLK_TCK;
//     cout << defaultfloat;
//     cout << fixed << setprecision(10) << "时间" << "\t" << t << endl;
// }

// int main () {
//     clock_t a1, b1;
//     double t = 0.0;
//     static int count = 10000;
//     double s1, s2;

//     a1 = clock();
//     for (int i = 0; i < count; i++) {
//         s1 = fun1(x);
//     }
//     b1 = clock();
//     time (a1, b1, t);
//     cout << defaultfloat;
//     cout << fixed << setprecision(10) << s1 << endl;

//     a1 = clock();
//     for (int i = 0; i < count; i++) {
//         double s = 0.0;
//         s2 = fun2(x, j, s);
//     }
//     b1 = clock();
//     time (a1, b1, t);
//     cout << defaultfloat;
//     cout << fixed << setprecision(10) << s2 << endl;

//     return 0;
// }



// #include <iostream>
// using namespace std;

// int main () {

//     return 0;
// }



// #include <iostream>
// using namespace std;

// int main () {

//     return 0;
// }