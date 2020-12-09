/*

Калькулятор

Имеется калькулятор, который выполняет следующие операции:

Умножить число XX на 22.
Умножить число XX на 33.
Прибавить к числу XX единицу.
Определите, какое наименьшее количество операций требуется, чтобы получить из числа 11 число NN.

Входные данные

Во входном файле написано натуральное число NN, не превосходящее 10^610 
6
 .

Выходные данные

Выведите минимальное количество операций.

Sample Input 1:

1
Sample Output 1:

0
Sample Input 2:

5
Sample Output 2:

3
Sample Input 3:

962340
Sample Output 3:

17

*/

#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    for (int i = 2; i <= n; ++i) {
        if (i % 6 == 0) {
            dp[i] = min(dp[i - 1], min(dp[i / 2], dp[i / 3])) + 1;
        } else if (i % 3 == 0) {
             dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
        } else if (i % 2 == 0) {
            dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
        } else {
            dp[i] = dp[i - 1] + 1;
        }
    }
    cout << dp[n];
    return 0;
}





