#include <iostream>
#include <vector>


using namespace std;


template<class T>
class my_shared_ptr {
public:
    my_shared_ptr() {}

    my_shared_ptr(T* ptr) {
        m_ptr = ptr;
        m_counter = new size_t(1);
    }

    my_shared_ptr(const my_shared_ptr& other) 
        : m_ptr(other.m_ptr)
        , m_counter(other.m_counter) {
            if (m_counter) {
                ++(*m_counter);
            }
        }

    my_shared_ptr(my_shared_ptr&& other)
        : m_ptr(std::exchange(other.m_ptr, nullptr))
        , m_counter(std::exchange(other.m_counter, nullptr)) {
    }

    my_shared_ptr& operator=(const my_shared_ptr& other) {
        my_shared_ptr tmp(other);
        tmp.swap(*this);
        return *this;
    }

    my_shared_ptr& operator=(my_shared_ptr&& other) {
        my_shared_ptr tmp(std::move(other));
        other.swap(*this);
        return *this;
    }

    void swap(my_shared_ptr& other) noexcept {
        std::swap(m_ptr,  other.m_ptr);
        std::swap(m_counter, other.m_counter);
    }

    size_t use_count() const {
        if (m_counter) {
            return *m_counter;
        }
        return 0;
    }



    ~my_shared_ptr() {
        if (m_counter and *m_counter > 1) {
            --(*m_counter);
        } else {
            delete m_ptr;
            delete m_counter;
        }
    }

private:
    T* m_ptr = nullptr;
    size_t* m_counter = nullptr;
};


struct A {
    A() {
        cout << "A()\n";
    }

    ~A() {
        cout << "~A()\n";
    }
};



template<class T, class... Args>
my_shared_ptr<T> my_make_shared(Args&&... args) {
    auto ptr = new T(std::forward<Args>(args)...);
    return my_shared_ptr(ptr);
}

int main() {
    auto p1 = my_make_shared<A>();
    cout << p1.use_count() << endl;
    my_shared_ptr<A> p2 = p1;
    cout << p2.use_count() << endl; // 2
    
    my_shared_ptr<A> p3 = std::move(p1);
    assert(p3.use_count() == 2);
}
