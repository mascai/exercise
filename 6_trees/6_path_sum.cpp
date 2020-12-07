/*
https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/537/

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

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

// Solution 1
class Solution {    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && sum == root->val)return true;
        int s = sum - root->val;
        return hasPathSum(root->left, s) || hasPathSum(root->right, s);
    }
};
 
// Solution 2
class Solution {
public:
    void preOrder(TreeNode* root, int sum, bool& res) {
        if (root) {
            sum -= root->val;
            if (root->left == NULL and root->right == NULL) {
                if (sum == 0) {
                    res = true;
                }
            }
            preOrder(root->left, sum, res);
            preOrder(root->right, sum, res);
        }    
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        bool res = false;
        preOrder(root, sum, res);
        return res;
    }
};
