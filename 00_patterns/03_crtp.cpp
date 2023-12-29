#include <iostream>
#include <memory>
#include <string>

using namespace std;


template<class Type>
class BaseOrder {
public:
    void sendOrder() {static_cast<Type*>(this)->send();}
    void send() { cout << "Send Base" << endl;}
};

class DerivedOrder1 : public BaseOrder<DerivedOrder1> {
public:
    void send() { cout << "Send DerivedOrder1" << endl;}
};

class DerivedOrder2 : public BaseOrder<DerivedOrder2> {
public:
    void send() { cout << "Send DerivedOrder2" << endl;}
};


int main() {
    BaseOrder<DerivedOrder1> obj1;
    obj1.sendOrder();

    BaseOrder<DerivedOrder2> obj2;
    obj2.sendOrder();
}
