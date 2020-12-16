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

/////////////////// O(N) solution
bool CheckBST(TreeNode *root){
    return CheckBST(root, INT_MIN, INT_MAX);
}

bool CheckBST(TreeNode *root, int l, int r){
    if (root == NULL){
        return true;
    }
    if (root->data <= l || root->data > r){
        return false;
    }
    if (!CheckBST(root->left, l, root->data)
     || !CheckBST(root->right, root->data, r)){
        return false;
    }
    return true;
}

/////////////////////////// O(N *log(N)) solution

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


// https://leetcode.com/problems/validate-binary-search-tree/solution/
// Solution 3
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool foo(TreeNode* root, long long l, long long r) {
        if (root == NULL) {
            return true;
        }
        if (root->val <= l or root->val >= r) {
            return false;
        }
        return foo(root->left, l, root->val) and
               foo(root->right, root->val, r);
    }
    bool isValidBST(TreeNode* root) {
        long long mmin = numeric_limits<long long>::min();
        long long mmax = numeric_limits<long long>::max();
        return foo(root, mmin, mmax);
    }
};
