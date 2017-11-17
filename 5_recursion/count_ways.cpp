/*
В прямоугольной таблице NxM в начале игрок находится в левой верхней клетке.
За один ход ему разрешается перемещаться в соседнюю клетку либо вправо,
либо вниз (влево и вверх перемещаться запрещено).
Посчитайте, сколько есть способов у игрока попасть в правую нижнюю клетку.
*/

#include <bits/stdc++.h>

using namespace std;

// simple solution
int count_ways(int i, int j) {
    if (i == 1 || j == 1) {
        return 1;
    }
    return count_ways(i - 1, j) + count_ways(i, j - 1);
}



int main(){

    int n, m;
    cin >> n >> m;
    cout << "Easy recursion: " << count_ways(n, m) << endl; // simple solution

    vector<vector<int>>dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << "DP solution:    " << dp[n - 1][m - 1] << endl;
    return 0;
}
