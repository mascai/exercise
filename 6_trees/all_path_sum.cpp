/* https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void foo(TreeNode* A, int B, vector<int> cur, vector<vector<int>>& res) {
    if (A != NULL) {
        B -= A->val;
        cur.push_back(A->val);
        if (A->left == NULL and A->right == NULL) { // is leaf
            if (B == 0) {
                res.push_back(cur);
            }
            return;
        }
        foo(A->left, B, cur, res);
        foo(A->right, B, cur, res);
    }
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> res;
    vector<int> cur;
    foo(A, B, cur, res);
    return res;
}
