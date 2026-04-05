#include <stdio.h>
#include <stdlib.h>

char *sh = "/bin/sh";

void vuln() {
    char buf[32];
    gets(buf);
}

int main() {
    system("echo hello");
    vuln();
    return 0;
}
