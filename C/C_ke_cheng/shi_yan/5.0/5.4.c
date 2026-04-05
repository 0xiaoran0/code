#include <stdio.h>
#define row 2
int seats[row][2];

void judge_seat (int k, int* seat_num);

int main () {
    int loop_count;
    scanf("%d", &loop_count);

    // 第一个元素用于存放这一排剩余座位数
    // 第二个用于存储从第几个座位开始是空的
    for (int i = 0; i < row; ++i) {
        seats[i][0] = 5;
        seats[i][1] = 0;
    }

    for (int i = 0; i < loop_count; ++i) {
        int seat_num;
        scanf("%d", &seat_num);

        // 遍历判断能否连续坐下
        for (int k = 0; k < row; ++k) {

            if (seat_num <= seats[k][0]) {
                judge_seat (k, &seat_num);
                break;
            }
        }

        while (seat_num) {
            // 若不能连续坐下，则开始遍历空座位
            for (int k = 0; k < row; ++k) {

                if (seats[k][0]) {
                    judge_seat (k, &seat_num);
                    // 遍历至全部坐下
                    if (!seat_num) break;
                }
            }
        }
    }

    return 0;
}

// 遍历座位，通过一些协调，使它既可以适配连续座位，也可以适配离散座位
void judge_seat (int k, int* seat_num) {
    int j;
    // 输出座位号
    for (j = 0; j < *seat_num && seats[k][1] + j < 5; ++j) {
        // F座需要单独判断
        if (4 == seats[k][1] + j) printf("%dF", k + 1);
        else printf("%d%c", k + 1, seats[k][1] + j + 'A');
        //判断输出格式
        if (j < *seat_num - 1) printf(" ");
        else printf("\n");
    }
    // 更新数据
    seats[k][0] -= *seat_num;
    seats[k][1] += *seat_num;
    *seat_num -= j;
}



// #include<stdio.h>
// #define row 20
// int main(){
// 	int n;
// 	scanf("%d",&n);
// 	int arr[row];
// 	arr[0] = 0;
// 	for(int i = 1;i <= row-1;i++){
// 		arr[i] = 5;
// 	}
// 	char alphabet[6] = {'0','F','D','C','B','A'};
// 	int ticket[n];
// 	for(int i = 0;i<n;i++){
// 		scanf("%d",&ticket[i]);
// 	}
// 	for(int i = 0;i<n;i++){
// 		int judge = 0;
// 		for(int j = 1;j<=row-1;j++){
// 			if(arr[j] >= ticket[i]){
// 				for(int t = arr[j],k = 0;k<ticket[i];k++,t--){
// 					printf("%d%c ",j,alphabet[t]);
// 				}
// 				arr[j] -= ticket[i];
// 				judge = 1;
// 				break;
// 				}
// 			}
// 			if(!judge){
// 				int sum = 0;
// 				for(int j = 1;sum <ticket[i];j++){
// 					if(arr[j] > ticket[i]-sum){
// 						for(int t = arr[j],k = 0;k < ticket[i] - sum;k++){
// 							printf("%d%c ",j,alphabet[t]);
// 						}
// 						arr[j] -= (ticket[i] - sum);
// 						sum = ticket[i];
// 						judge = 1;
// 						break;
// 					}
// 					if(arr[j] <= ticket[i] - sum){
// 						sum += arr[j];
// 						for(int t = arr[j];t > 0;t--){
// 							printf("%d%c ",j,alphabet[t]);
// 						}
// 						arr[j] = 0;
// 					}
// 				}
// 			}
// 			printf("\n");
// 		}
// 	return 0;
// }