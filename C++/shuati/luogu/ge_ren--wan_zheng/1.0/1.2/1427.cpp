#include <iostream>
using namespace std;

int main () {
    int* nums = (int*)malloc(sizeof(int)*500);
    int* index = nums;

    int num = 1;
    cin >> num;
    while(num != 0) {
        *index++ = num;
        cin >> num;
    }

    while (index != nums) {
        cout << *--index << ' ';
    }
    
    return 0;
}