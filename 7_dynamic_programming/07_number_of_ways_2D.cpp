/*
https://stepik.org/lesson/307327/step/6?unit=289415

Путь Черепахи

В верхнем-левом углу таблицы сидит черепаха. Она умеет ходить только вниз, вправо и вниз-вправо. Каждая клетка доски либо свободна, либо занята. Черепаха хочет попасть в нижнюю-правую клетку. Сколькими способами она может это сделать?

Входные данные

В первой строке входных данных записано два числа nn, mm (1 \leq n, m \leq 10001≤n,m≤1000) - количество строк и столбцов в таблице.

В следующих nn строках записано по mm чисел - данная таблица. 00 обозначает свободную клетку, а 11 - занятую. Гарантируется, что верхняя левая и нижняя правая клетки свободны.

Выходные данные

Выведите единственное число - количество способов добраться до нижней правой клетки. Поскольку это число может быть очень большим, выведите его по модулю 10^9 + 910 
9
 +9.

Sample Input 1:

3 5
0 0 1 0 0
1 1 0 1 1
0 0 0 0 0
Sample Output 1:

2
Sample Input 2:

5 5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
Sample Output 2:

321

*/

#include <bits/stdc++.h>

using namespace std;


int main() {
    const long long MOD = 1000000009;
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> v(n, vector<long long>(m));
    vector<vector<long long>> dp(n, vector<long long>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }
    dp[0][0] = 1 - v[0][0];
    for (int i = 1; i < n; ++i) {
        if (v[i][0] == 1) {
            dp[i][0] = 0;
        } else {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for (int i = 1; i < m; ++i) {
        if (v[0][i] == 1) {
            dp[0][i] = 0;
        } else {
            dp[0][i] = dp[0][i - 1];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (v[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = ((dp[i - 1][j] % MOD) + (dp[i][j - 1] % MOD) + (dp[i - 1][j - 1] % MOD)) % MOD;
            }
        }
    }
    cout << dp[n - 1][m - 1];
}
