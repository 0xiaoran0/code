#include <iostream>
using namespace std;

int main () {                                 // 小心第一个正数不需要 "+"，小心 0 项要不要输出，小心一次项
    int n;
    cin >> n;
    // 标记是否只有常数项
    int cnt = 0;
    // 标记第一个非零项在哪里
    int isfirst = 0;

    for (int i = n; i > 0; --i) {
        int num;
        cin >> num;
        if (0 == num)
            continue;

        cnt = 1;
        // 处理正数
        if (num > 0) {
            if (isfirst)
                cout << "+";
            if (1 != num)
                cout << num;
        }
        // 处理负数
        if (num < 0) {
            num *= -1;
            if (1 == num)
                cout << "-";
            else
                cout << "-" << num;
        }
        // 处理一次项
        if (i == 1)
            cout << "x";
        else
            cout << "x^" << i;
        isfirst = 1;
    }
    // 处理常数项
    int num;
    cin >> num;
    if (cnt && num > 0)
        cout << "+" << num;
    if (!cnt && num > 0 || !cnt && num == 0 || num < 0)
        cout << num;
    
    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n; scanf("%d",&n);
// 	for(int i=n;i>=0;i--){
// 		int a; scanf("%d",&a);
// 		if(!a)continue;//系数为0直接跳过
// 		if(a>0&&i!=n)putchar('+');//第一步
// 		if(a<0)putchar('-');
		
// 		if(abs(a)!=1||!i)printf("%d",abs(a));//第二步
		
// 		if(i){//第三步
// 			putchar('x');
// 			if(i!=1)printf("^%d",i);
// 		}
// 	}
// 	return 0;
// }