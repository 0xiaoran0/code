// 继承自7-06，递归改为循环
#include <stdio.h>
#include <stdlib.h>
// dir作为方向向量，change 为矩阵，用于将 dir 顺时针旋转90度
int dir[2] = {0, 1};
int change[2][2] = {{0, 1}, {-1, 0}};
int count_num = 0;

// 用于“回”型输出
void out (int nums[][4], int bo[][4], int m);

// 用于旋转方向向量 dir
void change_dir (int a[], int b[][2]);

// 用于改变x、y，继续循环
void re_x_y (int* x, int *y);

int main () {
    int m;
    scanf("%d", &m);

    // nums用于存储，bo用于对遍历过的元素进行标记
    int nums[m][4];
    int bo[m][4];

    // 输入数字及重置数组 bo
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &nums[i][j]);
            bo[i][j] = 0;
        }
    }
    out(nums, bo, m);

    return 0;
}

void out (int nums[][4], int bo[][4], int m) {
    static int x = 0, y = 0;
    while (count_num < 4 * m) {
        printf("%d", nums[x][y]);
        ++count_num;
        // 判断输出格式和结束条件
        if (count_num < 4 * m) printf(" ");

        bo[x][y] = 1;
        re_x_y (&x, &y);
        // 判断转向条件
        if (bo[x][y] || x > m || x < 0 || y > 3 || y < 0) {
            x -= dir[0];
            y -= dir[1];
            change_dir(dir, change);
            re_x_y (&x, &y);
        }
    }
}

// 矩阵的乘法，实现顺时针旋转方向向量
void change_dir (int dir[], int change[][2]) {
    int dir0 = dir[0];
    dir[0] = dir[0] * change[0][0] + dir[1] * change[0][1];
    dir[1] = dir0 * change[1][0] + dir[1] * change[1][1];
}

// 用于改变 x、y
void re_x_y (int* x, int *y) {
    *x += dir[0];
    *y += dir[1];
}