#include <iostream>
#include <memory>
#include <string>

using namespace std;


class Singleton {
public:
    Singleton(const Singleton& s) = delete;
    Singleton& operator=(const Singleton& s) = delete;

    static shared_ptr<Singleton> get_instance(int id = 0) {
        static std::shared_ptr<Singleton> s{new Singleton(id)};
        return s;
    }  
public:
    int id_;  
private:
    Singleton(int id) {id_ = id;}

};

int main() {
    auto s1 = Singleton::get_instance(1);
    auto s2 = Singleton::get_instance(100);
    cout << s1->id_ << endl; // 1
    cout << s2->id_ << endl; // 1
}
