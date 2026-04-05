#include <stdio.h>
void strcate(char t[], const char s[]);
void strdelc(char s[], char c);
char s[2000];
char t[2000];

int main () {
    char ch;
    char input;

    // 输入t
    int index = 0;
    while ((ch = getchar()) != '\n')
        t[index++] = ch;
    t[index] = '\0';

    // 输入s
    index = 0;
    while ((ch = getchar()) != '\n')
        s[index++] = ch;
    s[index] = '\0';
    scanf("%c", &ch);

    strcate (t, s);
    strdelc (s, ch);

    return 0;
}

void strcate(char t[], const char s[]) {
    int len = 0;
    for (; t[len]; ++len);

    // 直接复制
    int index = 0;
    while (s[index])
        t[len++] = s[index++];

    t[len] = '\0';
    printf("%s\n", t);
}

void strdelc(char s[], char c) {
    // 双下标替换
    int index = 0, index_ = 0;
    while (s[index_]) {
        if (c == s[index_]) {
            ++index_;
            continue;
        } else {
            s[index++] = s[index_++];
            continue;
        }
    }
    s[index] = '\0';
    printf("%s", s);
}