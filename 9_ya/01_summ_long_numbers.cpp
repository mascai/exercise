#include <iostream>
#include <iomanip>

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

 
using namespace std;



vector<int> str_to_vec(const string& s) {
    vector<int> res;
    //cout << "INPUT " << s << endl;
    for (int i = 1; i < s.size(); ++i) {
        if (std::isdigit(s[i])) {
            res.push_back(s[i] - '0');
        }
    }
    return res;
}

vector<int> sum_vec(vector<int> v1, vector<int> v2) {
    vector<int> res;
    if (v1.size() < v2.size()) {
        swap(v1, v2);
    }
    reverse(begin(v1), end(v1));
    reverse(begin(v2), end(v2));

    int carry = 0;
    int i = 0;
    for (; i < v1.size(); ++i) {
        int cur_sum = v1[i] + carry;
        if (i < v2.size()) {
            cur_sum += v2[i];
        }
        res.push_back(cur_sum % 10);
        carry = cur_sum / 10;
    }
    if (carry) {
        res.push_back(carry);
    }
    reverse(begin(res), end(res));
    return res;
}

void print_res(const vector<int>& v) {
    cout << '[';
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << ", ";
        }
    }
    cout << ']';
}


int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    const auto res = sum_vec(str_to_vec(s1), str_to_vec(s2));
    print_res(res);
}
