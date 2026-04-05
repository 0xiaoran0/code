#include <stdio.h>
#include <string.h>

void get_nextval(char a[], int nev[]) {
    int len_a = strlen(a) + 1;
    int i = 1, j = 0;
    for (; i < len_a;) {
        if (a[i] == a[j] || j == -1) {
            ++i;
            ++j;
            nev[i] = j;

            if (a[i] == a[j]) {
                nev[i] = nev[j];
            }
        } else {
            j = nev[j];
        }
    }
}

void kmp (char a[], char b[]) {
    int len_a = strlen(a) + 1;
    int nev[len_a];
    nev[0] = -1;
    nev[1] = 0;
    
    get_nextval(a, nev);

    for (int i = 0; i < len_a; ++i) {
        printf("%d\t", nev[i]);
    }
}

int main() {
    char a[] = "aaaab";
    kmp(a, "");

    return 0;
}