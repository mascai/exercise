#include <bits/stdc++.h>

using namespace std;
template <class T>
class Vec {
public:
    T *body;
    int size;
    Vec(int _size) {
        size = _size;
        body = new T[size];
    }
    Vec(Vec &v) {
        size = v.size;
        body = new T[size];
        for (int i = 0 ; i < size; i++) {
            body[i] = v[i];
        }
    }
    Vec &operator =(const Vec &v) {
        if (this != &v) {
            delete []body;
            size = v.size;
            body = new int [size];
            for (int i = 0 ; i < size; i++) {
                body[i] = v[i];
            }
        }
        return *this;
    }
    ~Vec() {
        delete []body;
    }
    T operator [](int id) {
        return body[id];
    }
};

int main() {
    int a, b;
    cin >> a >> b;
    Vec<int> arr(2);
    arr.body[0] = a;
    arr.body[1] = b;

    Vec<int>arr2(arr);
    for (int i = 0 ; i < 2; i++) {
        cout << arr2[i] << ' ';
    }

}
