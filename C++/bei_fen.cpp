#include <iostream>
using namespace std;

int main () {
    
    return 0;
}



#include <iostream>
#define endl '\n'
typedef long long ll;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}



#include <iostream>
#include <list>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list <int> l;
    l.insert(l.begin(), 1);
    l.insert(l.begin(), 2);
    
    return 0;
}



#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}



const int MOD = 1e9+7;
long long pow_mod(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}