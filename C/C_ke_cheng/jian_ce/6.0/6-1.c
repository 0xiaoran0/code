#include <stdio.h>
char t[1000] = {0};
char s[1000];

char *strcopy(char *t, const char *s);
char *strreverse(char *s);

int main () {
    char ch;
    int index = 0;

    while ((ch = getchar()) != EOF) {
        s[index++] = ch;
    }
    s[index] = 0;

    strcopy(t, s);
    strreverse(t);

    return 0;
}

char *strcopy(char *t, const char *s) {
    int in_t = 0;
    for (; t[in_t]; ++in_t);

    // 直接添加
    int in_s = 0;
    while (s[in_s]) {
        t[in_t++] = s[in_s++];
    }
    // 末尾补 0 
    t[in_t] = 0;
    printf("拷贝结果: %s\n", t);

    return t;
}

char *strreverse(char *s) {
    int head = 0;
    int tail = 0;
    // 得到末尾
    for (; s[tail]; ++tail);
    tail -= 1;
    // 换位
    while (head < tail) {
        char temp = s[head];
        s[head] = s[tail];
        s[tail] = temp;
        ++head;
        --tail;
    }
    printf("逆向结果: %s", s);
    return s;
}