#include <stdio.h>
#include <stdlib.h>

typedef struct s_list{
    int data; /* 数据域 */
    struct s_list* next; /* 指针域 */
} s_list;

int main(void) {
    // 指针置空
    s_list* head = NULL;
    int num;

    // 读取数据
    while (1 == (scanf("%d", &num))) {
        s_list* p = (s_list*) malloc (sizeof(s_list));
        p -> data = num;
        p -> next = head;
        head = p;
    }

    // 输出，同时释放内存
    s_list* pre = head;
    while (head != NULL) {
        printf("%d->", head -> data);
        head = head -> next;
        free(pre);
        pre = head;
    }
    printf("NULL");

    return 0;
}