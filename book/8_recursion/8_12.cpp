#include <iostream>
#include <stdio.h>
#define For(x,n) for(int x = 0; x < n; ++x)
#include <bits/stdc++.h>

using namespace std;

int SIZE = 8;
bool check(vector<int> &columns, int row1, int col1);
void placeQueens(int row, vector<int>&columns, vector<vector<int>> &res){
    if (row == SIZE){
        res.push_back(columns);
    } else {
        for (int col = 0; col < SIZE; col++){
            if (check(columns, row, col)){
                columns[row] = col; // Размещение ферзя
                placeQueens(row + 1, columns, res);
            }
        }
    }
}

bool check(vector<int> &columns, int row1, int col1){
    for (int row2 = 0; row2 < row1; row2++){
        int col2 = columns[row2];
        if (col1 == col2){
            return false;
        }
        int colDist = abs(col2 - col1);
        int rowDist = abs(row2 - row1);
        if (colDist == rowDist){
            return false;
        }
    }
    return true;
}

int main()
{
     vector<int>col;
     vector<vector<int>>res;
     placeQueens(3
                 , col, res);
     for (auto item : res){
        for (auto i : item){
            cout << i << ' ';
        }
        cout << endl;
     }
}
