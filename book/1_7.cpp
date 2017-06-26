// Повернуть матрицу на 90 градусов

#include<iostream>
#define n 3
using namespace std;
int matr[n][n];
int main()
{
     for(int i = 0;i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> matr[i][j];
     int tmp;
     for(int i = 0; i < n / 2; i++)
     {
         for(int j = i; j < n - 1 - i; j++)
         {
             tmp = matr[i][j];
             matr[i][j] = matr[n-j-1][i];
             matr[n-j-1][i] = matr[n-i-1][n-j-1];
             matr[n-i-1][n-j-1] = matr[j][n-i-1];
             matr[j][n-i-1] = tmp;
         }
     }
     cout << endl;
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << matr[i][j] << ' ';
        }
        cout << endl;
     }
}
