/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node’s key.
    The right subtree of a node contains only nodes with keys greater than the node’s key.
    Both the left and right subtrees must also be binary search trees.

Example :

Input : 
   1
  /  \
 2    3

Output : 0 or False


Input : 
  2
 / \
1   3

Output : 1 or True 

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
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
bool IsSubtreeLess(TreeNode* root, int val){
    if (root == NULL){
        return true;
    }
    if (root->val < val && IsSubtreeLess(root->left, val) 
    && IsSubtreeLess(root->right, val)){
        return true;
    }
    return false; 
 }
 
bool IsSubtreeGrate(TreeNode* root, int val){
    if (root == NULL){
        return true;
    }
    if (root->val > val && IsSubtreeGrate(root->left, val) 
    && IsSubtreeGrate(root->right, val)){
        return true;
    }
    return false; 
 }
 
int Solution::isValidBST(TreeNode* root) {
    if (root == NULL){
        return true;
    }
    if (IsSubtreeLess(root->left, root->val) && IsSubtreeGrate(root->right, root->val)
        && isValidBST(root->left) && isValidBST(root->right)){
        
        return true;        
    } else {
        return false;
    }
}
