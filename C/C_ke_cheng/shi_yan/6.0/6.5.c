#include <stdio.h>

void z_out (int* nums, int m, int n);

int main () {
    int m, n;
    scanf("%d %d", &m, &n);

    // 输入
    int nums[m][n];
    for (int x = 0; x < m; ++x) {
        for (int y = 0; y < n; ++y) {
            scanf("%d", &nums[x][y]);
        }
    }

    // 输出
    z_out (&nums[0][0], m, n);

    return 0;
}

void z_out (int* nums, int m, int n) {
    for (int i = 0; i < m * n; ++i) {
        // 上面一组代表坐标，下面一组代表移动方向
        // 把起点拓展理解为从界外向右上进入 [0, 0],避免了对原点的特殊讨论
        static int x = 0, y = 0;
        static int x_ = -1, y_ = 1;

        printf("%d", nums[x * n + y]);
        if (i < m * n - 1) printf(" ");

        // 更新坐标
        x += x_, y += y_;

        // 对越界做处理，对 y 的优先级应更高，处理右上角
        if (y < 0 || y >= n) {
            x -= x_, y -= y_;

            // 处理左下角
            if (x != m - 1) ++x;
            else ++y;

            x_ *= -1, y_ *= -1;
        }

        if (x < 0 || x >= m) {
            x -= x_, y -= y_;
            ++y;
            x_ *= -1, y_ *= -1;
        }
    }
}