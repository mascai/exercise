/*
https://leetcode.com/problems/triangle/?envType=study-plan&id=algorithm-i


Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/

class Solution {
public:
    int dfs(int i, int j, int n, vector<vector<int>>& memo, const vector<vector<int>>& v) {
        if (i == n) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int left = v[i][j] + dfs(i + 1, j, n, memo, v);
        int right = v[i][j] + dfs(i + 1, j + 1, n, memo, v);
        memo[i][j] = min(left, right);
        return memo[i][j];
        
    }
        
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(0, 0, n, memo, triangle);
    }
};
