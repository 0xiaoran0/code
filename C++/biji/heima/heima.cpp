//#include <bits/stdc++.h>                              //指针运算
//using namespace std;
//
//int main() {
//    int a[] = { 1, 2, 3, 4, 5 };
//    int* p = (int*)(&a[0] + 1);
//    int* q = (int*)(&a + 1);
//    cout << *(p - 1) << endl << *(q - 1);
//
//    return 0;
//}



//#include <iostream>
//using namespace std;
//
//struct st {
//	int a;
//};
//
//int main() {
//	st s1 = {1};                              //结构体
//	cout << s1.a << endl;
//
//	st s2[3];                                 //结构体数组
//	for (int i = 0; i < 3; i++) {
//		s2[i] = { i };
//	}
//	for (int i = 0; i < 3; i++) {
//		cout << s2[i].a << endl;
//	}
//
//	return 0;
//}



//#include <iostream>
//using namespace std;
//
//struct st {
//	int a;
//};
//
//int main() {
//	st s1 = { 1 };
//	st* p = &s1;
//	cout << p -> a << endl;                      //结构体指针
//
//	return 0;
//}



//#include <iostream>
//using namespace std;
//
//struct stu {
//	int b;
//};
//
//struct tea {
//	int a;
//	stu num[3];                                       //结构体嵌套
//};
//
//int main() {
//	tea tea1;
//	tea1.a = 1;
//	for (int i = 0; i < 3; i++) {
//		tea1.num[i].b = i;
//	}
//
//	cout << tea1.a << endl;
//	for (int i = 0; i < 3; i++) {
//		cout << tea1.num[i].b << "\t";
//	}
//
//	return 0;
//}



//#include <iostream>
//using namespace std;
//
//struct st {
//	int a;
//};
//
//void fun1(const st s1) {                           //把结构体作为参数，加上 const 可以保证数值不会变化
//	cout << s1.a <<endl;
//};
//
//void fun2(st* s1) {                                //结构体指针在函数中的应用
//	s1 -> a = 3;
//};
//
//int main() {
//	st s2;
//	s2.a = 2;
//	fun1(s2);
//	
//	st s3 = { 2 };
//	fun2(&s3);
//	cout << s3.a << endl;
//
//	return 0;
//}



//#include <iostream>
//using namespace std;
//
//struct st {
//	int a, b, c;
//
//	bool operator < (const st& x) const {                    //结构体符号重载
//		return b < x.b;
//	}
//};
//
//int main() {
//	st s1 = { 1, 4, 3 };
//	st s2 = { 5, 2, 6 };
//	if (s2 < s1) {
//		cout << s2.a;
//	}
//
//	return 0;
//}



//#include <iostream>
//using namespace std;

//int* fun(void) {
//	int* p = new int(10);                           //new 开辟变量
//	return p;
//}
//
//int main() {
//	int* p = fun();
//	cout << *p << endl;
//	delete p;
//	cout << *p << endl;
//
//	return 0;
//}



// #include <iostream>
// using namespace std;

// int* p = NULL;
// void fun1(void) {
// 	p = new int[10];
// }

// int main() {
// 	fun1();
// 	for (int i = 0; i < 10; i++) {
// 		*p++ = i;                                    //节省步骤
// 	}
// 	p -= 10;                                         //不写这一步，p指向的位置就越界了
// 	for (int i = 0; i < 10; i++) {
// 		cout << *p++ << "\t";
// 	}
// 	delete[] p;

// 	return 0;
// }



// #include <iostream>                             //初始化引用
// using namespace std;

// int main() {
//     int a = 1;
//     int &b = a;
//     cout << b << endl; 
//     int c = 0;
//     b = c;
//     cout << a << "\t" << b;

// 	return 0;
// }



// #include <iostream>                                //引用作为参数
// using namespace std;

// void swap (int &a, int &b) {
//     int t = a;
//     a = b;
//     b = t;
// }

// int main() {
//     int c = 1, d = 2;
//     swap (c, d);
//     cout << c << "\t" << d; 

// 	return 0;
// }



// #include <iostream>
// using namespace std;

// int& fun (void) {
//     static int a = 0;                                     //不能使用临时变量，可以使用静态变量
//     return a;
// }

// int main() {
//     fun() = 1000;                                        //返回值为引用，函数可以作为左值
//     int &b = fun();                                      //输出1000
//     cout << b;

// 	return 0;
// }



// #include <iostream>
// using namespace std;

