#include <iostream>
using namespace std;

int main () {
    int ans[5][5] = {{0, -1, 1, 1, -1},\
                    {1, 0, -1, 1, -1},\
                    {-1, 1, 0, -1, 1},\
                    {-1, -1, 1, 0, 1},\
                    {1, 1, -1, -1, 0}};

    int n, n_a, n_b;
    cin >> n >> n_a >> n_b;

    int na[n_a];
    int nb[n_b];
    for (int i = 0; i < n_a; ++i)
        cin >> na[i];
    for (int i = 0; i < n_b; ++i)
        cin >> nb[i];

    int index_a = 0;
    int index_b = 0;
    int a_cnt = 0;
    int b_cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x = na[index_a];
        int y = nb[index_b];
        if (1 == ans[x][y])
            ++a_cnt;
        if (-1 == ans[x][y])
            ++b_cnt;
        index_a = (index_a + 1) % n_a;
        index_b = (index_b + 1) % n_b;
    }

    cout << a_cnt << " " << b_cnt;
    
    return 0;
}