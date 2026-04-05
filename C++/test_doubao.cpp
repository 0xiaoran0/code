#include <iostream>
using namespace std;

class A;
void test01 ();

int main () {
    test01();

    return 0 ;
}

class A {
    public:
        A (int x) {
            a = new int (x);
        }
        ~A () {
            if (a != NULL) {
                delete a;
                a = NULL;
            }
        }

        A& operator = (A& x) {
            if (a != NULL) {
                delete a;
                a = NULL;
            }
            a = new int (*(x.a));

            return *this;
        }

        int *a;
};

void test01 () {
    A a1(18);
    cout << *a1.a << endl;
    A a2(20);
    cout << *a2.a << endl;
    a2 = a1;
    cout << *a1.a << endl;
    cout << *a2.a << endl;
}