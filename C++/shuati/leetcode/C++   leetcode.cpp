#include <bits/stdc++.h>
using namespace std;

double* convertTemperature(double celsius, int* returnSize) {
    returnSize[0] = celsius + 273.15;
    returnSize[1] = celsius * 1.80 + 32.20;
}

int main () {
    double a;
    cin>>a;
    int ans[2];
    convertTemperature(a, &ans[0]);
    cout<<defaultfloat;
    cout<<fixed<<setprecision(6)<<"["<<ans[0]<<","<<ans[1]<<"]";

    return 0;
}