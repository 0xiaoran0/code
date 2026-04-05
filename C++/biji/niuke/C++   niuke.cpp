// #include <bits/stdc++.h>                                  // 输出Hello World
// using namespace std;
// int main() {
//     cout<<"Hello World";
//     return 0;
// }




// #include <bits/stdc++.h>                                     // 输入输出
// using namespace std;
// int main () {
//     int a, b, c;

//     cin>>a >>b >>c;
//     cout<<a <<"\t" <<b <<"\t" <<c;

//     return 0;
// }



// #include <bits/stdc++.h>                                  //控制小数位数
// using namespace std;
// int main () {
//     double a = sqrt(2);

//     cout<<defaultfloat;                                   //清空之前对浮点数位数的设置
//     cout<<fixed<<setprecision(6)<<a;                      //先固定小数部分，再保留六位小数

//     return 0;
// }



// #include <bits/stdc++.h>                                    //尝试 if 语句
// using namespace std;
// int main () {
//     int a, b;
//     cin>>a>>b;

//     if (a > b) {
//         cout<<"大";
//     } else {
//         cout<<"小";
//     }

//     return 0;
// }



// #include <bits/stdc++.h>                                      //尝试 for 语句, 判断素数
// using namespace std;
// int main () {
//     int a;
//     cin>>a;

//     int i = 2, b;
//     for (; i * i < a; i++) {
//         b = 1;
//         if (a % i == 0) {
//             b = 0;
//         }
//     }

//     if (b) {
//         cout<<"YES";
//     } else {
//         cout<<"NO";
//     }

//     return 0;
// }



// #include <bits/stdc++.h>                                        //尝试 while 语句, 输出九九乘法表
// using namespace std;
// int main () {
//     int i = 1, j = 1;

//     while (i <= 9) {
//         j = 1;                                                    //初始化很重要
//         while (j <= i) {
//             cout<<i<<"*"<<j<<"="<<i*j<<"\t";
//             j++;                                                  // j++ 不要忘了
//         }
//         cout<<"\n";
//         i++;
//     }

//     return 0;
// }



// #include <bits/stdc++.h>                            //尝试数组、指针
// using namespace std;
// int main () {
//     int a[] = {1, 2, 3, 4, 5,};
//     cout<<a[1]<<endl;

//     int* i = a;
//     cout<<*(i+2)<<endl;

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;
// int main () {
//     string a;
//     cin>>a;
//     a = " " + a;                                          //垫一格可以方便不熟练下标从零开始的人

//     cout<<a[1]<<endl;                                     //访问字符串
//     cout<<a.size()<<endl;                                 //统计字符串长度

//     string b = "Hello, World!";
//     cout<<b.substr(7,5);                              //切片，取从七开始，长度为五的字符串

//     return 0;
// }




// #include <bits/stdc++.h>                           //尝试函数, 实现加法
// using namespace std;

// int add (int a, int b);

// int main () {
//     int a, b;
//     cin>>a>>b;

//     int c = add (a, b);
//     cout<<c;

//     return 0;
// }

// int add (int a, int b) {
//     return a + b;
// }



// #include <bits/stdc++.h>                       //尝试结构体
// using namespace std;

// #include <string>

// struct ST {
//     string name;
//     double ch, ma, en;
// };

// int main () {
//     ST s1;                                    //结构体的输入与访问
//     cin>>s1.ch>>s1.ma>>s1.en;
//     cout<<s1.ch<<s1.ma<<s1.en<<endl;

//     ST* s = new ST();
//     cin>>s->ch;                                //结构体指针的输入与访问
//     cout<<s->ch<<endl;

//     return 0;
// }



// #include <bits/stdc++.h>                         //通过结构体函数做加法
// #include <string>
// using namespace std;

// struct st {
//     int a, b, c, s;

//     st (int e, int f, int g) {
//         a = e;
//         b = f;
//         c = g;
//         s = a + b + c;
//     }

// };

// int main () {
//     int a1, b1, c1;
//     cin>>a1>>b1>>c1;
//     st s1(a1, b1, c1);
//     cout<<s1.s<<endl;

//     return 0;
// }



// #include <bits/stdc++.h>                               //尝试结构体符号重载，可实现逐步比较成绩
// using namespace std;

// struct st {
//     string na;
//     int ch, ma, en, tot;
//     st (string a, int b, int c, int d) {
//         na = a, ch = b, ma = c, en = d;
//         tot = b + c + d;
//     }
//     st() = default;
//     bool operator < (const st &x) const {
//         return tot < x.tot;
//     }
// }a[2000];

// int main () {
//     string an;                                        //这里不能使用变量 a ，会与数组的命名重合
//     int b, c, d;
//     int n;
//     cin>>n;
//     for (int i = 1; i <= n; i++) {
//         cin>>an>>b>>c>>d;
//         a[i] = st(an,b,c,d);
//     }
//     st top = a[1];
//     for (int i = 2; i <= n; i++) {
//         if (top < a[i]) {
//             top = a[i];
//         }
//     }

//     cout<<top.tot;

//     return 0;
// }



// #include <bits/stdc++.h>                                            //尝试序列
// using namespace std;
// int main () {
//     vector <int> a = {1, 2, 3, 4};
//     for (int i = 0; i < a.size(); i++) {
//         cout<<a[i]<<"\t";
//     }
//     cout<<endl;

//     a.push_back(3);                                                 //增加元素(在末尾)
//     for (int i = 0; i < a.size(); i++) {
//         cout<<a[i]<<"\t";
//     }
//     cout<<endl;

//     a.pop_back();                                                  //删除最后元素
//     for (int i = 0; i < a.size(); i++) {
//         cout<<a[i]<<"\t";
//     }
//     cout<<endl;

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;
// int main () {
//     vector <int> a = {2, 1, 4, 3};
//     sort(a.begin(), a.end());                                //升序排序
//     for (int i = 0; i < a.size(); i++) {
//         cout<<a[i]<<"\t";
//     }

//     vector <int> c = {2, 1, 4, 3};
//     sort(a.begin(), a.end(), greater<int>());               //多写一个参数，表示降序排列

//     vector <int> b = {2, 1, 4, 3};
//     reverse(a.begin(), a.end());                             //逻辑是先降序排序，再将其逆转


//     return 0;
// }



// #include <bits/stdc++.h>                                                       //忘记打换行符错两次，升降序搞反错一次
// using namespace std;
// int main () {
//     vector <int> a = {};
//     int i ;
//     cin >> i;
//     for (int j = 0; j < i; j++) {
//         int k;
//         cin >> k;
//         switch (k) {
//             case 1: int b1; cin >> b1; a.push_back(b1); break;
//             case 2: a.pop_back(); break;
//             case 3: int b2; cin >> b2; cout << a[b2] << endl; break;
//             case 4:
//                 int b3, c;
//                 cin >> b3 >> c;
//                 a.push_back(0);
//                 for (int d = a.size() - 1; d > b3 + 1; d--) {                    //在序列中插入元素，这里写作 b + 1 可在不影响正确性的情况下减少一次循环
//                     a[d] = a[d-1];
//                 }
//                 a[b3+1] = c; break;
//             case 5: sort(a.begin(), a.end()); break;
//             case 6: sort(a.begin(), a.end(), greater<int>()); break;
//             case 7: cout<<a.size()<<endl; break;
//             case 8:
//                 for (int b = 0; b < a.size(); b++) {
//                     cout << a[b] << " ";
//                 }
//                 cout<<endl;
//                 break;
//         }
//     }

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;
// int main () {

//     return 0;
// }