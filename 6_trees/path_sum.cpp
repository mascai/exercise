/*
https://www.interviewbit.com/problems/path-sum/

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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


int Solution::hasPathSum(TreeNode* A, int B) {
    if (A == NULL) {
        return 0;
    }
    B -= A->val;
    if (A->left == NULL and A->right == NULL) {
        if (B == 0) {
            return 1;
        }
        return 0;
    }
    return hasPathSum(A->left, B) or hasPathSum(A->right, B);
}
