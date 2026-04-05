#include <stdio.h>

void task0 ();
void task1 ();
void task2 ();
void task3 ();
void task4 ();
void task5 ();
void task6 ();
void task7 ();

void scheduler (char ch, void (*p[8]) ());
void execute(int choose, void (*p[8]) ());

int main () {
    // 函数指针数组
    void (*p[8]) () = {task0, task1, task2, task3, task4, task5, task6, task7};
    char ch;
    ch = getchar();

    // 输入数字，调用函数
    while (ch != EOF) {
        scheduler (ch, p);
        ch = getchar();
    }

    return 0;
}

void task0 () {
    printf("task0 is called!\n");
}
void task1 () {
    printf("task1 is called!\n");
}
void task2 () {
    printf("task2 is called!\n");
}
void task3 () {
    printf("task3 is called!\n");
}
void task4 () {
    printf("task4 is called!\n");
}
void task5 () {
    printf("task5 is called!\n");
}
void task6 () {
    printf("task6 is called!\n");
}
void task7 () {
    printf("task7 is called!\n");
}

void scheduler (char ch, void (*p[8]) ()) {
    for (int i = 0; i < 8; ++i) {
        if (ch == i + '0') {
            // 将要调用的函数下标传给 execute
            execute (i, p);
        }
    }
}

// 调用
void execute(int choose, void (*p[8]) ()) {
    p[choose]();
}