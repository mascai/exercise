#include <bits/stdc++.h>

using namespace std;

class A {
public:
    void f() { cout << "A " << endl;}
};

class B: public A {
public:
    void f() { cout << "B " << endl;}
};

class vA {
public:
    virtual void f() { cout << "vA " << endl;}
};

class vB: public vA {
public:
    void f() { cout << "vB " << endl;}
};

int main() {
    A a;
    B b;
    A *pa;
    B *pb;
    pa = &a;
    pa->f(); // A
    pa = &b;
    pa->f(); // A
    cout << "VIRTUAL FUNCTIONS: " << endl;
    vA virt_a;
    vB virt_b;
    vA *virt_pa;
    vB *virt_pb;
    virt_pa = &virt_a;
    virt_pa->f(); // vA
    virt_pa = &virt_b;
    virt_pa->f(); // vB
    return 0;
}
