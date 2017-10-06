/*

Каждый день вырастает один лук, его можно продать или отложить
Цены известны заранее
Вход: вектор цен на каждый день
Выход: максимальная сумма, которую можно получить, продавая лук

*/

#include <bits/stdc++.h>

#define SIZE 5

using namespace std;

void print_pair(vector<pair<int, int>>p) {
    for (auto i : p)
    cout << i.first << ' ' << i.second << endl;
}

bool cmp (pair<int, int>a, pair<int, int>b) {
    return a.first > b.first;
}

int main() {
    //vector<int>v = {10, 5, 17, 3, 4};
    vector<int>v(SIZE);
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
    vector<pair<int, int>>p; // <price, day>
    for (int i = 1; i <= v.size(); i++) {
        p.push_back(make_pair(v[i - 1], i));
    }
    sort(begin(p), end(p), cmp); // sort by price 10 9 8 ...
    //print_pair(p);
    int day = p[0].second,
        ans = 0,
        dec = 0; // number of sold items
    for (auto item : p) {
        if (item.second >= day) {
            ans += item.first * (item.second - dec);
            day = item.second;
            dec += item.second - dec;
        }
    }
    cout << ans;
}
