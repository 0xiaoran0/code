#include <iostream>
#include <cmath>
using namespace std;
long long nums[1000100];

int main () {
	long long q;
	cin >> q;
	
	for (long long i = 0; i < q; ++i) {
		cin >> nums[i];
	}
	
	for (long long i = 0; i < q; ++i) {
		int judge = 1;
		for (long long j = 1; j * j * 2 <= nums[i] + 5; ++j) {
			long long head = j;
			long long tail = (long long)sqrt(nums[i] + 10);
			for (long long k = (head + tail) / 2;;) {
				if (k * k + j * j == nums[i]) {
					cout << "YES" << endl;
					judge = 0;
					break;
				}
				if (head >= tail || head == k || tail == k) {
					break;
				}
				if (k * k + j * j > nums[i]) {
					tail = k;
				} else if (k * k + j * j < nums[i]) {
					head = k;
				}
				k = (head + tail) / 2;
			}
			if (judge == 0) {
				break;
			}
		}
		
		if (judge) {
			cout << "NO" << endl;
		}
	}

    return 0;
}
