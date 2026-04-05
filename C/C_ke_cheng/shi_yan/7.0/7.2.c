#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct node {
    int num;
    struct node* next;
} node;

int main () {
    int N, M;
    scanf("%d %d", &N, &M);

    // 进行链表的初始化
    node* head = (node*) malloc (sizeof(node));
    head -> next = NULL;
    node* index = head;

    // 通过下标移动构建链表
    for (int i = 0; i < N; ++i) {
        node* p = (node*) malloc (sizeof(node));
        p -> num = i + 1;
        index -> next = p;
        index = index -> next;
        index -> next = NULL;
    }

    // 实现链表闭环
    index -> next = head -> next;
    // 记录遍历时的上一个节点，用于删除
    node* last = index;
    index = index -> next;

    // 循环删除，结束条件为只剩余一个节点
    while (index != index -> next) {
        for (int i = 0; i < M-1; ++i) {
            last = index;
            index = index -> next;
        }

        printf("%d", index -> num);

        // 节点的删除
        node* p = index;
        index = index -> next;
        last -> next = p -> next;
        free(p);

        if (index != index -> next)
            printf(" ");
        else
            printf("\n");
    }
    printf("%d", index -> num);
    // 释放该释放的内存
    free(index);
    free(head);

    return 0;
}