#include <stdio.h>

// 定义结构体
typedef struct student {
int num; // 学号
char name[20]; // 姓名
int score; // 成绩
} student;

int main () {
    // 确认人数
    int n;
    scanf("%d", &n);

    student stus[n];
    student* p = &stus[n-1];

    // 输入
    for (int i = 0; i < n; ++i)
        scanf("%d %s %d", &stus[i].num,  &stus[i].name, &stus[i].score);

    // 通过数组输出
    for (int i = 0; i < n; ++i)
        printf("%d %s %d\n", stus[i].num,  stus[i].name, stus[i].score);

    // 通过指针输出
    for (int i = 0; i < n; --p, ++i)
        printf("%d %s %d\n", p -> num,  p -> name, p -> score);
    
    return 0;
}