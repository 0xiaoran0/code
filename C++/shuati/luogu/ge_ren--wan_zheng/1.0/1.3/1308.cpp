// #include <iostream>
// #include <string>
// using namespace std;

// int main () {
//     int cnt = 0;
//     int n = -1;
//     int n_ = -1;

//     string s;
//     int index = 0;
//     cin >> s;
//     for (int i = 0; s[i] != '\0'; i++) {
//         if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
//     }

//     char ch;
//     int state = 0;
//     while ((ch = getchar()) != EOF) {
//         if (ch >= 'A' && ch <= 'Z') ch += 32;
//         ++n_;
        
//         if (ch < 'a' || ch > 'z') {
//             if (state == 3) {
//                 cnt++;
//                 if (n == -1) n = n_ - index - 1;
//                 index = 0;
//                 state = 0;
//             }
//             if (state == 0) state = 1;

//             if (state == 2) {
//                 state = 0;
//                 index = 0;
//             }
            
//             continue;
//         } else {
//             if (state == 3) state = 0;
//         }

//         if (state == 1 || state == 2) {

//             if (ch == s[index]) {
//                 state = 2;
//                 if (s[++index] == '\0') state = 3;
//             } else {
//                 state = 0;
//                 index = 0;
//             }
//         }
//     }

//     if (state == 3) {
//         cnt++;
//         if (n == -1) n = n_ - index;
//     }
    
//     if (cnt) {
//         cout << cnt << ' ' << n << endl;
//     } else {
//         cout << n << endl;
//     }
    
//     return 0;
// }



// #include <iostream>                   //! 修改后完好的状态机
// #include <string>
// using namespace std;

// int main () {
//     string s;
//     cin >> s;
//     getchar();
//     for (int i = 0; s[i]; ++i) {
//         if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
//     }
//     int index = 0;

//     char ch;
//     int state = 1;

//     int n = -1;
//     int n_ = 0;
//     int cnt = 0;

//     while ((ch = getchar()) != EOF) {
//         ++n_;
//         if (ch >= 'A' && ch <= 'Z') ch += 32;

//         switch (state) {
//             case 0: if (ch < 'a' || ch > 'z') {
//                         state = 1;
//                     }
//                     break;

//             case 1: if (ch == s[index]) {
//                         ++index;
//                         state = 2;
//                         if (s[index] == '\0') {
//                             state = 3;
//                         }
//                     } else if (ch < 'a' || ch > 'z') {
//                         state = 1;
//                     } else {
//                         state = 0;
//                     }
//                     break;

//             case 2: if (ch == s[index]) {
//                         ++index;
//                         state = 2;
//                         if (s[index] == '\0') {
//                             state = 3;
//                         }
//                     } else if (ch < 'a' || ch > 'z') {
//                         state = 1;
//                         index = 0;
//                     } else {
//                         state = 0;
//                         index = 0;
//                     }
//                     break;

//             case 3: if (ch < 'a' || ch > 'z') {
//                         ++cnt;
//                         if (n == -1) n = n_ - index - 1;
//                         state = 1;
//                     } else {
//                         state = 0;
//                     }
//                     index = 0;
//                     break;

//         }
//     }

//     if (state == 3) {
//         ++cnt;
//         if (n == -1) n = n_ - index;
//     }

//     if (cnt) cout << cnt << ' ' << n << endl;
//     else cout << n << endl;
    
//     return 0;
// }



#include<bits/stdc++.h>                   //! 从字符串视角写的
using namespace std;
string dan,ci,s;
int cur=-1,ans;
int main()
{
    cin>>ci;
    for(int i=0;i<ci.size();++i)ci[i]=tolower(ci[i]);
    getchar();
    getline(cin,s);                                          //! 没学过
    s+=' ';//这行很重要，关系着最后一个单词会不会扫描到
    for(int i=0;i<s.size();++i)s[i]=tolower(s[i]);
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==' '){
            if(dan==ci){
                ans++;
                if(cur==-1)cur=i-ci.size();
            }
            dan="";
        }
        else dan+=s[i];
    }
    if(ans==0)printf("-1");
    else printf("%d %d",ans,cur);
    return 0;
}