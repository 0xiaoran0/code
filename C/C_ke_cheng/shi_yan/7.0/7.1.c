// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node{
//     int stu_num;
//     char name[20];
//     int Eng;
//     int math;
//     int phy;
//     int C;
//     double aver;
//     int sum;
//     struct node* next;
// } node;

// typedef struct {
//     node* head;
//     node* tail;
// } link;

// void my_strcpy(char* s1, char* s2);
// void input (node* head, node** tail);
// void output (node* head, node* tail);
// void change (node* head, node* tail);
// void out_aver(node* head, node* tail);
// void out_a_s(node* head, node* tail);


// int main () {
//     int fun;
//     scanf("%d", &fun);

//     link* li;
//     li->head = (node*) malloc (sizeof(node));
//     li->head -> next = li->tail = NULL;

//     void (*p[5]) (node* head, node* tail) = \
//         {input, output, change, out_aver, out_a_s};

//     while (0 != fun) {
//         p[fun-1](li->head, &li->tail);
//         scanf("%d", &fun);
//     }
        

//     return 0;
// }

// // 字符串的复制
// void my_strcpy(char* s1, char* s2) {
//     int index = 0;
//     for (; s2[index]; ++index)
//         s1[index] = s2[index];
//     // 不能忘记最后的 '\0'
//     s1[index] = '\0';
// }

// void input (node* head, node** tail) {
//     int num;
//     scanf("%d", &num);

//     for (int i = 0; i < num; ++i) {
//         node* p = (node*) malloc (sizeof(node));
//         scanf("%d %s %d %d %d %d", &p->stu_num, \
//             &p->name, &p->Eng, &p->math, &p->phy, &p->C);

//         if (!(head -> next)) {
//             head -> next = p;
//             (*tail) = p;
//         } else {
//             (*tail) -> next = p;
//             (*tail) = (*tail) -> next;
//         }
//         (*tail) -> next = NULL;
//     }

//     printf("完成了%d位同学的成绩输入\n", num);
// }

// void output (node* head, node* tail) {
//     node* p = head;
//     while (p != tail) {
//         p = p -> next;
//         printf("%d %s %d %d %d %d\n", p->stu_num, \
//             p->name, p->Eng, p->math, p->phy, p->C);
//     }
// }

// void change (node* head, node* tail) {
//     int stu_num;
//     scanf("%d", &stu_num);

//     node* p  = head;
//     int judge = 0;
//     for (; p != NULL; p = p -> next) {
//         if (p -> stu_num) {
//             judge = 1;
//             break;
//         }
//     }

//     if (judge) {
//         int cha_num;
//         scanf("%d", &cha_num);

//         if (0 == cha_num) {
//             char name[20];
//             scanf("%s", name);
//             my_strcpy(p -> name, name);
//         } else {
//             int grade;
//             scanf("%d", &grade);

//             switch (cha_num) {
//                 case 1: p -> Eng = grade; break;
//                 case 2: p -> math = grade; break;
//                 case 3: p -> phy = grade; break;
//                 case 4: p -> C = grade; break;
//             }
//         }
//         printf("%d %s %d %d %d %d\n", p->stu_num, \
//             p->name, p->Eng, p->math, p->phy, p->C);
//     }
// }

// void out_aver(node* head, node* tail) {
//     node* p = head  -> next;
//     for (; p != NULL; p = p -> next) {
//         p -> sum = p -> Eng + p -> math + p -> phy + p -> C;
//         p -> aver = p -> sum / 4.0;
//         printf("%d %s %.2lf\n", p->stu_num, p->name, p->aver);
//     }
// }

// void out_a_s(node* head, node* tail) {
//     node* p = head;
//     while (p != tail) {
//         p = p -> next;
//         printf("%d %s %d %.2lf\n", p->stu_num,\
//             p->name, p->sum, p->aver);
//     }
// }



#include <stdio.h>
#include <stdlib.h>

// 定义学生节点
typedef struct node{
    int stu_num;
    char name[20];
    int Eng;
    int math;
    int phy;
    int C;
    double aver;
    int sum;
    struct node* next;
} node;

