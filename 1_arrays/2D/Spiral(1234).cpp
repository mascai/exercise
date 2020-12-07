/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:
[ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]

*/



// Solution 1
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int l = 0, r = n - 1, high = 0, low = n - 1;
        int mode = 0;
        int i = 1;
        while (i <= n * n) {
            if (mode == 0) {
                for (int j = l; j <= r; ++j) {
                    res[high][j] =  i++;
                }
                high++;
            }
            if (mode == 1) {
                for (int j = high; j <= low; ++j) {
                    res[j][r] = i++;
                }
                r--;
            }
            if (mode == 2) {
                for (int j = r; j >= l; --j) {
                    res[low][j] =  i++;
                }
                low--;
            }
            if (mode == 3) {
                for (int j = low; j >= high; --j) {
                    res[j][l] = i++;
                }
                l++;
            }
            mode = (mode + 1) % 4;
        }
        return res;
    }
};



// Solution 2
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
            int dir = 0;
            vector< vector<int> > matrix(n, vector<int> (n, 0));
            int i = 0, j = 0, k = 1;
            while (k <= n * n) {
                matrix[i][j] = k++;
                if (dir == 0){
                    j++;
                    if (j == n || matrix[i][j] != 0) dir = 1, j--, i++;
                } else
                if (dir == 1) {
                    i++;
                    if (i == n || matrix[i][j] != 0) dir = 2, i--, j--;
                } else
                if (dir == 2) {
                    j--;
                    if (j < 0 || matrix[i][j] != 0) dir = 3, j++, i--;
                } else
                if (dir == 3) {
                    i--;
                    if (i < 0 || matrix[i][j] != 0) dir = 0, i++, j++;
                }
            }
            return matrix;
        }
};

