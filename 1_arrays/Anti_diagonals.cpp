/*

Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]


*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int N = A.size();
    int len = (N - 1) * 2 + 1;
    vector<vector<int>> res(len, vector<int>());
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            res[i+j].push_back(A[i][j]);
        }
    }
    return res;
}
