/* https://leetcode.com/problems/matrix-block-sum/submissions/894896313/?envType=study-plan&id=dynamic-programming-i


Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n, k <= 100
1 <= mat[i][j] <= 100
*/

  
  
class Solution {
public:
    void print(const vector<vector<int>>& v) {
        for (auto row : v) {
            for (auto i : row) {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> sums(n, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                sums[i][j] = sums[i][j - 1] + mat[i][j - 1];
            }
        }
        print(sums);
        
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int minR = max(0, i - k);
                int maxR = min(n - 1, i + k);

                int minC = max(0, j - k);
                int maxC = min(m - 1, j + k);

                long long cur = 0;
                for (int z = minR; z <= maxR; ++z) {
                    cur += sums[z][maxC + 1] - sums[z][minC];
                }
                res[i][j] = cur;
            }
        }
        return res;
    }
};
