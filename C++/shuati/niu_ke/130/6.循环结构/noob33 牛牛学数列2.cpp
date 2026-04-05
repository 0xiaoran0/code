#include <iostream>
#define endl '\n'
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    double sum = 0.0;
    for (int i = 1; i < (n + 1); ++i) {
        sum += 1.0 / i;
    }

    printf("%.10lf", sum);
    
    return 0;
}