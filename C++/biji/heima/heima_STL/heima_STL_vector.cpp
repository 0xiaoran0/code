// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void pnt (int x);
// void test01 ();

// int main () {
//     test01();                                                    //* 初识 vector, 并实现遍历输出

//     return 0 ;
// }

// void pnt (int x) {
//     cout << x << endl;
// }

// void test01 () {
//     vector<int> v;
//     for (int i = 0; i < 5; ++i) {
//         v.push_back(i);
//     }

//     vector<int>::iterator bgn = v.begin();                            //* 第一种遍历方式
//     vector<int>::iterator end = v.end();
//     while (bgn != end) {
//         cout << *bgn << endl;
//         ++bgn;
//     }

//     for (vector<int>::iterator bgn = v.begin(); bgn != v.end(); ++bgn) //* 第二种遍历方式
//         cout << *bgn << endl;

//     for_each(v.begin(), v.end(), pnt);                                 //* 第三种遍历方式，使用自带算法，需要自己写一个输出函数
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class A;
// void test01();
// void test02();

// int main () {                                                 //* 容器中存储自定义类型
//     test01();
//     test02();

//     return 0 ;
// }

// class A {
//     public:
//         A (int x): a(x) {};

//     int a;
// };

// void test01() {
//     vector <A> v;
//     for (int i = 0; i < 5; ++i) {
//         A a1(i);
//         v.push_back(a1);
//     }

//     for (vector<A>::iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << bgn->a << endl;
// }

// void test02() {
//     vector <A*> v;
//     for (int i = 0; i < 5; ++i) {
//         A* a1 = new A (i);                                         //* 这里如果不申请内存，队列中的元素将全是这一处地址，会导致数值的覆盖(相当于浅拷贝)
//         v.push_back(a1);
//     }

//     vector<A*>::iterator pre = v.begin();
//     for (vector<A*>::iterator bgn = v.begin(); bgn != v.end();){
//         cout << (*bgn)->a << endl;
//         ++bgn;
//         delete *pre;                                               //* 申请内存就要释放内存
//         pre = bgn;
//     }
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class A;
// void test01();

// int main () {                                         //* 二维队列的创建与遍历
//     test01();

//     return 0 ;
// }

// class A {
//     public:
//         A (): a(1) {};

//     int a;
// };

// void test01() {
//     vector<vector<int>> v;
//     for (int i = 1; i < 5; ++i) {
//         vector<int> v1;
//         for (int j = i; j < 4 * i; j = j + i) {
//             v1.push_back(j);
//         }

//         v.push_back(v1);
//     }

//     for (vector<vector<int>>::iterator bgn = v.begin(); bgn != v.end(); ++bgn) {
//         for (vector<int>::iterator bgn_ = (*bgn).begin(); bgn_ != (*bgn).end(); ++bgn_) {
//             cout << *bgn_ << " ";
//         }
//         cout << endl;
//     }
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void print (vector<int> v);

// int main () {                                       //* vector 的构造方式
//     vector<int> v1;                                 //* 默认无参构造
//     for (int i = 0; i < 4; ++i)
//         v1.push_back(i);
//     print(v1);

//     vector<int> v2 (v1.begin(), v1.end());         //* 使用区间构造
//     print(v2);

//     vector<int> v3 (10, 100);                      //*  初始化 10 个 100
//     print(v3);

//     vector<int> v4 (v1);                           //* 拷贝构造
//     print(v4);

//     return 0 ;
// }

// void print (vector<int> v) {
//     for (vector<int>::iterator bgn = v.begin(); bgn != v.end(); ++bgn) //* 第二种遍历方式
//         cout << *bgn <<" ";
//     cout << endl;
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void print (vector<int> v);

// int main () {                                             //* 四种赋值方式，与构造相似
//     vector<int> v1;
//     for (int i = 0; i < 4; ++i)
//         v1.push_back(i);
//     print(v1);

//     vector<int> v2;
//     v2 = v1;
//     print(v2);

//     vector<int> v3;
//     v3.assign(v1.begin(), v1.end());
//     print(v3);

//     vector<int> v4;
//     v4.assign(10, 100);
//     print(v4);

//     return 0 ;
// }

// void print (vector<int> v) {
//     for (vector<int>::iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << *bgn <<" ";
//     cout << endl;
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void print (vector<int> v);

// int main () {
//     vector<int> v1;
//     for (int i = 0; i < 4; ++i)
//         v1.push_back(i);
//     print(v1);

