/*Напишите рекурсивную функцию для умножения двух положительных целых
чисел без использования оператора * . Допускается использование операций
сложения, вычитания и поразрядного сдвига, но их количество должно быть
минимальным.*/


#include <iostream>
#include <stdio.h>
#define For(x,n) for(int x = 0; x < n; ++x)
#include <bits/stdc++.h>
using namespace std;
int rec(int smal, int big, vector<int> memo);
int F(int a, int b){ // a * b
    int big  = a > b ? a : b,
        smal = a > b ? b : a;
    vector<int>memo(smal + 1, 0);
    return rec(smal, big, memo);
}

int rec(int smal, int big, vector<int> memo){
    if (smal == 0){
        return 0;
    }
    if (smal == 1){
        return big;
    }
    if (memo[smal] != 0){
        return memo[smal];
    }
    int s = smal / 2;
    int side1 = rec(s, big, memo);
    int side2 = side1;
    if (smal % 2 == 1){
        side2 =  rec(smal - s, big, memo);
    }
    memo[smal] = side1 + side2;
    return side1 + side2;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << F(a, b);
    return 0;
}