// 定义链表结构
typedef struct {
    node* head;
    node* tail;
} link;

// 声明所需函数(字符串复制、链表的输入、输出)
void my_strcpy(char* s1, char* s2);
void input (link* li);
void output (link* li);
void change (link* li);
void out_aver(link* li);
void out_a_s(link* li);


int main () {
    int fun;
    scanf("%d", &fun);

    // 链表的初始化
    link* li = (link*) malloc (sizeof(link));
    li->head = (node*) malloc (sizeof(node));
    li->head -> next = li->tail = NULL;

    // 使用函数指针简化代码
    void (*p[5]) (link* li) = \
        {input, output, change, out_aver, out_a_s};

    //按照输入执行相应功能 
    while (0 != fun) {
        if (fun > 0 && fun < 6)
            p[fun-1](li);
        scanf("%d", &fun);
    }

    // 释放链表各个节点
    node* fr = li->head;
    while (li->head != NULL) {
        li->head = li->head -> next;
        free(fr);
        fr = li->head;
    }
    // 释放链表本身
    free(li);

    return 0;
}

// 字符串的复制
void my_strcpy(char* s1, char* s2) {
    int index = 0;
    for (; s2[index]; ++index)
        s1[index] = s2[index];
    // 不能忘记最后的 '\0'
    s1[index] = '\0';
}

void input (link* li) {
    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; ++i) {
        // 增加节点
        node* p = (node*) malloc (sizeof(node));
        scanf("%d %s %d %d %d %d", &p->stu_num, \
            &p->name, &p->Eng, &p->math, &p->phy, &p->C);

        // 分类输入
        if (!(li->head -> next)) {
            li->head -> next = p;
            li->tail = p;
        } else {
            li->tail -> next = p;
            li->tail = li->tail -> next;
        }
        // 将暂时不用的指针悬空
        li->tail -> next = NULL;
    }
    printf("完成了%d位同学的成绩输入\n", num);
}

void output (link* li) {
    // 链表的遍历
    node* p = li->head -> next;
    while (p != NULL) {
        printf("%d %s %d %d %d %d\n", p->stu_num, \
            p->name, p->Eng, p->math, p->phy, p->C);
        p = p -> next;
    }
}

void change (link* li) {
    int stu_num;
    scanf("%d", &stu_num);

    // 链表的查找
    node* p  = li->head -> next;
    int judge = 0;
    for (; p != NULL; p = p -> next) {
        if (stu_num == p -> stu_num) {
            // 标记是否找到，防止错误更改
            judge = 1;
            break;
        }
    }

    if (judge) {
        int cha_num;
        scanf("%d", &cha_num);

        // 将姓名与成绩分开讨论
        if (0 == cha_num) {
            char name[20];
            scanf("%s", name);
            my_strcpy(p -> name, name);
        } else {
            int grade;
            scanf("%d", &grade);

            switch (cha_num) {
                case 1: p -> Eng = grade; break;
                case 2: p -> math = grade; break;
                case 3: p -> phy = grade; break;
                case 4: p -> C = grade; break;
            }
        }
        printf("%d %s %d %d %d %d\n", p->stu_num, \
            p->name, p->Eng, p->math, p->phy, p->C);
    }
}

void out_aver(link* li) {
    // 遍历计算平均值，顺便统计总和
    node* p = li->head  -> next;
    for (; p != NULL; p = p -> next) {
        p -> sum = p -> Eng + p -> math + p -> phy + p -> C;
        p -> aver = p -> sum / 4.0;
        printf("%d %s %.2lf\n", p->stu_num, p->name, p->aver);
    }
}

void out_a_s(link* li) {
    // 遍历输出指定内容
    node* p = li->head -> next;
    while (p != NULL) {
        p -> sum = p -> Eng + p -> math + p -> phy + p -> C;
        p -> aver = p -> sum / 4.0;
        printf("%d %s %d %.2lf\n", p->stu_num,\
            p->name, p->sum, p->aver);
        p = p -> next;
    }
}