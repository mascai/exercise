/*

Вам даны два целых числа NN и  MM (1 \le N \le 10^9, 2 \le M \le 10^91≤N≤10 
9
 ,2≤M≤10 
9
 ). Вычислите остаток от деления N^NN 
N
  на M.

Sample Input 1:

3 1001
Sample Output 1:

27
Sample Input 2:

10 123456
Sample Output 2:

64000

*/


#include <bits/stdc++.h>


using namespace std;
 

long long fastPow(long long a, long long n, long long MOD) {
    if (n == 0LL) {
        return 1;
    }
    if (n % 2 == 1) {
        return (a * fastPow(a, n - 1, MOD)) % MOD;
    }
    long long temp = fastPow(a, n / 2, MOD);
    return (temp * temp) % MOD;
}

int main(){
    long long n, m;
    cin >> n >> m;
    cout << fastPow(n, n, m);
    
}
