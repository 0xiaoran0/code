// #include <iostream>
// using namespace std;

// int main () {
//     int n;
//     cin >> n;
//     int* nums = (int*)malloc(sizeof(int) * n);

//     for (int i = 0; i < n; i++) {
//         int num;
//         cin >> num;
//         nums[i] = num;
//     }

//     int length = n * (n-1) / 2;
//     int index = 0;
//     int* plus = (int*)malloc(sizeof(int) * length);
//     for (int i = 0; i < n; i++) {
//         for (int j = i+1; j < n; j++) {
//             if (nums[i] != nums[j]) {
//                 int pl  = nums[i] + nums[j];
//                 plus[index++] = pl;
//             }
//         }
//     }

//     int cnt = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < length; j++) {
//             if (nums[i] == plus[j]) cnt++;
//         }
//     }

//     cout << cnt << endl;

//     return 0;
// }

//     for (int i = length; i > 0; i--) {
//         for (int j = 0; j < i; j++) {
//             if (nums[j] > nums[j+1]) {
//                 int temp = nums[j];
//                 nums[j] = nums[j+1];
//                 nums[j+1] = temp;
//             }
//         }
//     }



#include <iostream>
using namespace std;
int nums[100];
int pl[20006];

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];

        for (int j = 0; j < i; j++) {
            pl[nums[i] + nums[j]] = 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (pl[nums[i]] == 1);
    }
    cout << cnt << endl;

    return 0;
}