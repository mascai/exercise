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
    vector<vector<int>>ans;
    int sz = A.size();
    // fill the first row diagonals
    for (int j = 0; j < sz; j++) {
        int index_col = j;
        int index_row = 0;
        vector<int>curr;
        while (index_col >= 0) { // generate diagonal
            curr.push_back(A[index_row++][index_col--]);
        } 
        ans.push_back(curr);
    }
    // fill the last col diagonals
    for (int i = 1; i < sz; i++) {
        int index_col = sz - 1;
        int index_row = i;
        vector<int>curr;
        while (index_row < sz) { // generate diagonal
            curr.push_back(A[index_row++][index_col--]);
        } 
        ans.push_back(curr);
    }
    return ans;
}
