#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int mnh = n % 100;

    if (mnh >= 3 && mnh <= 5)
        cout << "spring";
    if (mnh >= 6 && mnh <= 8)
        cout << "summer";
    if (mnh >= 9 && mnh <= 11)
        cout << "autumn";
    if (mnh >= 12 || mnh <= 2)
        cout << "winter";
    
    return 0;
}