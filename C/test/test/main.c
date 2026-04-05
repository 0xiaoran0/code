#include "sub.h"  // 关键：通过头文件引入函数声明，编译器才能识别printHello()

int main() {
    printHello();  // 调用sub.c中实现的函数
    return 0;
}