/*
У вас есть nn слитков золота, каждый имеет свой вес. Также у вас есть рюкзак вместимости SS. Необходимо вычислить максимальный вес, который вы можете с собой унести. Вы не можете дробить слитки.

Входные данные

В первой строке записано два целых числа SS и NN (1 \leq S \leq 10^41≤S≤10 
4
 ; 1 \leq N \leq 3001≤N≤300).

Во второй строке записаны nn целых чисел - веса слитков. Каждый слиток имеет неотрицательный вес, не превосходящий 10^510 
5
 .

Выходные данные

Выведите единственное число - максимальный суммарный вес, который вы можете унести.

Sample Input 1:

10 6
2 3 4 4 6 9
Sample Output 1:

10
Sample Input 2:

10 6
1 1 1 1 1 1
Sample Output 2:

6


*/



#include <bits/stdc++.h>

using namespace std;


int main() {
    int s, n;
    cin >> s >> n;
    vector<int>weights(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> weights[i];
    }
    // dp[i][j] = 1 - if we can combine weight=j from weights in range [0, i]
    // else - 0
    vector<vector<long long>> dp(n + 1, vector<long long>(s + 1, 0)); 
    dp[0][0] = 1; // we can combine weight=0 from 0 weights

    for (int i = 1; i <= n; ++i) {
        for (int weight = 0; weight <= s; ++weight) {
            if (weights[i] <= weight) {
                dp[i][weight] = dp[i - 1][weight] or dp[i - 1][weight - weights[i]];
            } else {
                dp[i][weight] = dp[i - 1][weight];
            }
        }
    }
    for (int maxWeight = s; maxWeight >= 0; maxWeight--) {
        if (dp[n][maxWeight] == 1) {
            cout << maxWeight;
            break;
        }
    }
    return 0;
}
