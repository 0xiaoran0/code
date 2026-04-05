#include <stdio.h>
void strcate(char [], char []);
void strdelc(char [], char );
int main(void)
{
    // 修改点：扩大b数组的存储空间，避免缓冲区溢出
    char a[] = "Language", b[30] = "Programming";
    printf("%s %s\n", b, a);
    strcate(b, a);
    printf("%s %s\n", b, a);
    strdelc(b, 'a');
    printf("%s\n", b);
    return 0;
}
void strcate(char t[], char s[])
{
    int i = 0,  j = 0;
    // 修改点：修正while循环逻辑，使i停在t的'\0'位置
    while (t[i] != '\0') i++;
    while ((t[i++] = s[j++]) != '\0');
}
void strdelc(char s[], char c)
{
    int j, k;
    for (j = k = 0; s[j] != '\0'; j++)
        if (s[j] != c)
            s[k++] = s[j];
    // 修改点：添加字符串结束符，标识删除后的字符串结尾
    s[k] = '\0';
}
