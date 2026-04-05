#include <stdio.h>
#include <stdlib.h>  // 必须加！自带 system 函数

// 手动定义 /bin/sh 字符串，程序里就有了！
char *sh = "/bin/sh";

void success() {
    printf("You win! 栈溢出成功\n");
}

void vuln() {
    char buf[20];
    gets(buf);
}

int main() {
    vuln();
    system("echo hello world");
    return 0;
}

