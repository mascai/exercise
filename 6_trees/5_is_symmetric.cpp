/*
https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/536/


Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.
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
class Solution {
public:
    bool check(TreeNode* l, TreeNode* r) {
        if (r == NULL and l == NULL) {
            return true;
        }
        if (r and l and r->val == l->val) {
            return check(l->left, r->right) and check(l->right, r->left);
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
