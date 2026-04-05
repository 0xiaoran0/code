#include <stdio.h>

int del_out (char* str[], char s[]);

int main(void) {
    int cnt;
    scanf("%d", &cnt);
    // 读入换行，避免影响
    getchar();

    for (int i = 0; i < cnt; ++i) {
        char s[81];
        char* str[81];
        // 数行读取字符串，并用指针一一对应
        fgets (s, 81, stdin);
        for (int j = 0; '\n' != s[j];) {
            str[j] = &s[j];
            if ('\n' == s[++j]) str[j] = &s[j];
        }
        int index = del_out (str, s);
        for (int k = 0; k < index; ++k) {
            printf("%c", s[k]);
        }
        if (i < cnt - 1) printf("\n");
    }

    return 0;
}

int del_out (char* str[], char s[]) {
    int state = 0;
    int index = 0;
    for (int i = 0;'\n' != *str[i]; ++i) {
        // 使用状态机处理，先删除行首，再删空格
        switch (state) {
            case 0: if (' ' == *str[i] || '\t' == *str[i]) {
                        break;
                    } else {
                        s[index++] = *str[i];
                        state = 1;
                    }
                    break;

            case 1: if (' ' == *str[i]) state = 2;
                    s[index++] = *str[i];
                    break;

            case 2: if (' ' == *str[i]) {
                        break;
                    } else {
                        s[index++] = *str[i];
                        state = 1;
                    }
                    break;
        }
    }
    return index;
}



// #include <stdio.h>

// int del_out (char* str[], char s[]);

// int main(void) {
//     int cnt;
//     scanf("%d", &cnt);
//     // 读入换行，避免影响
//     getchar();

//     for (int i = 0; i < cnt; ++i) {
//         char s[81];
//         char* str[81];
//         // 数行读取字符串，并用指针一一对应
//         fgets (s, 81, stdin);
//         for (int j = 0; '\n' != s[j];) {
//             str[j] = &s[j];
//             if ('\n' == s[++j]) str[j] = &s[j];
//         }

//         int index = del_out (str, s);
//         printf("%s", s);

//         if (i < cnt - 1) printf("\n");
//     }

//     return 0;
// }

// int del_out (char* str[], char s[]) {
//     int state = 0;
//     int index = 0;
//     for (int i = 0;'\n' != *str[i]; ++i) {
//         // 使用状态机处理，先删除行首，再删空格
//         switch (state) {
//             case 0: if (' ' == *str[i] || '\t' == *str[i]) {
//                         break;
//                     } else {
//                         s[index++] = *str[i];
//                         state = 1;
//                     }
//                     break;

//             case 1: if (' ' == *str[i]) state = 2;
//                     s[index++] = *str[i];
//                     break;

//             case 2: if (' ' == *str[i]) {
//                         break;
//                     } else {
//                         s[index++] = *str[i];
//                         state = 1;
//                     }
//                     break;
//         }
//     }

//     s[index] = '\0';
//     return index;
// }