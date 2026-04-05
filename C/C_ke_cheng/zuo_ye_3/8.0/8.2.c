#include <stdio.h>
char s[1000], s_[1000];

void strnCat (char* s_, char* s, int n);

int main () {
    int n;
    // 输入
    scanf("%s %s %d", s_, s, &n);

    // 拼接
    strnCat (s_, s, n);
    // 输出
    printf("%s", s_);

    return 0;
}

void strnCat (char* s_, char* s, int n) {
    int index;
    for (index = 0; s_[index]; ++index);

    for (int i = 0; i < n; ++i)
        s_[index++] = s[i];
    
    // 记得末尾的 '\0'
    s_[index] = '\0';
}