// int fun (const int &a, int n) {                          //常量修饰引用，防止更改
//     int b = 1;
//     for (int i = 0; i < n; i++) {
//         b = b * a;
//     }
//     return b;
// }

// int main() {
//     int c, n;
//     cin >> c >> n;
//     int d = fun (c, n);
//     cout << d;

// 	return 0;
// }



// #include <iostream>
// using namespace std;

// int fun (int a, int b = 20, int c = 30) {                              //函数声明和函数实现最多一个有默认参数
//     return a + b + c;
// }

// int main() {
//     int a = 10;
//     int b = fun(a);
//     cout << b << endl;

//     int a1 = 10, b1 = 10, c1 = 10;
//     int d1 = fun(a1, b1, c1);
//     cout << d1 << endl;

// 	return 0;
// }



// #include <iostream>                                      //函数重载，条件：参数类型不同、个数不同、顺序不同，返回类型不同不可以作为条件
// using namespace std;

// void fun () {
//     cout << "1" << endl;
// }

// void fun (int a) {
//     cout << "2" << endl;
// }

// void fun (double a) {
//     cout << "3" << endl;
// }

// void fun (int a, double b) {
//     cout << "4" << endl;
// }

// void fun (double b, int a) {
//     cout << "5" << endl;
// }

// int main() {
//     fun();
//     fun(1);
//     fun(3.14);
//     fun(1, 3.14);
//     fun(3.14, 1);

// 	return 0;
// }



// #include <iostream>              //* 参数中const int& 与 int& 不同，两者同时存在时，传入常量只能调用前者，传入变量优先调用后者(只有前者时也可调用前者)
// using namespace std;

// void fun (int &a) {
//     cout << "1" << endl;
// }

// void fun (const int &a) {
//     cout << "2" << endl;
// }

// int main() {
//     int a = 1;
//     fun(a);
//     const int b = 1;
//     fun(b);
//     fun(1);                                            //此处引用的实质，创建了一个临时变量

// 	return 0;
// }



// #include <iostream>
// using namespace std;

// void fun (int a) {
//     cout << "3" << endl;
// }

// void fun (int a, int b = 2) {
//     cout << "4" << endl;
// }

// int main() {
//     fun(1);                                        //不能运行，因为两个函数虽然不同，但此处调用哪一个都可以，产生二义性

// 	return 0;
// }



// #include <iostream>                                         //类与对象权限管理
// #include <string>
// using namespace std;
// class person {
//     public:                                                //可读可写
//         void set_name (string name1) {
//             name = name1;
//         }
//         void get_name (void) {
//             cout << name << endl;
//         }

//     public:                                               //只读不写
//         void get_gender (void) {
//             cout << gender << endl;
//         }

//     public:                                               //只写不读
//         void set_age (int age1) {
//             age = age1;
//         }

//     private:
//         string name = "";
//         string gender = "未知";
//         int age;      
// };

