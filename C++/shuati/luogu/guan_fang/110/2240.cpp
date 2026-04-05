#include <iostream>
using namespace std;

int main () {
    double n[150][2] = {0.0};
    double n_[150] = {0.0};
    int N;
    double t;
    cin >> N >> t;

    for (int i = 0; i < N; ++i) {
        cin >> n[i][0] >> n[i][1];
        n_[i] = 1.0 * n[i][1] / n[i][0];
    }

    for (int i = N-1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (n_[j] > n_[j+1]) {
                swap (n_[j], n_[j+1]);
                swap (n[j][1], n[j+1][1]);
                swap (n[j][0], n[j+1][0]);
            }
        }
    }

    double sum = 0.0;
    for (int i = N-1; i >= 0; --i) {
        if(t - n[i][0]>-0.000001) {
            t -= n[i][0];
            sum += n[i][1];
        } else {
            sum += 1.0 * t * n[i][1] / n[i][0];
            break;
        }
    }

    printf("%.2f", sum);
    
    return 0;
}