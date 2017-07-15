/*
Определим «волшебный» индекс для массива A [ 0".n - 1 ] как и ндекс, для которого
выполняется условие А[ i ] =i. Для заданного отсортироваг1ного массива,
не содержащего одинаковых значений, напишите метод воиска «волшебного»
индекса в массиве А (если он существует).
*/

#include <iostream>
#include <stdio.h>
#define For(x,n) for(int x = 0; x < n; ++x)
#include <bits/stdc++.h>
using namespace std;

int Foo(int low, int high, const vector<int>&v);
int Foo(const vector<int>& v){
    int low = 0, high = v.size() - 1;
    return Foo(low, high, v);
}

int Foo(int low, int high, const vector<int>&v){
    if (!(low <= high)){
        return -1;
    }
    int mid = (low + high) / 2;
    if (v[mid] == mid){
        return mid;
    } else if (v[mid] < mid){
        return Foo(mid + 1, high, v);
    } else {
        return Foo(low, mid - 1, v);
    }
}

int main() {
    cout << Foo({0, 9, 10});
    return 0;
}
