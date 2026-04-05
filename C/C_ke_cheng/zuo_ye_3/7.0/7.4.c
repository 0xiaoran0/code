#include <stdio.h>
char s[2000], t[2000];

void strnCpy(char s[], const char t[], int n);

int main () {
    int n;
    scanf("%s %s %d", s, t, &n);

    strnCpy(s, t, n);
    printf("%s", s);

    return 0;
}

// 若无s、t的长短关系，应注意字符串最后的'\0'
void strnCpy(char s[], const char t[], int n) {
    for (int i = 0; i < n && t[i]; i++) {
        s[i] = t[i];
    }
}