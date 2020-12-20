/*
https://stepik.org/lesson/307320/step/4?unit=289408

Найти наибольший общий делитель N целых положительных чисел.

В первой строке входных данных находится одно целое положительное число N, не меньшее 2 и не превосходящее 100. Вторая строка содержит N целых положительных чисел, не превосходящих 10^610 
6
 , наибольший общий делитель которых надо найти.

Sample Input 1:

4
2 4 6 2022
Sample Output 1:

2
Sample Input 2:

3
10001 10002 10003
Sample Output 2:

1

*/


#include <bits/stdc++.h>


using namespace std;
 

int gcd (int a, int b) {
    while (b) {
        auto c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int res = gcd(a, b);
    for (int i = 2; i < n; ++i) {
        cin >> a;
        res = gcd(a, res);
    }
    cout << res;
    return 0;
}

