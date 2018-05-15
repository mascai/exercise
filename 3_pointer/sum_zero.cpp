// Найти в отсортированном массиве i, j: a[i]+a[j]=0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int>sum_zero(vector<int>a) {
    int start_pos = 0, end_pos = a.size() - 1;
    while (start_pos < end_pos) {
        if (a[start_pos] + a[end_pos] == 0) {
            return {start_pos, end_pos, a[start_pos]};
        }
        if (abs(a[start_pos]) > abs(a[end_pos])) {
            start_pos++;
        } else {
            end_pos--;
        }
    }
    if (start_pos != end_pos &&
        a[start_pos] + a[end_pos] == 0) {
            return {start_pos, end_pos, a[start_pos]};
        }
    return {-1, -1};
}

int main() {
    vector<int>v = {-4, -3, -2, 0, 1, 3, 5};
    vector<int>ans = sum_zero(v);
    cout << "Start " << ans[0] << endl;
    cout << "End   " << ans[1] << endl;
    cout << "Val   " << ans[2] << endl;
    return 0;
}
