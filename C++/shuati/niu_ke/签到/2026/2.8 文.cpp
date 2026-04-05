#include <iostream>
#include <deque>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

double so (const string &s1, const string &s2, int t) {
    double re = 0;
    for (int i = 0; i < t; ++i) {
        if (s1[i] == s2[i]) {
            re += 100.0 / t;
        }
    }

    return re;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string ans;
    cin >> ans;

    deque <string> an;
    deque <string> na;

    for (int i = 0; i < m; ++i) {
        string te;
        cin >> te;
        na.push_back(te);
        cin >> te;
        an.push_back(te);
    }

    deque <int> id;
    double max = 0;
    for (int i = 0; i < m; ++i) {
        double re = so(ans, an[i], n);
        if (max < re) {
            max = re;
            id.clear();
            id.push_back(i);
        } else if (max == re) {
            id.push_back(i);
        }
    }

    deque <string> out;
    for (int i = 0; i < id.size(); ++i) {
        out.push_back(na[id[i]]);
    }
    sort(out.begin(), out.end());
    cout << out[0] << endl;
    printf("%.2lf", max);
    
    return 0;
}