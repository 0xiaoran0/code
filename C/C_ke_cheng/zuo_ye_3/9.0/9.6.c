#include <stdio.h>
#include <stdlib.h>

// 定义节点
typedef struct node {
    char ch;
    struct node* next;
} node;

int main() {
    // 初始化链表
    node* head = (node*) malloc (sizeof(node));
    head -> next = NULL;
    node* index = head;

    // 遍历输入
    int ch;
    while ((ch = getchar()) != '\n') {
        node* p = (node*) malloc (sizeof(node));
        p -> ch = ch;
        index -> next = p;
        index = index -> next;
    }
    // 不用循环链表了，用线性链表
    index -> next = NULL;
    node* last = head;
    index = head -> next;

    // 读入目标字符，遍历删除，同时输出
    scanf("%c", &ch);
    while (index != NULL) {

        if (index -> ch == ch) {
            // 执行删除操作并释放内存
            node* p = index;
            index = index -> next;
            last -> next = index;
            free(p);
            continue;
        } else {
            // 不相同则执行输出操作
            printf("%c", index -> ch);
            last = index;
            index = index -> next;
        }
    }

    // 遍历释放内存
    index = head -> next;
    last = head;
    while (index != NULL) {
        free(last);
        last = index;
        index = index -> next;
    }
    // 释放内存并置空
    free(last);
    last = NULL;

    return 0;
}