/*
Если какой-либо класс имеет хотя бы одну чисто виртуальную функцию, 
то такой класс называется абстрактным (abstract). 
Важной особенностью абстрактных классов является то, 
что не существует ни одного объекта данного класса. 
Вместо этого абстрактный класс служит в качестве базового для других 
производных классов. Причина, по которой абстрактный класс не может быть 
использован для объявления объекта, заключается в том, 
что одна или несколько его функций-членов не имеют определения. 
Тем не менее, даже если базовый класс является абстрактным, 
все равно можно объявлять указатели или ссылки на него, 
с помощью которых затем поддерживает­ся полиморфизм времени исполнения.

*/

#include <bits/stdc++.h>

using namespace std;

class Animal { // abstract class (with virtual function)
public:
    virtual void action() = 0;
};

class Cat: public Animal {
public:
    void action() { cout << "May May " << endl;}
};

class Dog: public Animal {
public:
    void action() { cout << "Hrr Hrr " << endl;}
};


int main() {
    Animal *A;
    Cat mCat;
    Dog mDog;
    A = &mCat;
    A->action();
    A = &mDog;
    A->action();
    return 0;
}