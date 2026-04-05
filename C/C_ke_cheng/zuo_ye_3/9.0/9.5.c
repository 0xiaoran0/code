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

    // 遍历输入
    int ch;
    while ((ch = getchar()) != '\n') {
        node* p = (node*) malloc (sizeof(node));
        p -> ch = ch;
        index -> next = p;
        index = index -> next;
    }
    // 构造成环，便于后续遍历
    index -> next = head -> next;
    node* tail = index;
    index = index -> next;

    int len = 0;
    if (head -> next) {
        // 遍历统计长度
        do {
            ++len;
            index = index -> next;
        } while (index != head -> next);
    }

    // 输入字符
    scanf("%c", &ch);
    // 标记是否有相同字符
    int judge = 1;
    // 用来标记可能要插入的部位，以及为删除做准备
    node* max = NULL;
    node* last = head;
    // 存储差值与最大值
    int dif = 0;
    int max_n = 0;

    if (len > 0) {
        // 遍历寻找相同值与差值最大的地方
        //! 还没有处理如果全部删除之后的空指针，很难搞
        for (int i = len; i > 0; --i) {
            if (index -> ch == ch) {
                judge = 0;
                --len;
                node* p = index;
                index = index -> next;
                last -> next = index;
                tail -> next = head -> next;
                free(p);
                continue;
            }

            dif = (ch - index -> ch) > 0 ? \
                ch - index -> ch : index -> ch - ch;
            if (max_n < dif) {
                max = index;
                max_n = dif;
            }

            last = index;
            index = index -> next;
        }

        // 如果无相同值，执行插值的程序
        if (judge) {
            node* p = (node*) malloc (sizeof(node));
            p -> ch = ch;
            p -> next = max -> next;
            max -> next = p;
            ++len;
        }
    } else {
        node* p = (node*) malloc (sizeof(node));
        p -> ch = ch;
        index = p;
        head -> next = index;
        index -> next = index;
    }

    // 遍历输出
    if (len > 0) {
        do {
            printf("%c", index -> ch);
            index = index -> next;
        } while (index != head -> next);
    }

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