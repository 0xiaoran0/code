// #include <iostream>
// #include <string>
// using namespace std;

// int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// struct st {
//     int y;
//     int m;
//     int d;
// };

// st fun (int x) {
//     st s;
//     s.y = x / 10000;
//     s.m = x / 100 % 100;
//     s.d = x % 100;
//     return s;
// };

// int main () {
//     int a, b;
//     cin >> a >> b;
//     int cnt = 0;

//     st a1 = fun(a);
//     st b1 = fun(b);

//     for (int year = a1.y; year <= b1.y; ++year) {
//         if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
//             days[1] = 29;
//         }
//         static int month = a1.m;
//         static int day = a1.d;

//         while (month <= 12) {

//             while (day <= days[month-1]) {
//                 string s = to_string(year*10000 + month*100 + day);

//                 int judge = 1;

//                 for (int i = 0; i < 4; ++i) {

//                     if (s[i] != s[7-i]) judge = 0;
//                 }

//                 if (judge) ++cnt;

//                 ++day;
//                 if (year == b1.y && month == b1.m && day > b1.d) break;
//             }
//             day = 1;
//             ++month;
//             if (year == b1.y && month > b1.m) break;
//         }

//         month = 1;
//     }

//     cout << cnt << endl;
    
//     return 0;
// }



// https://www.luogu.com.cn/problem/solution/P2010  「QQ红包」
#include<iostream>                       //! 天才
using namespace std;
int i,j,n,m,a,b,c,sum,ans;
int s[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=12;i++)//枚举月和日 
        for (j=1;j<=s[i];j++)
        {
            c=(j%10)*1000+
              (j/10)*100+
              (i%10)*10+
              (i/10);//算出前四位。
            sum=c*10000+i*100+j;//算出整个日期 
            if (sum<n||sum>m) continue;
            ans++;//统计 
        }
    printf("%d",ans);
    return 0;
}