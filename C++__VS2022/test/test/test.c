//#include <stdio.h>
//
//int main(void) {                            //* %s 输入字符串会自动添加隐含的 0 ，这一元素可能会被挤到相邻数组第 0 位，导致相邻数组无法输出
//    char a[2];
//    char b[2];
//    scanf_s("%s%s", &a, 2, &b, 2);
//    printf("%s\n%s\n", a, b);
//
//    printf("%c\n", a[0]);
//    printf("%c\n", a[1]);
//
//    char* p1 = a;
//    char* p2 = b;
//    printf("%zu\t%zu\n", p1, p2);            //* %zu 用于指针
//
//    return 0;
//}