/*
    Мажорирующий_элемент
    на вход вектор N натураьных чисел
    если в нем есть число, которое стречается больше, чем N/2 раз,
    то вывести это число, иначе вывести -1

    Рещение за O(N)
*/

#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<int>v = {1, 1, 2, 2, 1, 2, 1, 3, 1, 1};
    int bit_cnt = 0, mask = 1;
    stack<int>st;
    for (int i = 0; i < v.size(); i++) {
        if (st.empty() || st.top() == v[i]) {
            st.push(v[i]);
        } else {
            st.pop();
        }
    }
    if (!st.empty()) {
        cout << st.top();
    } else {
        cout << "-1";
    }
}


