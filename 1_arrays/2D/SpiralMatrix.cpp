/*

Input:
[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]

Output:
[1, 2, 3, 6, 9, 8, 7, 4, 5]

*/

#include <iostream>

using namespace std;


int main()
{
    int m, n;
    cin >> m >> n;
    int a[m][n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int T = 0, B = m-1, R = n-1, L = 0;
    int dir = 0;
    while(T <= B && L <= R){
        if (dir == 0){
            for (int i = L; i <= R; i++){
                cout << a[T][i];
            }
            dir = 1;
            T++;
        } else if (dir == 1){
            for (int i = T; i <= B; i++){
                cout << a[i][R];
            }
            dir = 2;
            R--;
        } else if (dir == 2){
            for (int i = R; i >= L; i--){
                cout << a[B][i];
            }
            dir = 3;
            B--;
        } else if (dir == 3){
            for (int i = B; i >= T; i--){
                cout << a[i][L];
            }
            dir = (dir+1)%4;
            L++;
        }
    }
    return 0;
}
