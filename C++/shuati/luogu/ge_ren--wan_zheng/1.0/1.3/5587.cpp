// #include <iostream>
// #include <string>
// #include <string.h>
// using namespace std;

// struct S {
//     string s;
//     string s_;
// };

// void judge (string* s);

// int main () {
//     S str[2];
//     for (int i = 0; i < 2; ++i) {
//         getline(cin, str[i].s_);
//         while (str[i].s_ != "EOF") {
//             judge(&str[i].s_);
//             str[i].s += str[i].s_;
//             str[i].s += '\n';
//             getline(cin, str[i].s_);
//         }
//     }
    

//     int cnt = 0, i = 0, j = 0;
//     while (i < str[0].s.size() && j < str[1].s.size()) {
//         if ('#' == str[0].s[i] || '\n' == str[0].s[i]) {
//             ++i;
//             continue;
//         }
//         if ('#' == str[1].s[j] || '\n' == str[1].s[j]) {
//             ++j;
//             continue;
//         }

//         if (str[0].s[i] == str[1].s[j]) ++cnt;
//         ++i, ++j;

//         if ('\n' == str[0].s[i]) {
//             while ('\n' != str[1].s[j]) ++j;
//         } else if ('\n' == str[1].s[j]) {
//             while ('\n' != str[0].s[i]) ++i;
//         }
//     }

//     int time;
//     cin >> time;
//     cout << cnt * 60 / time << endl;

//     return 0;
// }

// void judge (string* s) {
//     int n = 0;
//     int cnt = 0;
//     int state = 0;
//     if ((*s)[0] == '<') (*s)[0] = '#';

//     for (int i = 1; (*s)[i]; ++i) {
//         n++;

//         switch (state) {
//             case 0: if ((*s)[i] == '<') {
//                         ++cnt;
//                         state = 1;
//                         (*s)[i] = '#';
//                         (*s)[i-1] = '#';
//                     }
//                     break;
//             case 1: if ((*s)[i] == '<') {
//                         ++cnt;
//                         state = 1;
//                     } else {
//                         for (int i = n - cnt - 1; cnt > 0 && i >= 0; --i, --cnt) {
//                             (*s)[i] = '#';
//                             (*s)[i + cnt] = '#';
//                         }
//                         cnt = 0;
//                         state = 0;
//                     }
//                     break;
//         }
        
//     }

//     int i = 0, j = 0;
//     while ((*s)[j]) {
//         if ('#' == (*s)[i]) {
//             if ('#' != (*s)[j]) {
//                 (*s)[i] = (*s)[j];
//                 (*s)[j] = '#';
//                 ++i, ++j;
//             } else {
//                 (*s)[j] = '#';
//                 ++j;
//             }
//         } else {
//             ++i, ++j;
//         }
//     }
// }



// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// struct S {
//     vector<string> lines; // 存储每行处理后的结果
//     string s_;
// };

// void judge (string* s);

// int main () {
//     S str[2];
//     for (int i = 0; i < 2; ++i) {
//     getline(cin, str[i].s_);
//         while (str[i].s_ != "EOF") {
//             judge(&str[i].s_); // 处理退格
//             str[i].lines.push_back(str[i].s_); // 存入当前行，不拼接
//             getline(cin, str[i].s_);
//         }
//     }
    

//     int cnt = 0;
//     int max_line = min(str[0].lines.size(), str[1].lines.size()); // 只比较到较短的行数
//     for (int k = 0; k < max_line; ++k) { // k是当前行索引
//         string& line_ref = str[0].lines[k]; // 范文第k行
//         string& line_in = str[1].lines[k]; // 输入第k行
//         int len = min(line_ref.size(), line_in.size()); // 每行只比较到较短的长度
//         for (int p = 0; p < len; ++p) { // p是当前行的字符索引
//             if (line_ref[p] == line_in[p]) {
//                 cnt++;
//             }
//         }
//     // 超出较短行长度的字符，均算错误，不统计
//     }

//     int time;
//     cin >> time;
//     cout << cnt * 60 / time << endl;

//     return 0;
// }

// void judge(string* s) {
//     for (int i = 0; (*s)[i]; ++i) {
//         if ((*s)[i] == '<') {
//             if (i > 0) {
//                 (*s).erase(i - 1, 2);
//                 i -= 2;
//             } else {
//                 (*s).erase(i, 1);
//             }
//         }
//     }
// }



#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct S {
    string s;
    string s_;
};

void judge (string* s);

int main () {
    S str[2];
    string ch;
    for (int i = 0; i < 2; ++i) {
        getline(cin, str[i].s_);
        while (str[i].s_ != "EOF") {
            judge(&str[i].s_);
            str[i].s += str[i].s_;
            str[i].s += '$';
            getline(cin, str[i].s_);
        }
    }

    int cnt = 0, i = 0, j = 0;
    while (i < str[0].s.size() && j < str[1].s.size()) {
        if ('#' == str[0].s[i]) {
            ++i;
            continue;
        }
        if ('#' == str[1].s[j]) {
            ++j;
            continue;
        }

        if ('$' == str[0].s[i]) {
            while ('$' != str[1].s[j]) ++j;
        } else if ('$' == str[1].s[j]) {
            while ('$' != str[0].s[i]) ++i;
        }

        if ('$' == str[0].s[i] &&  '$' == str[1].s[j]) {
            ++i;
            ++j;
            continue;
        }

        if (str[0].s[i] == str[1].s[j]) ++cnt;
        ++i, ++j;
    }

    int time;
    cin >> time;
    cout << cnt * 60 / time << endl;

    return 0;
}

void judge (string* s) {
    int cnt = 0;
    int state = 0;
    if ((*s).size() > 0 && (*s)[0] == '<') (*s)[0] = '#';

    for (int i = 1; i < (*s).size(); ++i) {

        switch (state) {
            case 0: if ('<' == (*s)[i]) {
                        (*s)[i] = '#';
                        (*s)[i - 1] = '#';
                        state = 1;
                        ++cnt;
                    }
                    break;
            case 1: if ('<' == (*s)[i]) {
                        (*s)[i] = '#';
                        ++cnt;
                        state = 1;
                        int temp = i - 2 * cnt + 1;
                        if (temp >= 0) (*s)[temp] = '#';
                        else (*s)[0] = '#';
                    } else {
                        cnt = 0;
                        state = 0;
                    }
                    break;
        }

    }

    // int i = 0, j = 0;
    // while (j < (*s).size()) {
    //     if ('#' == (*s)[i]) {    // 这里不排序之后也会跳过，好像没必要
    //         if ('#' != (*s)[j]) {
    //             (*s)[i] = (*s)[j];
    //             (*s)[j] = '#';
    //             ++i, ++j;
    //         } else {
    //             (*s)[j] = '#';
    //             ++j;
    //         }
    //     } else {
    //         ++i, ++j;
    //     }
    // }
}