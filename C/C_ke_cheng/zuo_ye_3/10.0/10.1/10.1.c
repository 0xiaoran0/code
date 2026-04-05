#include <stdio.h>
#include <string.h>
// 用于临时存储一行文本内容
char con[2000] = {0};

int main () {
    // 打开需要读取和写入的文件
    char* fi_in = "input.txt";
    char* fi_out = "output.txt";
    FILE* file_in = fopen (fi_in, "r");
    FILE* file_out = fopen (fi_out, "w");

    // 记录行号和结束条件
    int cnt = 1;
    char* s_cmp = "-END-";
    char line[4] = {'0', '0', 0, ' '};
    // 循环读入
    while ((fgets(con, 2000, file_in)) != NULL) {
        // 及时结束
        int iscmp = strcmp(con, s_cmp);
        if (!iscmp)
            break;
        // 判断换行
        if (cnt != 1 && iscmp)
            fputc('\n', file_out);
        // 输入行号和内容
        int n = strlen(con);
        line[2] = cnt + '0';
        fwrite(line, 1, 4, file_out);
        fwrite(con, 1, n-1, file_out);

        ++cnt;
    }

    // 关闭文件并置空指针
    fclose(file_in);
    fclose(file_out);
    file_in = file_out = NULL;

    return 0;
}