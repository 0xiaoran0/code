// #include <bits/stdc++.h>                      //通过ASCLL码输入字符不能直接输入，如输入 65 只会读取 6 作为字符
// using namespace std;

// int main () {
//     int a;
//     cin >> a;
//     char b = a;
//     cout << b;

//     return 0;
// }



// #include <bits/stdc++.h>
// #include <string>
// using namespace std;

// int main () {
//     char a = '*';                               //单个字符用单引号
//     cout<<string(5, a);                         //把 a 输出五次，也可以通过循环
    
//     return 0;
// }



// #include <bits/stdc++.h>                        //结构体数组
// using namespace std;
// struct st {
//     int a;
// }ai[3];

// int main () {
//     for (int i = 0; i < 3; i++) {
//         ai[i].a = i*10;
//     }

//     for (int i = 0; i < 3; i++) {
//         cout << (ai[i].a)+1 << endl;
//     }
    
//     return 0;
// }



// #include <bits/stdc++.h>                       //通过结构体指针测试结构体的初始化
// using namespace std;

// struct st {
//     int a;
//     int b;
// };

// int main () {
//     st s1 = {1, 2};
//     st* p = &s1;
//     cout << p -> a << endl;
    
//     return 0;
// }



// #include <bits/stdc++.h>                             //测试结构体嵌套怎么输出
// using namespace std;

// struct student {
//     string c;
//     int d;
// };

// struct teacher {
//     string a;
//     int b;
//     struct student stu;
// };

// int main () {
//     teacher tea = {"a", 8};
//     tea.stu = {"c", 4};
//     cout << tea.stu.c << endl;
    
//     return 0;
// }



// #include <bits/stdc++.h>                            //测试引用,引用值作为参数 和 以引用值类型返回
// using namespace std;

// void f1(int &x) {
//     x = 1;
// }

// int& f2(int &x) {                                   //若此处不是引用，而是传递一个值，那无法返回引用
//     x++;
//     return x;
// }

// int main () {
//     int a = 0;
//     f1(a);
//     cout << a;

//     int b = 0;
//     int &c = f2(b);
//     cout << c;
    
//     return 0;
// }



// #include <iostream>                                                            //! << 重载实现类的输出
// using namespace std;

// class A {
//     public:
//         int a1;
//         int a2;

//         void A1 (int x1, int x2) {
//             a1 = x1;
//             a2 = x2;
//         }

//         // friend ostream& operator << (ostream &os, const A &x) {              //重载(1)，使用友元函数的形式，不能使用const
//         //     os << "(" << x.a1 << "," << x.a2 << ")" << endl;
//         //     return os;
//         // }
// };

// ostream& operator << (ostream &os, const A &x) {                         //!重载(2)，使用普通法函数的形式
//             os << "(" << x.a1 << "," << x.a2 << ")" << endl;
//             return os;
//         }

// int main () {
//     A i;
//     i.A1(1, 1);
//     cout << i;

//     return 0 ;
// }



// #include <bits/stdc++.h>
// using namespace std;

// int main () {                               //指针套娃
//     int a = 1;
//     int* b = &a;
//     int** c = &b;                           //指针的指针的数据类型是 int**
//     cout << *b << endl;
//     cout << **c << endl;
    
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// void fun (int a) {                              //*静态变量和常量在递归中的不同表现
//     if (a == 0) {
//         return;
//     }
//     static int b = a;
//     const int d = a;                                     //todo 终究只是局部变量，不能在递归中保持数值不变
//     cout << b << "\t" << d << endl;
//     fun(a-1);
//     return;
// }

// int main () {
//     int a;
//     cin >> a;
//     fun(a);

//     static int c = 0;
//     static int c = 1;             //*这两种都是重定义
//     int c = 2;

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// int main () {
//     string s = "";
//     if (s[1]) cout << "c";
//     else cout << "v";
    
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// int main () {
    
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// int main () {
    
//     return 0;
// }



// #include <iostream>
// using namespace std;

// class base;
// class son;
// void test01 ();
// void test02 ();

// int main () {
//     test01();
//     test02();

//     return 0 ;
// }
// class base {
//     public:
// };

// class son :public base {
//     public:
// };

// void test01() {
// }

// void test02 () {
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class A;
// void test01();

// int main () {
//     test01();

//     return 0 ;
// }

// class A {
//     public:
//         A (): a(1) {};

//     int a;
// };

// void test01() {

// }



// #include <iostream>
// #include <list>
// #include <algorithm>
// #define endl '\n'
// typedef long long ll;
// using namespace std;

// int main () {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     list <int> l;
//     l.insert(l.begin(), 1);
//     list <int>::iterator bgn = l.begin();
//     ++bgn;
//     l.insert(bgn, 2);
//     cout << l.front() << " " << l.back();
    
//     return 0;
// }



// const int MOD = 1e9+7;
// long long pow_mod(long long a, long long b) { // 快速幂求逆元
//     long long res = 1;
//     while (b) {
//         if (b & 1) res = res * a % MOD;
//         a = a * a % MOD;
//         b >>= 1;
//     }
//     return res;
// }



