/*

In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

 

Example 1:

Input: [[0,1],[1,0]]


Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]


Output: 4

 

Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1
*/



class Solution {
public:
    struct Node {
        int x;
        int y;
        int val;
    };
    
    bool isValid(int x, int y, int n) {
        return x >= 0 and x < n and y >= 0 and y < n;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 or grid[n - 1][n - 1] == 1) {
            return -1;
        }
        queue<Node> q;
        q.push({0, 0, 1});
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        
        // all ways
        vector<int> rows{1, 0, 1, 0, -1, -1, 1, -1};
        vector<int> cols{1, 1, 0, -1, 0, -1, -1, 1};
        
        // BFS
        while (not q.empty()) {
            Node cur = q.front();
            q.pop();
            
            if (cur.x == n - 1 and cur.y == n - 1) { // Found destination
                return cur.val;
            }
            for (int i = 0; i < 8; ++i) { // All possible ways
                int curX = cur.x + rows[i];
                int curY = cur.y + cols[i];
                
                if (isValid(curX, curY, n) and not visited[curX][curY] and grid[curX][curY] == 0) {
                    visited[curX][curY] = 1;
                    q.push({curX, curY, cur.val + 1});
                }
            }
        }
        return -1;
    }
};
