/*
Напишите метод, возвращающий все подмножества заданного множества
*/

#include <iostream>
#include <stdio.h>
#define For(x,n) for(int x = 0; x < n; ++x)
#include <bits/stdc++.h>
using namespace std;
void Foo(vector<int>v, vector<vector<int>>&ans, vector<int>cur, int index);
vector<vector<int>>Foo(vector<int>v){
    vector<vector<int>>ans;
    vector<int>cur;
    sort(begin(v), end(v));
    Foo(v, ans, cur, 0);
    sort(begin(ans), end(ans));
    return ans;
}

void Foo(vector<int>v, vector<vector<int>>&ans, vector<int>cur, int index){
    if (index >= v.size()){
        ans.push_back(cur);
        return;
    }
    //ignore
    Foo(v, ans, cur, index + 1);

    //push
    cur.push_back(v[index]);
    Foo(v, ans, cur, index + 1);
    cur.pop_back();
}


int main() {
    auto v = Foo({0, 1, 3});
    for (auto i : v){
        for (auto j : i){
            cout << j << ' ' ;
        }
        cout << endl;
    }
    return 0;
}
