#include <iostream>
using namespace std;

signed main() {
    long long a1, a2, n, d;
    scanf("%lld %lld %lld", &a1, &a2, &n);
    d = a2 - a1;

    printf("%lld", n * a1 + n * (n - 1) * d / 2);

    return 0;
}
