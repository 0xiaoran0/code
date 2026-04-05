#include <iostream>
using namespace std;
int ti[1000100] = {0};

int main () {
    int n;
    cin >> n;

    int max = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ti[a] += 1;
        ti[b] += -1;
        max = (max > b ? max : b);
    }

    int sum = 0, sum_ = 0;
    for (int i = 0; i <= max+2; ++i) {
        ti[i+1] += ti[i];
        if (ti[i] > 0) {
            ++sum_;
            continue;
        } else {
            sum_ /= 2;
            sum += sum_;
            sum_ = 0;
        }
    }

    cout << sum;
    
    return 0;
}