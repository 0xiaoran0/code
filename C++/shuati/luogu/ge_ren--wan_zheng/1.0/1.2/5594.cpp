#include <iostream>
using namespace std;
int day[1001][1001];

int main () {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            day[a-1][j+1] = 1;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            if (day[i][j+1] == 1) {
                day[i][0]++;
            }
        }
        cout << day[i][0] << ' ';
    }
    
    return 0;
}