// Solution 1

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


// Solution2

#include <atomic>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Singleton {
public:
    static shared_ptr<Singleton> init() {
        static shared_ptr<Singleton> res = shared_ptr<Singleton>(new Singleton({1, 2}));
        return res;
    }
    Singleton(const Singleton& other) = delete;
    Singleton& operator=(const Singleton& other) = delete;

    friend ostream& operator<<(ostream& os, const Singleton& other) {
        for (auto i : other.data) {
            os << i << ' ' ;
        }
        return os;
    }
private:
    Singleton(const vector<int> v) : data(v) {}
private:
    vector<int> data;
};

int main() {
    auto s = Singleton::init();
    cout << *s << endl;
}
