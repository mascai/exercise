/*
Напишите алгоритм, реализующий следующее условие: если элемент матрицы
MxN равен О, то весь столбец и вся строка обнуляются.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>
#include<set>

#define For(x,n) for(int x = 0; x < n; ++x)

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    vector<int>col(m, 1);
    vector<int>row(n, 1);
    For(i, n){
        For(j, m){
            cin >> arr[i][j];
            if (arr[i][j] == 0){
                col[j] = 0;
                row[i] = 0;
            }
        }
    }
    For(i, n){
        For(j, m){
            if (!row[i] || !col[j]){
                arr[i][j] = 0;
            }
        }
    }
    For(i, n){
        For(j, m){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }


}
