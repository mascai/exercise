/*
  Повернуть массив налево (направо) на N элементов
*/

#include <bits/stdc++.h>

using namespace std;

void print_vec(const vector<int>& v) {
    for (auto& i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

vector<int> rotate_left(const vector<int> &v, int k) {
    vector<int>ans(v.size());
    for (int i = 0; i < v.size(); i++) {
        ans[i] = v[(i + k) % v.size()];
    }
    return ans;
}

vector<int> rotate_right(const vector<int> &v, int k) {
    int sz = v.size();
    vector<int>ans(sz);
    for (int i = 0; i < sz; i++) {
        ans[i] = v[(sz + i - k) % v.size()];
    }
    return ans;
}

int main() {
    vector<int>v = {1, 2, 3, 4, 5};
    vector<int>v_left = rotate_left(v, 1);
    print_vec(v_left);
    vector<int>v_right = rotate_right(v, 1);
    print_vec(v_right);
    return 0;
}
