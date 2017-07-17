/*
Дано неограниченное количество монет достоинством 25, 1 0, 5 и 1 цент.
Напишите код, определяющий количество способов представления п центов.
*/
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int Foo(int n, int index, vector<int>v);
int Foo(int n){
    vector<int>v = {25, 10, 5, 1};
    return Foo(n, 0, v);
}

int Foo(int n, int index, vector<int>v){
    if (index > v.size() - 1){
        return 1;
    }
    int val = v[index];
    int way = 0;
    for (int i = 0; i * val < n; i++){
        int remain = n - i * val;
        way += Foo(remain, index + 1, v);
    }
    return way;
}
int main()
{
    cout << Foo(25);
}
