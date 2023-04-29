/*
https://leetcode.com/contest/biweekly-contest-103/problems/maximum-number-of-fish-in-a-grid/


You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

A land cell if grid[r][c] = 0, or
A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any number of times:

Catch all the fish at cell (r, c), or
Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

 

Example 1:


Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
Example 2:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
0 <= grid[i][j] <= 10
*/


class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& cur) {
        int n = grid.size();
        int m = grid[0].size();
        if (i >= 0 and  i < n and j >= 0 and j < m and grid[i][j]) {
            cur += grid[i][j];
            grid[i][j] = 0;
            dfs(grid, i + 1, j, cur);
            dfs(grid, i - 1, j, cur);
            dfs(grid, i, j + 1, cur);
            dfs(grid, i, j - 1, cur);
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cur = 0;
                if (grid[i][j]) {
                    //cout << "XXX_ " << i << ' ' << j << endl;
                    dfs(grid, i, j, cur);
                    res = max(res, cur);
                    grid[i][j] = 0;
                }
            }
        }
        return res;
    }
};
