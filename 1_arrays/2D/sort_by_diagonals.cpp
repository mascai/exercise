/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3614/
A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

 

Example 1:


Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
*/

class Solution {
public:
    void solve(vector<vector<int>>& mat, int i, int j) {
        int n = mat.size();
        int m = mat[0].size();
        int ii = i;
        int jj = j;
        vector<int> cur;
        while (ii < n and jj < m) {
            cur.push_back(mat[ii++][jj++]);
        }
        sort(begin(cur), end(cur));
        int pos = 0;
        ii = i;
        jj = j;
        while (ii < n and jj < m) {
            mat[ii++][jj++] = cur[pos++];
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if (mat.size() < 2) {
            return mat;
        }
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; ++i) {
            solve(mat, i, 0);
        }
        for (int i = 1; i < m; ++i) {
            solve(mat, 0, i);
        }
        return mat;
    }
};
