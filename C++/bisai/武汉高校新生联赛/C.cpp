#include <iostream>
using namespace std;
long long num[501000][4];

int main () {
	long long n, cnt;
	string s;
	cin >> n >> cnt;
	if (n) {
		cin >> s;
	}
	
	for (long long i = 0; i < cnt; ++i) {
		cin >> num[i][0] >> num[i][1] >> num[i][2] >> num[i][3];
	}
	
	for (long long j = 0; j < cnt; ++j) {
		long long x = 0, y = 0;
		int judge = 1;
		
		for (long long i = 0; i < n; ++i) {
			if (i >= (num[j][0]-1) && i <= (num[j][1]-1)) {
				continue;
			}
			if (x == num[j][2] && y == num[j][3]) {
				cout << "YES" << endl;
				judge = 0;
				break;
			}
			if (s[i] == 'L') {
				x -= 1;
			} else if (s[i] == 'R') {
				x += 1;
			} else if (s[i] == 'U') {
				y += 1;
			} else if (s[i] == 'D') {
				y -= 1;
			}
			if (x == num[j][2] && y == num[j][3]) {
				cout << "YES" << endl;
				judge = 0;
				break;
			}
		}
		
		if (judge) {
			if (x == num[j][2] && y == num[j][3]) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;	
			}
		}
	}

    return 0;
}