//     cout << v1.empty() << endl;                      //* 判断是否为空，不为空返回 0
//     cout << v1.capacity() << endl;                   //* 返回容量，再不重新设置大小时，容量与大小相同
//     cout << v1.size() << endl;                       //* 返回大小

//     v1.resize(10, 9);                                //* 重新设置大小，比原来长则填充第二个参数的数据，默认为 0，可以不写
//     print(v1);

//     v1.resize(2);                                    //* 比原来短则直接删除
//     print(v1);

//     return 0 ;
// }

// void print (vector<int> v) {
//     for (vector<int>::iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << *bgn <<" ";
//     cout << endl;
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void print (vector<int> v);

// int main () {
//     vector<int> v1;
//     for (int i = 0; i < 4; ++i)
//         v1.push_back(i);
//     print(v1);

//     v1.pop_back();                                    //* 弹出队尾元素
//     print(v1);

//     v1.insert(v1.begin(), 99);
//     v1.insert(v1.begin(), 2, 100);                    //* 在指定位置插入元素，第二个参数为个数，可以不写，默认为 1
//     print(v1);

//     v1.erase(v1.begin());
//     v1.erase(v1.begin(), v1.end());                   //* 删除区间内元素，第二个参数不写则只删除一个元素，左表达式则是清空队列
//     v1.clear();                                       //* 与上式作用相同
//     print(v1);

//     return 0 ;
// }

// void print (vector<int> v) {
//     for (vector<int>::iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << *bgn <<" ";
//     cout << endl;
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main () {                                                 //* 队列的其他遍历方式
//     vector<int> v1;
//     for (int i = 0; i < 4; ++i)
//         v1.push_back(i);

//     for (int i= 0; i < v1.size(); ++i)                        //* 使用 [] 进行遍历
//         cout << v1[i] << " ";
//     cout << endl;

//     for (int i = 0; i < v1.size(); ++i)                       //* 使用 at() 函数进行遍历
//         cout << v1.at(i) << " ";
//     cout << endl;

//     cout << v1.front() << " " << v1.back() << endl;           //* 访问第一与最后一个元素

//     return 0 ;
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void print (vector<int> v);

// int main () {                                             //* vector 互换
//     vector <int> v1;
//     vector <int> v2;

//     for (int i = 0; i < 10; ++i) {
//         v1.push_back(i);
//         v2.push_back(i * 10);
//     }
//     print(v1);
//     print(v2);

//     v1.swap(v2);                                         //* swap 功能展示
//     print(v1);
//     print(v2);

//     vector <int> v3;
//     for (int i = 0; i < 10000; ++i) {
//         v3.push_back(i);
//     }
//     cout << v3.capacity() << " " << v3.size() << endl;

//     v3.resize(3);
//     cout << v3.capacity() << " " << v3.size() << endl;                 //! 删除了内部的内容，规模变小，但总体占用空间不变

//     vector <int> (v3).swap(v3);                                        //! 天才，先通过拷贝构造建立匿名对象，其容量就是 v3 的规模，再将匿名对象与 v3 互换，v3 的空间缩小，匿名对象将原 v3 的空间回收
//     cout << v3.capacity() << " " << v3.size() << endl;

//     return 0 ;
// }

// void print (vector<int> v) {
//     for (vector<int>::iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << *bgn <<" ";
//     cout << endl;
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void print (vector<int> v);

// int main () {                                           //*  vector 预留内存
//     vector <int> v1;
//     v1.reserve(100000);                                 //* 分配空间，但是其中的数据不会初始化为 0，所以内存不可访问(全是垃圾)

//     int num = 0;
//     int *p = NULL;
//     for (int i = 0; i < 100000; ++i) {
//         v1.push_back(i);

//         if (p != &v1[0]) {
//             p = &v1[0];
//             ++num;
//         }
//     }

//     cout << num;

//     return 0;
// }

// void print (vector<int> v) {
//     for (vector<int>::iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << *bgn <<" ";
//     cout << endl;
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void print (vector<int> v);

// int main () {

//     return 0;
// }

// void print (vector<int> v) {
//     for (vector<int>::iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << *bgn <<" ";
//     cout << endl;
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void print (vector<int> v);

// int main () {

//     return 0;
// }

// void print (vector<int> v) {
//     for (vector<int>::iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << *bgn <<" ";
//     cout << endl;
// }