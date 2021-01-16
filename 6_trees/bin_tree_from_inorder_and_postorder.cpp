/*
https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return : 
            1
           / \
          2   3
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
TreeNode* foo(const vector<int> &A, vector<int> &B, int l1 , int r1, int l2, int r2) {
    if (l2 > r2) {
        return NULL;
    }
    TreeNode *root = new TreeNode(B[r2]);
    size_t pos = find(begin(A) + l1, begin(A) + r1 + 1, root->val) - begin(A); // assume that val in the vector
    root->left = foo(A, B, l1, pos - 1, l2, l2 + pos - l1 - 1);
    root->right = foo(A, B, pos + 1, r1, r2 - r1 + pos, r2 - 1);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    if (A.empty()) {
        return NULL;
    }
    return foo(A, B, 0, A.size() - 1, 0, B.size() - 1);
}
