/*
https://stepik.org/lesson/307321/step/5?unit=289409
Задано целое число N (4 \le N \le 10^6)N(4≤N≤10 
6
 ). Найти сумму наименьших простых делителей всех составных чисел, больших 2 и не превосходящих N.

Sample Input 1:

5
Sample Output 1:

2
Sample Input 2:

9
Sample Output 2:

9

*/

#include <bits/stdc++.h>

using namespace std;


long long minSimpleDividersSum(long long n) {
    vector<int> v(n + 1, 0);
    for (long long i = 2; i * i <= n; ++i) {
        if (v[i] == 0) {
            for (long long j = i; i * j <= n; ++j) {
                if (v[i * j] == 0) {
                    v[i * j] = i;
                }
            }
        }
    }
    long long res = 0;
    for (auto i : v) {
        res += i;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << minSimpleDividersSum(n);
    return 0;
}




