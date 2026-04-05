#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int n_ = n;

    int x;
    int judge = 0;
    for (x = 1; x < 11; ++x) {
        n_ *= x;
        if (0 == n_ % 10){
            judge = 1;
            break;
        } else {
            n_ = n;
        }
    }

    if (judge)
        cout << x;
    else
        cout << "10";
    
    return 0;
}