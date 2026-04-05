#include <stdio.h>
int sort(int x);
void put_n (int x, FILE* file);

int main () {
    // 打开文件
    char* fi_in = "input.txt";
    char* fi_out = "output.txt";
    FILE* file_in = fopen (fi_in, "r");
    FILE* file_out = fopen (fi_out, "w");

    // 遍历得到数目
    char ch;
    int ch_n = 0;
    int wo_n = 0;
    int sen_n = 0;
    int judge = 1;
    while ((ch = getc(file_in)) != EOF) {
        if (ch != ' ' && ch != '\n') {
            ++ch_n;
            judge = 1;
        }
        if (judge && ch == ' ') {
            ++wo_n;
            judge = 0;
            continue;
        }
        if (ch == ',') {
            if (judge)
                ++wo_n;
            judge = 0;
            continue;
        }
        if (ch == '.') {
            ++sen_n;
            if (judge)
                ++wo_n;
            judge = 0;
            continue;
        }
    }

    // 准备输入的字符
    char ch_s[] = "Characters: ";
    char wo_s[] = "Words: ";
    char sen_s[] = "Sentences: ";

    // 将内容输入文件
    fputs(ch_s, file_out);
    put_n(ch_n, file_out);
    fputs("\n", file_out);
    fputs(wo_s, file_out);
    put_n(wo_n, file_out);
    fputs("\n", file_out);
    fputs(sen_s, file_out);
    put_n(sen_n, file_out);

    // 关闭文件并置空指针
    fclose(file_in);
    fclose(file_out);
    file_in = file_out = NULL;

    return 0;
}

// 用于将数字倒叙
int sort(int x) {
    int x_so = 0;
    while (x > 0) {
        int num = x % 10;
        x /= 10;
        x_so = x_so * 10 + num;
    }
    return x_so;
}

// 用于输入数字
void put_n (int x, FILE* file) {
    // 倒叙数字，便于写入文件
    x = sort(x);
    while (x > 0) {
        int num = x % 10;
        fputc(num + '0', file);
        x /= 10;
    }
}