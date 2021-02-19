/* https://leetcode.com/problems/number-of-islands/
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/

// O(n*m)
class Solution {
public:

    bool isSafe(int i, int j, int n, int m) {
        return 0 <= i and i < n and 0 <= j and j < m;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j, int color) {
        vector<int> row {-1, 1, 0, 0};
        vector<int> col {0, 0, -1, 1};
        visited[i][j] = color;
        int n = grid.size();
        int m = grid[0].size();
        for (int k = 0; k < row.size(); ++k) {
            int ii = i + row[k];
            int jj = j + col[k];
            if (isSafe(ii, jj, n, m) and not visited[ii][jj] and grid[ii][jj] == '1') {
                dfs(grid, visited, ii, jj, color);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (not visited[i][j] and grid[i][j] == '1') {
                    ++res;
                    dfs(grid, visited, i, j, res);
                }
            }
        }
        /* Print grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << visited[i][j] << ' ';
            }
            cout << endl;
        }*/
        return res;
    }
};
