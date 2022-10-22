/* https://leetcode.com/problems/rotting-oranges/

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        
        int cnt_fresh = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});   
                    dist[i][j] = 0;
                } else if (grid[i][j] == 1) {
                    cnt_fresh++;
                }
            }
        }
        if (cnt_fresh == 0) {
            return 0;
        }
        
        while (not q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            int steps[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (int i = 0; i < 4; ++i) {
                int newx = x + steps[i][0];
                int newy = y + steps[i][1];
                
                if (newx >= 0 and newy >= 0 and newx < n and newy < m) {
                    if (grid[newx][newy] == 1 and dist[newx][newy] > dist[x][y] + 1) {
                        dist[newx][newy] = dist[x][y] + 1;
                        q.push({newx, newy});
                    }
                }
            }
        }
        
        int res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) { // fresh
                    if (dist[i][j] == INT_MAX) {
                        return -1;
                    }
                    res = max(res, dist[i][j]);
                }
            }
        }
        return res;
    }
};
