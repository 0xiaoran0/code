#include <iostream>
using namespace std;

int w(long long a, long long b, long long c);
int w_num[21][21][21] = {0};

int main () {
    long long a, b, c;
    int judge = 0, cnt = 0;
    while (3 == (scanf("%lld %lld %lld", &a, &b, &c))) {
        ++cnt;

        if (-1 == a && -1 == b && -1 == c)
            judge = 1;

        if (judge)
            break;
        else if (!judge && cnt != 1)
            printf("\n");

        printf("w(%lld, %lld, %lld) = %d", a, b, c, w(a, b, c));
    }
    
    return 0;
}

int w(long long a, long long b, long long c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    if (a < b && b < c) {
        if (0 == w_num[a][b][c-1])
            w_num[a][b][c-1] = w(a, b, c-1);
        if (0 == w_num[a][b-1][c-1])
            w_num[a][b-1][c-1] = w(a, b-1, c-1);
        if (0 == w_num[a][b-1][c])
            w_num[a][b-1][c] = w(a, b-1, c);

        return w_num[a][b][c-1] + w_num[a][b-1][c-1] - w_num[a][b-1][c];
    } else {
        if (0 == w_num[a-1][b][c])
            w_num[a-1][b][c] = w(a-1, b, c);
        if (0 == w_num[a-1][b-1][c])
            w_num[a-1][b-1][c] = w(a-1, b-1, c);
        if (0 == w_num[a-1][b][c-1])
            w_num[a-1][b][c-1] = w(a-1, b, c-1);
        if (0 == w_num[a-1][b-1][c-1])
            w_num[a-1][b-1][c-1] = w(a-1, b-1, c-1);

        return w_num[a-1][b][c] + w_num[a-1][b-1][c] + w_num[a-1][b][c-1] - w_num[a-1][b-1][c-1];
    }
}