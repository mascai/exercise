#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


template<class T>
class SmartPtr {
public:
    SmartPtr(T* data) {
        data_ = data;
        count_ = new size_t(1);
    }

    SmartPtr(SmartPtr<T>& temp) {
        data_ = temp.data_;
        count_ = temp.count_;
        ++(*count_);
    }

    SmartPtr(SmartPtr<T>&& temp) {
        data_ = temp.data_;
        count_ = temp.count_;
        temp.data_ = NULL;
        temp.count_ = NULL;
    }

    SmartPtr<T> operator=(SmartPtr<T>& temp) {
        if (this == &temp) {
            return *this;
        }
        if (*count_ > 0) {
            remove();
        }
        data_ = temp.data_;
        count_ = temp.count_;
        ++(*count_);
        return *this;
    }

    friend ostream& operator<<(ostream& os, SmartPtr<T>& temp) {
        os << "Data " << *(temp.data_) << " Count " << *(temp.count_);
        return os; 
    }
    
    T* getData() const {
        return data_;
    }
    
    size_t getCount() const {
        return *count_;
    }
private:
    void remove() {
        --(*count_);
        if (*count_ == 0) {
            delete data_;
            delete count_;
        }
    }
private:
    T* data_;
    size_t* count_;
};



TEST(TestSmartPtr, Test1) {
    {
        string* s = new string("123");
        SmartPtr<string> ptr(s);
        SmartPtr<string> ptr2(ptr);
        ASSERT_EQ("123", *ptr.getData());
        ASSERT_EQ(2, ptr2.getCount());
        
    }

    {
        string* s = new string("123");
        SmartPtr<string> ptr(s);
        SmartPtr<string> ptr2 = ptr;
        ASSERT_EQ("123", *ptr.getData());
        ASSERT_EQ(2, ptr2.getCount());
        
    }

    {
        string* s = new string("123");
        SmartPtr<string> ptr(s);
        SmartPtr<string> ptr2(std::move(ptr));
        ASSERT_EQ("123", *ptr2.getData());
        ASSERT_EQ(1, ptr2.getCount());

        ASSERT_EQ(NULL, ptr.getData());
    }
    
}

int main(int argc, char** argv) {  
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
