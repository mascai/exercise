#include <iostream>

using std::cout;
using std::endl;

template<class Type>
class BaseOrder {
protected:
    BaseOrder() = default;
    BaseOrder(const BaseOrder&) = default;
    BaseOrder& operator=(const BaseOrder&) = default;
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

template<class T>
void handleOrder(BaseOrder<T>& order) {
    order.sendOrder();
}

int main() {
    DerivedOrder1 obj1;
    handleOrder(obj1);

    DerivedOrder2 obj2;
    handleOrder(obj2);
}
