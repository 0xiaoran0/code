// #include <stdio.h>
// #include <stdlib.h>

// int atoh(const char nstr[]);

// int main () {
//     int n;
//     scanf("%d", &n);

//     // 转换数字并输出
//     for (int i = 0; i < n; ++i) {
//         char* str = malloc (sizeof(char) * 2000);
//         scanf("%s", str);
//         printf("%d", atoh(str));
//         if (i < n - 1) printf(" ");
//     }

//     return 0;
// }

// int atoh(const char nstr[]) {
//     // 得到字符串前后端，便于遍历
//     char* nstr_last = nstr;
//     char* nstr_head = nstr;
//     nstr_head += 2;
//     for (; *nstr_last; ++nstr_last);

//     // 遍历求和
//     int retuen_num = 0;
//     while (nstr_head != nstr_last) {
//         char current_ch = *nstr_head++;
//         int current_num;
//         if (current_ch >= 'a' && current_ch <= 'z') {
//             current_num = current_ch - 'a' + 10;
//         } else if (current_ch >= 'A' && current_ch <= 'Z') {
//             current_num = current_ch - 'A' + 10;
//         } else {
//             current_num = current_ch - '0';
//         }
//         // 求和
//         retuen_num = retuen_num * 16 + current_num;
//     }

//     return retuen_num;
// }