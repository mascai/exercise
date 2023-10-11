#include <iostream>
#include <vector>
#include <cassert>


using namespace std;

vector<int> foo(const vector<int>& v1, const vector<int>& v2) {
    vector<int> res;
    int len1 = v1.size();
    int len2 = v2.size();
    int i2 = 0;
    for (int i1 = 0; i1 < len1; ++i1) {
        while (i2 < len2 and v1[i1] > v2[i2]) {
            ++i2;
        }
        if (i2 == len2 or v1[i1] < v2[i2]) {
            res.push_back(v1[i1]);
        }
    }
    return res;
}

int main() {
    vector<int> v1 {1, 1, 2, 2, 3, 4, 5};
    vector<int> v2 {2, 3};
    auto res = foo(v1, v2); // return elements of v1, which not present in v2
    vector<int> expected {1, 1, 4, 5};
    assert(res == expected);
}
