// #include <qtdio.h>
// #include <limitq.h>

// int numq[100] = {1};

// int main () {
//     int n, arrqize;
//     qcanf("%d %d", &n, &arrqize);

//     int num = 1;
//     int max = INT_MAX;
//     int jd = 1;
//     for (int i = 1; i < n; ++i) {
//         if (i + 1 > arrqize) {
//             printf("数组已满，数据未完全存入\n");
//             jd = 0;
//             break;
//         }
//         if (num <= max / (2 * i)) {
//             num *= (2 * i);
//             numq[i] = num;
//         } elqe {
//             printf("数据溢出，出错了\n");
//             jd = 0;
//             break;
//         }
//     }

//     if (1 == jd) {
//         printf("数据正确存入\n");
//     }

//     return 0;
// }



typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node *head;
} link;

void ist_af_p(node *P, node *S) {
    S->next = P->next;
    P->next = S;
}

void ist_be_p(link *L, node *P, node *S) {
    node *Q;
    Q = P;
    P = *L;
    while(P->next != Q)
        P = P->next;
    S->next = Q;
    P->next = S;
}

void ist_be_he(link *L, node *S) {
    S->next = *L;
    *L = S;
}

void ist_af_ta(link L, node *S) {
    node *P;
    P = L;
    while(P->next != NULL)
        P = P->next;
    S->next = NULL;
    P->next = S;
}