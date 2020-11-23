/*


You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]

Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]



*/


// Simple native solution
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        for (int i = 0; i < matrix.size() / 2 + matrix.size() % 2; ++i) {
            for (int j = 0; j < matrix.size() / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j][i];
                matrix[n - j][i] = matrix[n - i][n - j];
                matrix[n - i][n - j] = matrix[j][n - i];
                matrix[j][n - i] = temp;
            }
        }
    }
};


// Solution 2

void Solution::rotate(vector<vector<int> > &A) {
    int sz = A.size();
    int tmp1, tmp2;
    int iter = sz / 2;
    for (int i = 0; i < iter; i++) {
        for (int j = i; j < sz - 1  - i; j++) {
            tmp1 = A[j][sz - 1 - i];
            A[j][sz - 1 - i] = A[i][j];
            
            tmp2 = A[sz - i - 1][sz - j - 1];
            A[sz - i - 1][sz - j - 1] = tmp1;
            
            tmp1 = A[sz - 1 - j][i];
            A[sz - 1 - j][i] = tmp2;
            
            A[i][j] = tmp1;
        }
    }
    
    
}
