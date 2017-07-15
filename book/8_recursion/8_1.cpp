/*
Ребенок поднимается п о лестнице и з п ступенек. З а оди н шаг о н может переместиться
на одну, две или три ступеньки. Реализуйте метод, рассчитывающий
количество возможных вариантов перемещения ребенка по лестнице.
*/

#include <iostream>
#include <stdio.h>
#define For(x,n) for(int x = 0; x < n; ++x)
#include <bits/stdc++.h>
using namespace std;

int Foo(int n, vector<int>&v);
int Foo(int n){
    vector<int>v(n+1, -1); // if in memory
    return Foo(n, v);
}

int Foo(int n, vector<int>&v){
    if (n < 0){
        return 0;
    } else if (n == 0){
        return 1;
    } else if (v[n] > -1){
        return v[n];
    } else{
        v[n] = Foo(n-1, v) + Foo(n-2, v) + Foo(n-3, v);
        return v[n];
    }
}

int main() {
    cout << Foo(3);
    return 0;
}
