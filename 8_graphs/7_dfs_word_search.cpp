/*
Given an m x n board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 200
1 <= word.length <= 103
board and word consists only of lowercase and uppercase English letters.

*/

class Solution {
public:
    bool dfs (vector<vector<char>>& board, string &word, int col, int row, int beg)
    {
        bool res(false);
        if (board[col][row] == word[beg])
        {
            if (beg >= word.size() - 1) {
                return true;
            }
            char temp (board[col][row]);
            board[col][row] = '*';
            if (col+1<board.size() && dfs(board,word,col+1,row,beg+1))
                res = true;
            else if (col>0 && dfs(board,word,col-1,row,beg+1))
                res = true;
            else if (row+1 < board[0].size() && dfs(board,word,col,row+1,beg+1))
                res = true;
            else if (row>0 && dfs(board,word,col,row-1,beg+1))
                res = true;
            board[col][row] = temp;
        }
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i(0);i!=board.size();++i)
            for (int j(0);j!=board[i].size();++j)
                if (dfs(board,word,i,j,0))
                    return true;
        return false;
    }
};
