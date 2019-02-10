#include <bits/stdc++.h>

using namespace std;
/*
Найти K-ый по величине элемент
*/
int selection(vector<int>v, unsigned int k) {
    int index = v.size() / 2;
    vector<int>gt, lt,eq;
    for (auto item : v) {
        if (item > v[index]) {
            gt.push_back(item);
        } else if (item < v[index]) {
            lt.push_back(item);
        } else {
            eq.push_back(item);
        }
        return -1;
    }
    if (k <= lt.size()) {
        return selection(lt, k);
    } else if (lt.size() < k && k <= lt.size() + eq.size()) {
        return v[index];
    } else if (k > lt.size() + eq.size()) {
        return selection(gt, k - lt.size() - eq.size());
    }
}

int heap_solution (vector<int>nums, int k) {
    make_heap(nums.begin(), nums.end(), greater<int>());
    for (int i = 0; i < k - 1; i++) {
        pop_heap(nums.begin(), nums.end(), greater<int>());
        nums.pop_back();
    }
    return nums.front();
}
int main() {
    vector<int>v = {10, 7, 5, 6, 4};
    int k;
    cin >> k;
    cout << "HEAP: " << heap_solution(v, k) << endl;
    cout << "NEW: " << selection(v, k);
}
