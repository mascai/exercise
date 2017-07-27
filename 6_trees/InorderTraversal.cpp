/*

Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3

return [1,3,2].

Using recursion is not allowed.

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
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int>ans;
    stack<TreeNode *>st;
    TreeNode *cur = A;
    while(!st.empty() || cur){
        if (cur){
            st.push(cur);
            cur = cur->left;
        } else {
            TreeNode *temp = st.top();
            ans.push_back(temp->val);
            st.pop();
            cur = temp->right;
        }
    }
    return ans;
}
