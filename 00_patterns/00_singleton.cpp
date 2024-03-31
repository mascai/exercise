// Solution 1
#include <iostream>
#include <vector>


class Singleton {
public:
    static Singleton& init(std::vector<int> v) {
        static Singleton res = Singleton(v);
        return res;
    }
    Singleton(const Singleton& ) = delete;
    Singleton& operator=(const Singleton&) = delete;

    friend std::ostream& operator<<(std::ostream& os, Singleton& other) {
        for (auto cur : other.data) {
             os << cur << ' ';
        }
        return os;
    }
private:
    Singleton(const std::vector<int> v) {
        data = v;
    }
private:
    std::vector<int> data;
};


int main() {
    Singleton& s = Singleton::init({1, 2, 3});
    std::cout << s << std::endl; // 1 2 3

    Singleton& s2 = Singleton::init({1, 1, 1});
    std::cout << s2 << std::endl; // 1 2 3

}

// Solution 2

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


// Solution3

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
