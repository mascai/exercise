#include <bits/stdc++.h>

using namespace std;

/*
Имеется калькулятор, который выполняет три операции:

    Прибавить к числу X единицу;
    Умножить число X на 2;
    Умножить число X на 3.

Определите, какое наименьшее число операций необходимо для того,
чтобы получить из числа 1 заданное число N.
Выведите это число, и, на следующей строке, набор исполненных операций вида «111231»
*/

int main(){
    int n;
    cin >> n;
    vector<int>dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= n; i++) {
        if (i % 3 == 0 && i % 2 == 0) {
            dp[i] = min(min(dp[i / 2], dp[i / 3]), dp[i - 1]) + 1;
        } else if (i % 3 != 0 && i % 2 == 0) {
            dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
        } else if (i % 3 == 0 && i % 2 != 0) {
            dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
        } else {
            dp[i] = dp[i - 1] + 1;
        }
    }
    cout << dp.back() << endl;

    int i = n;
    string ans;
    while (i > 1) {
        if (dp[i] == dp[i - 1] + 1) {
           ans.insert(0, "1");
           i--;
           continue;
        }
        if (i % 2 == 0 && dp[i] == dp[i / 2] + 1) {
            ans.insert(0, "2");
            i /= 2;
            continue;
        }
        ans.insert(0, "3");
        i /= 3;
    }
    cout << ans << endl;
    return 0;
}
