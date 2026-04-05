#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 体现封装思想
typedef struct {
    char name[20];
    int grade;
}students;

void creat (int* num, students** stu);
void sort (int num, students* stu);
void out (int num, students* stu);
void find (int find_gra, int num, students* stu);

int main () {
    // 存储功能代号与学生人数
    int choice, num;
    scanf("%d", &choice);
    students* stu;

    while (choice) {
        switch (choice) {
            case 1: creat (&num, &stu);
                    break;

            case 2: sort (num, stu);
                    break;

            case 3: out (num, stu);
                    break;

            case 4: int find_gra;
                    scanf("%d", &find_gra);
                    find (find_gra, num, stu);
                    break;
        }
        scanf("%d", &choice);
        if (0 == choice)
            free(stu);
    }

    return 0;
}

void creat (int* num, students** stu) {
    scanf("%d", num);
    // 申请内存
    *stu = (students*) malloc (sizeof(students)*(*num));
    for (int i = 0; i < *num; ++i) {
        scanf("%s %d", (*stu)[i].name, &(*stu)[i].grade);
    }
    printf("%d records were input!\n", *num);
}

void sort (int num, students* stu) {
    // 冒泡排序
    for (int i = 0; i < num; ++i) {
        for (int j = num - 1; j > i; --j) {
            if (stu[j].grade > stu[j - 1].grade) {
                char temp_name[20];
                strcpy(temp_name, stu[j].name);
                strcpy(stu[j].name, stu[j - 1].name);
                strcpy(stu[j - 1].name, temp_name);
                int temp_grade = stu[j].grade;
                stu[j].grade = stu[j - 1].grade;
                stu[j - 1].grade = temp_grade;
            }
        }
    }
    printf("Reorder finished!\n");
}

void out (int num, students* stu) {
    for (int i = 0; i < num; ++i) {
        printf("%s %d\n", stu[i].name, stu[i].grade);
    }
}

void find (int find_gra, int num, students* stu) {
    // 二分查找的起始于结束
    int min = 0;
    int max = num - 1;
    int judgement = 0;
    while (min <= max) {
        int middle = (min + max) / 2;
        // 标记退出的时机
        int judge_exit = 0;
        if (min == max) judge_exit = 1;
        if (find_gra < stu[middle].grade) {
            min = middle + 1;
        } else if (find_gra > stu[middle].grade) {
            max = middle - 1;
        } else if (find_gra == stu[middle].grade) {
            printf("%s %d\n", stu[middle].name, stu[middle].grade);
            judgement = 1;
            break;
        }
        if (1 == judge_exit) break;
    }
    if (0 == judgement) printf("not found!\n");
}



// #include <stdio.h>           //* 帮忙改的代码
// #include <string.h>
// int main(){
//     int n;
//     char name[10][10];
//     int score[100];
//     scanf("%d", &n);
//     for(int h = 0; h < n; h++){
//         scanf("%s %d", name[h], &score[h]);
//     }
//     printf("%d records were input!", n);

//     for(int i = (n-1); i >= 0; i--){
//         for(int j = (n-1); j >= n-i-1; j--){
//             if(score[j] > score[j-1]){
//                 int temp;
//                 temp = score[j];
//                 score[j] = score[j-1];
//                 score[j-1] = temp;
//                 char Temp[10];
//                 strcpy(name[j], Temp);
//                 strcpy(name[j-1], name[j]);
//                 strcpy(Temp, name[j-1]);
//             }
//         }
//     }

//     for(int k = 0; k < n; k++){
//         printf("%s %d\n", name[k], score[k]);
//     }

//     int target;
//     scanf("%d", &target);
//     for(int l = 0; l < n; l++){
//         if(score[l] == target){
//             printf("%s %d", name[l], score[l]);
//         }
//     }
//     return 0;
// }