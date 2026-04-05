#include <stdio.h>
#include <stdlib.h>

// 定义节点
typedef struct node {
    char ch;
    struct node* next;
} node;

int main () {
    // 初始化链表
    node* head = (node*) malloc (sizeof(node));
    head -> next = NULL;
    node* index = head;

    // 遍历输出
    int ch;
    while ((ch = getchar()) != EOF) {
        node* p = (node*) malloc (sizeof(node));
        p -> ch = ch;
        index -> next = p;
        index = index -> next;
    }
    // 构造成环，便于后续遍历
    index -> next = head -> next;
    index = index -> next;

    int len = 0;
    if (head -> next) {
        // 遍历输出，同时统计长度
        do {
            ++len;
            printf("%c", index -> ch);
            index = index -> next;
        } while (index != head -> next);
    }
    // 输出长度
    printf("\n%d\n", len);

    char str[len+1];
    if (head -> next) {
        // 复制到字符串
        for (int i = 0;; ++i) {
            str[i] = index -> ch;
            index = index -> next;
            if (index == head -> next)
                break;
        }
    }

    // 字符串最后的 '\0'
    str[len] = '\0';
    printf("%s", str);

    // 释放内存
    node* p = index;
    for (int i = 0; i < len; ++i) {
        index = index -> next;
        free(p);
        p = index;
    }
    free(head);

    return 0;
}