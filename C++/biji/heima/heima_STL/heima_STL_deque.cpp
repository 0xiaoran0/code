// #include <iostream>
// #include <deque>
// #include <algorithm>
// using namespace std;

// void print (const deque<int> &v);              //* 传入引用，减少开销

// int main () {                                   //* deque 构造
//     deque <int> d1;
//     for (int i = 0; i < 5; ++i) {
//         d1.push_back(i);
//     }
//     print(d1);

//     deque <int> d2 (d1.begin(), d1.end());
//     print(d2);

//     deque <int> d3 (10, 100);                 //* 10 个 100
//     print(d3);

//     deque <int> d4 (d1);                      //* 深拷贝
//     print(d4);

//     return 0;
// }

// void print (const deque<int> &v) {
//     for (deque<int>::const_iterator bgn = v.begin(); bgn != v.end(); ++bgn)   //* 为避免双端队列中的元素被修改，可用 const 修饰；const_iterator 相当于 const T*，迭代器可以修改，其指向的值不可以
//         cout << *bgn <<" ";
//     cout << endl;
// }



// #include <iostream>
// #include <deque>
// #include <algorithm>
// using namespace std;

// void print (const deque<int> &v);

// int main () {                                           //* 赋值
//     deque <int> d1;
//     for (int i = 0; i < 5; ++i) {
//         d1.push_back(i);
//     }
//     print(d1);

//     deque <int> d2;
//     d2 = d1;
//     print(d2);

//     deque <int> d3;
//     d3.assign(d1.begin(), d1.end());
//     print(d3);

//     deque <int> d4;
//     d4.assign(10, 100);
//     print(d4);

//     return 0;
// }

// void print (const deque<int> &v) {
//     for (deque<int>::const_iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << *bgn <<" ";
//     cout << endl;
// }



// #include <iostream>
// #include <deque>
// #include <algorithm>
// using namespace std;

// void print (const deque<int> &v);

// int main () {                                          //* 大小操作
//     deque <int> d1;
//     for (int i = 0; i < 5; ++i) {
//         d1.push_back(i);
//     }

//     print(d1);
//     cout << d1.empty() << endl;            //* 空为 1；非空为 0
//     cout << d1.size() << endl;

//     d1.resize(10, 3);                     //* 内存分段存储，没有容量，只有大小; 可知更改大小，扩大则填充第二个参数，默认为 0，缩小则直接删除
//     print(d1);

//     return 0;
// }

// void print (const deque<int> &v) {
//     for (deque<int>::const_iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << *bgn <<" ";
//     cout << endl;
// }



// #include <iostream>
// #include <deque>
// #include <algorithm>
// using namespace std;

// void print (const deque<int> &v);

// int main () {                         //* 插入与删除
//     deque <int> d1;
//     d1.push_back(10);                 //* 插入
//     d1.push_front(1);
//     d1.push_front(1);

//     d1.pop_back();                   //* 没有参数
//     d1.pop_front();

//     d1.insert(d1.begin(), 2, 200);       //* 第二个参数控制插入的个数，可以不写
//     // 200 200 1

//     deque <int> d2;
//     d2.push_back(4);
//     d2.push_back(3);
//     d2.push_back(2);
//     d1.insert(d1.begin(), d2.begin(), d2.end());
//     // 4 3 2 200 200 1

//     d1.erase(d1.begin() + 1);        //* 删除指定位置
//     print(d1);
//     // 4 2 200 200 1

//     d1.erase(d1.begin(), d1.end());             //* 删除区间
//     d1.clear();                                 //* 清空区间

//     return 0;
// }

// void print (const deque<int> &v) {
//     for (deque<int>::const_iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << *bgn <<" ";
//     cout << endl;
// }



// #include <iostream>
// #include <deque>
// #include <algorithm>
// using namespace std;

// void print (const deque<int> &v);

// int main () {
//     deque <int> d1;
//     for (int i = 0; i < 5; ++i) {
//         d1.push_back(i);
//     }

//     cout << d1.at(1) << endl;                     //* 访问第 i 个元素
//     cout << d1[1] << endl;
//     cout << d1.front() << endl;                   //* 第一个元素
//     cout << d1.back() << endl;                     //* 最后一个元素

//     return 0;
// }

// void print (const deque<int> &v) {
//     for (deque<int>::const_iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << *bgn <<" ";
//     cout << endl;
// }



// #include <iostream>
// #include <deque>
// #include <algorithm>
// using namespace std;

// void print (const deque<int> &v);

// int main () {
//     deque <int> d1;
//     d1.push_back(1);
//     d1.push_back(4);
//     d1.push_back(2);
//     d1.push_back(3);

//     sort(d1.begin(), d1.end());
//     print(d1);

//     return 0;
// }

// void print (const deque<int> &v) {
//     for (deque<int>::const_iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << *bgn <<" ";
//     cout << endl;
// }



#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void print (const deque<int> &v);

int main () {
    deque <int> d;
    d.resize(3);
    print(d);

    return 0;
}

void print (const deque<int> &v) {
    for (deque<int>::const_iterator bgn = v.begin(); bgn != v.end(); ++bgn)
        cout << *bgn <<" ";
    cout << endl;
}



// #include <iostream>
// #include <deque>
// #include <algorithm>
// using namespace std;

// void print (const deque<int> &v);

// int main () {

//     return 0;
// }

// void print (const deque<int> &v) {
//     for (deque<int>::const_iterator bgn = v.begin(); bgn != v.end(); ++bgn)
//         cout << *bgn <<" ";
//     cout << endl;
// }