// int main () {
//     person p1;
//     p1.set_name("AI");
//     p1.get_name();
//     p1.get_gender();
//     p1.set_age(18);

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class a2 {
//     public:
//         void set (int c1_, int c2_) {                                       //设置点
//             c1 = c1_;
//             c2 = c2_;
//         }
//         void get () {                                                        //获取点
//             cout << "(" << c1 << "," << c2 << ")" << endl;
//         }

//     private:
//         int c1;
//         int c2;
// };

// class a1 {
//     public:
//         void seti (a2 n1) {                                                 //通过输入一个点类元素对点类进行赋值
//             i = n1;                                                         //同一个类下的元素可以直接赋值
//         }
//         void geti (void) {                                                 //调用点类(这个类中的嵌套类)中的函数
//             i.get();
//         }

//     private:
//         int b1;
//         a2 i;
// };

// int main () {
//     a1 n;
//     a2 i1;
//     i1.set(1, 1);
//     i1.get();

//     n.seti(i1);
//     n.geti();

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class a {
//     public:
//         a () {                                                    //类与对象中构造函数，创建对象的时候会被自动调用，只调用一次
//             cout << "Hello World!" << endl;
//         }

//         ~a () {                                                   //析构函数，对象销毁后执行一次
//             cout << "Good Bye!" << endl;
//         }
// };

// void b (void) {
//     a a1;
// }

// int main () {
//     b();

//     return 0 ;
// }



// #include <iostream>                                                            // << 重载实现类的输出
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

// ostream& operator << (ostream &os, const A &x) {                               //重载(2)，使用普通法函数的形式
//             os << "(" << x.a1 << "," << x.a2 << ")" << endl;
//             return os;
//         }

// int main () {
//     A i;
//     i.A1(1, 1);
//     cout << i;

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class A {
//     public:
//         A () {
//             cout << "Hello" << endl;
//         }
//         A (int x) {
//             cout << "World" << endl;
//         }
//         A (A &x) {                                                     //可通过使用引用拷贝一个对象
//             a1 = x.a1;                                                 //隐含 this 指针
//             a2 = x.a2;
//             cout << "!" << endl;
//         }

//         void set (int a, int b) {
//             a1 = a;
//             a2 = b;
//         }

//         void get (void) {
//             cout << "(" << a1 << "," << a2 << ")" << endl;
//         }

//     private:
//         int a1;
//         int a2;
// };

// int main () {
//     //括号法调用
//     A i1;                                //构造函数无参数时调用不能写括号， A li() 会被认为是函数声明；
//     A i2(1);
//     i2.set(1, 1);

//     A i3(i2);
//     i3.get();

//     //显示法
//     A n1;
//     A n2 = A(10);                            //等号右侧为匿名对象，这一行代码结束后就被销毁，等号左边可以看作是对象的名字
//     A n3 = A(n2);

//     A(10);                                   //会执行并销毁，无意义
//     A(n4);                                   //等效于 A n4; 重建一个对象

//     //隐式转换
//     A j1 = 10;                              //会转换为显示法
//     A j2 = j1;

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// int main () {            //自定义有参构造函数，则编译器不提供默认无参构造函数，自定义拷贝构造函数，则不提供任何默认构造。

//     return 0 ;           //不展示了
// }



// #include <iostream>
// using namespace std;

// class person {
//     public:
//         person () {
//             cout << "A" << endl;
//         }
//         person (int a, int b) {
//             height = new int (b);                            //这里不能写 int* height = ... ; 否则 height 就变成了临时变量，而不是类中的变量
//             cout << "B" << endl;
//         }
//         person (const person &x) {
//             cout << "C" << endl;
//             age = x.age;
//             // height = x.height;                            //编译器的方法，浅拷贝，会出问题
//             if (x.height != NULL) {
//                 height = new int (*x.height);               //自定义，深拷贝，需要记得释放，记得加*
//             } else {
//                 height = NULL;
//             }
//         }
//         ~person () {
//             cout << "Z" << endl;
//             if (height != NULL) {
//                 delete height;
//                 height = NULL;
//                 cout << "Y" << endl;
//             }
//         }

//         void test (void) {
//             cout << *height << endl;
//         }

//     private:
//         int age;
//         int* height = NULL;                               //指针一定要记得初始化
// };

// int main () {
//     person p1 (18, 182);
//     person p2 (p1);
//     p2.test();

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class A {                                                                 //传统赋值，适合动态赋值
//     public:
//         A (int a1, int b1, int c1) {
//             a = a1;
//             b = b1;
//             c = c1;
//         }

//     private:
//         int a;
//         int b;
//         int c;
// };

// class B {
//     public:
//         B (int a1, int b1, int c1): a(a1), b(b1), c(c1) {}                 //初始化列表，性能更好

//     private:
//         int a;
//         int b;
//         int c;
// };

// int main () {
//     A p1(10, 20, 30);                                                       //赋值过程，不再验证了
//     B p2(10, 20, 30);

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class B {
//     public:
//         B (int a, int b): b1(a), b2(b) {}

//         int b1;
//         int b2;
// };

// class A {
//     public:
//         A (int a, int b, int c): a1(a), p2(b, c){}         //看清楚此赋值操作，p2 的赋值其实是隐式转换法赋值

//         int a1;
//         B p2;                                      //类的嵌套
// };

// int main () {                                     //先进行 B 的赋值，再进行 A 的赋值
//     A i1(1, 2, 3);
//     cout << i1.p2.b1 << endl;
//     cout << i1.p2.b2 << endl;

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class A {
//     public:
//         void get (void) {
//             cout << a << endl;
//         }
//         void set (int x) {
//             a = x;
//         }

//         void fun () {
//             cout << A::a << endl;           //可使用类名加变量名访问，不需要具体对象名，遵循访问权限
//         }

//     private:
//        static int a;                         //静态成员变量，类内声明，类外初始化，可理解为全部对象共享
// };
// int A::a = 0;

// int main () {
//     A p1;
//     p1.set(10);
//     A p2;
//     p2.set(20);
//     p1.get();
//     p2.get();

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class A {
//     public:
//         static void fun (int x) {                   //静态成员函数全部对象共享，只能调用静态变量，遵循访问权限
//             // this -> a = x;                       //此函数不能区分要修改非静态变量 是 哪个对象的非静态变量，this 指针在静态函数中无法使用
//             b = x;
//         }

//     private:
//     int a;
//     static int b;
// };
// int A::b = 0;

// int main () {

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class A {

// };

// class B {
//     public:
//         int a;
//         double b;
// };

// int main () {                       //空对象内存为 1 (字节)，只有非静态成员变量属于类对象，非静态成员变量存在时，对象内存为变量的内存
//     A p1;
//     B p2;
//     cout << sizeof(p1) << endl;
//     cout << sizeof(p2) << endl;               //内存对齐

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class A {
//     public:
//         A (int a) {
//             this -> a = a;                       //临时变量最好不要与成员变量名称相同，必要时要使用 this 指针
//         }

//         A& fun (A &x) {
//             a += x.a;
//             return *this;
//         }

//         void f1 () {
//             cout << a << endl;
//         }
    
//     private:
//         int a;

// };

// int main () {
//     A p1 (10);
//     A p2 (10);
//     p2.fun(p1).fun(p1).fun(p1);
//     p2.f1();

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class A {
//     public:
//         void fun1 (void) {
//             cout << "asdf" << endl;
//         }

//         void fun2 (void) {
//             if (this == NULL) {
//                 cout << "NULL" << endl;
//             } else {
//                 cout << a << endl;
//             }
//         }

//         void get (void) {
//             cout << a << endl;
//         }

//     private:
//         int a;
// };

// int main () {
//    A* p1 = NULL;                               //!指针记得悬空
//     p1 -> fun1();
//     p1 ->fun2();

//     A p2;                                       //*编译器默认构造函数赋值 a = 0
//     p2.get();

//     return 0 ;
// }




// #include <iostream>
// using namespace std;

// class A {
//     public:
//         A () {}

//         A (int x) {
//             a = x;
//         }

//         void fun (void) const {                      //*常函数不可以修改成员属性， mutable 关键字可以修改
//             a = 10;
//             cout << a << endl;
//         }

//     private:
//         mutable int a;                              //* mutable 易变的
// };

// int main () {
//     A p1;
//     p1.fun();

//     const A p2(1);                                 //*常对象不可以修改成员属性，mutable 除外，必须初始化
//     p2.fun();                                      //*常对象只能调用常函数

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class A {
//     friend void fun1 (A &p1);                   //*全局函数做友元，需要在类内写下友元声明

//     public:
//         A () {
//             a = 0;
//             b = 1;
//         }

//     public:
//         int a;

//     private:
//         int b;
// };

// void fun1 (A &p1) {
//     cout << p1.a << endl;
//     cout << p1.b << endl;
// }

// int main () {
//     A p1;
//     fun1(p1);

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class A;                         //*类做友元
// class B {
//     public:
//         B ();
//         void fun1 ();

//         A * b;                                //!这一步之前必须先声明 class A 
// };

// class A {
//     friend class B;

//     public:
//         A ();

//     private:
//         int a;
// };

// int main () {                  //* B 类作为 A 类的友元，此处先定义 A 类，再定义 B 类，函数实现写在代码下方
//     B p1;                      //todo B 类定义了 p1, 调用构造函数，构造函数使用 new 定义出一个 A 类，调用了 A 类的构造函数
//     p1.fun1();
//     free(p1.b);

//     return 0 ;
// }

// A::A () {
//     a = 0;
// }

// B::B () {
//     b = new A;                 //!切记之后要释放
// }

// void B::fun1 () {
//     cout << b -> a;
// }



// #include <iostream>
// using namespace std;

// class B;                        //! A的成员包含B，故B先声明

// class A {                       //! B内部的友元函数需要A，故A先定义
//     public:
//         A ();                   //! A的函数实现需要B类的完整定义，故此处先声明，定义放在下方
//         void test (void) ;

//     private:
//         B *b;
// };

// class B {
//     friend void A::test ();

//     public:
//         B ();

//     private:
//         int b1;
// };

// int main () {
//     A a;
//     a.test();

//     return 0 ;
// }

// A::A () {
//     b = new B;
// }

// void A::test (void) {
//     cout << b->b1 << endl;
// }

// B::B () {
//     b1 = 1;
// }




// #include <iostream>
// using namespace std;

// class A;
// ostream& operator << (ostream &cout, const A &x);

// int main () {
//     A a;
//     a.test(1);
//     cout << a;

//     return 0 ;
// }

// class A {
//     friend ostream& operator << (const std::ostream &cout, const A &x);      //* 一般只通过全局函数做友元重载 <<, 成员函数不能使 cout 在左侧
//     public:
//         void test (int a) {
//             this -> a = a;
//         } 

//     private:
//         int a;
// };

// ostream& operator << (ostream &cout, const A &x) {                           //todo 即为 operate << (cout, x), 简化为 cout << x;
//     cout << "(" << x.a << ")" << endl;
//     return cout;
// }



// #include <iostream>
// using namespace std;

// class A;
// ostream& operator << (ostream &cout, const A &x);
// void test01 ();
// void test02 ();

// int main () {
//     test01();
//     test02();

//     return 0 ;
// }

// class A {
//     friend ostream& operator << (ostream &cout, const A &x);
//     friend void test01 ();
//     public:
//         A () {a = 1;}

//         A& operator++ () {                            //* 前置递增，返回引用是为了链式编程
//             ++a;
//             return *this;
//         }

//         A operator++ (int) {                           //* 后置递增，只能返回值，不能返回引用。int 只是一个后置递增的标志，防止重定义，无实意
//             A a1 = *this;
//             ++a;
//             return a1;
//         }

//     private:
//         int a;
// };

// ostream& operator << (ostream &cout, const A &x) {
//     cout << "(" << x.a << ")" << endl;
//     return cout;
// }

// void test01 () {
//     A a1;
//     cout << a1;
//     cout << ++a1;
//     cout << a1;
// }

// void test02 () {
//     A a2;
//     cout << a2;
//     cout << a2++;
//     cout << a2;
// }



// #include <iostream>
// using namespace std;

// class A;

// void test01 ();

// int main () {
//     test01();

//     return 0 ;
// }

// class A {
//     public:
//         A (int x) {
//             a = new int (x);
//         }
//         ~A () {
//             if (a != NULL) {
//                 delete a;
//                 a = NULL;
//             }
//         }

//         A& operator = (A& x) {             //! 这里返回值的话，临时对象在函数运行后析构，内存释放，a2 指向无用内存，而且 a2 析构时导致内存重复释放
//             if (a != NULL) {
//                 delete a;
//                 a = NULL;
//             }
//             a = new int (*(x.a));

//             return *this;
//         }

//         int *a;
// };

// void test01 () {
//     A a1(18);
//     cout << *a1.a << endl;
//     A a2(20);
//     cout << *a2.a << endl;
//     a2 = a1;                                       //! 这一步会将数值进行复制, 地址也会复制过去, 导致指针指向同一片区域
//     cout << *a1.a << endl;                         //! 在析构函数运行过后, a1中指针指向的内存已被释放, 但 a2 依然指向那里，导致内存重复释放
//     cout << *a2.a << endl;                         //! 所以在有指针存在的类中, 赋值运算符要自己重载
// }



// #include <iostream>
// using namespace std;

// class A {
//     public:
//         A (int x) :a(x) {};                            //todo 快速赋值

//         bool operator > (A &x) {                      //* 其他的不演示了
//             return a > x.a;
//         }

//         int a;
// };

// int main () {
//     A a1(10);
//     A a2(20);
//     cout << (a1 > a2) << endl;

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class PRINT {
//     public:
//         void operator () (int x) {           //* 此处指进行简单尝试，后续 STL 会用到，拥有封装思想，有一定好处
//             cout << x;                       //* 重载 () 也成为仿函数
//         }
// };

// int main () {
//     PRINT my_print;
//     my_print(10);

//     PRINT ()(20);                     //todo 创建匿名对象，执行后立即释放，避免创建一个只使用一次的对象

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class A;                                // 讨论继承权限
// class B;
// void test01();

// int main () {
//     test01();

//     return 0 ;
// }

// class base {
//     public:
//         void a1() {
//             cout << "a1" << endl;
//         }

//     protected:

//     private:
// };

// class B : public base {             //! 其他继承方式不展示了，默认私有继承，权限只会从公共到私有，父类中私有成员在子类中存在，但不可直接访问
// };                                  //* 继承中构造、析构函数的顺序为 父类-子类-子类-父类

// void test01 () {
//     base a1;
//     a1.a1();
//     B b1;
//     b1.a1();
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
//         void func () {
//             cout << "base" << endl;
//         }

//         int a;
// };

// class son :public base {
//     public:
//         son () {
//             a = 10;
//             base::a = 20;
//         }

//         void func () {
//             cout << "son" << endl;
//         }

//         int a;
// };

// void test01() {
//     son a1;
//     cout << a1.a << endl;
//     cout << a1.base::a << endl;                     //* 访问父类同名成员属性需要加作用域
// }

// void test02 () {
//     son a2;
//     a2.func();                                      //* 子类的同名成员函数会隐藏父类所有 同名的 成员函数和所有重载，子类没有则可以直接访问
//     a2.base::func();
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
//         static void func () {
//             cout << "base-static" << endl;
//         }

//         static int a;
// };
// class son :public base {
//     public:
//         static void func () {
//             cout << "son-static" << endl;
//         }

//         static int a;
// };
// int son::a = 10;                               //* 类内声明，类外初始化
// int base::a = 20;

// void test01() {
//     son a1;                                    //* 两种访问方式，和普通属性一样受权限影响，第一种通过对象名字进行访问
//     cout << a1.a << endl;
//     cout << a1.base::a << endl;

//     cout << son::a << endl;                    //* 第二种直接通过类名进行访问
//     cout << base::a << endl;
//     cout << son::base::a << endl;
// }

// void test02 () {
//     son a2;                                     //* 和成员属性相同，两种调用方式
//     a2.func();                                  //* 子类同样会隐藏 父类中 所有同名重载
//     a2.base::func();

//     son::func();
//     son::base::func();
// }



// #include <iostream>
// using namespace std;

// class base1;
// class base2;
// class son;
// void test01 ();

// int main () {
//     test01();

//     return 0 ;
// }
// class base1 {
//     public:
//         base1 () : a(1) {};

//         int a;
// };

// class base2 {
//     public:
//         base2 () : a(2) {};

//         int a;
// };

// class son :public base1, public base2 {                  //* 多次继承，逗号分隔
//     public:
//         son () : a(3) {};

//         int a;
// };

// void test01() {
//     son s1;
//     cout << s1.base1::a << endl;                        //* 使用继承自不同父类中的同名属性 需要加作用域
//     cout << s1.base2::a << endl;                        //* 不建议多继承，因为要写作用域，很麻烦
//     cout << s1.a << endl;
// }



// #include <iostream>
// using namespace std;

// int main () {

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// class base;                            //* 菱形继承的虚继承
// class son1;
// class son2;
// class g_son;
// void test01 ();

// int main () {
//     test01();

//     return 0 ;
// }

// class base {
//     public:
//         base () : a(1) {};

//         int a;
// };

// class son1 : virtual public base {         //* 虚继承，用于菱形继承(不推荐)，虚继承与同一个父类的两个子类共享虚继承来的成员属性
// };

// class son2 : virtual public base {         //* 虚继承避免了菱形继承时来自祖父类的成员属性重复的问题，但好像又不利于子类的多样性
// };

// class g_son : public son1, public son2 {
// };

// void test01() {
//     g_son s1;
//     cout << s1.a;                           //? 如果出现了同名属性，应该同上
// }



#include <iostream>
using namespace std;

class base;
class son1;
class son2;
void test01 ();
void test02 (base &b1);

int main () {
    test01();

    return 0 ;
}
class base {
    public:
    virtual void func1 () {                     //* 虚函数，地址晚绑定，根据传入类型决定调用函数
        cout << "base" << endl;                 //* 要求: virtual 关键字，子类有一个完全相同的函数结构，使用引用或指针
    }

    void func2 () {                             //* 地制早绑定，直接采用占位参数的类型，效率更高
        cout << "base" << endl;
    }

};

class son1 :public base {
    public:
        void func1 () {
            cout << "son1" << endl;
        }
};

class son2 :public base {
    public:
        void func1 () {
            cout << "son2" << endl;
        }
};

void test01() {
    base b1;
    test02(b1);
    son1 s1;
    test02(s1);
    son2 s2;
    test02(s2);
}

void test02 (base &b1) {
    b1.func1();                                     //* 是否为虚函数调用结果不同
    b1.func2();
}

// 54 左右



// #include <iostream>
// using namespace std;

// int main () {

//     return 0 ;
// }



// #include <iostream>
// using namespace std;

// int main () {

//     return 0 ;
// }