/*
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/

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
    void dfs(TreeNode* root, size_t& bits, size_t& res) {
        if (root == nullptr) {
            return;
        }
        bits <<= 1;
        bits |= root->val;
        if (root->left == nullptr and root->right == nullptr) {
            res += bits;
        }
        dfs(root->left, bits, res);
        dfs(root->right, bits, res);
        bits >>= 1;
    }

    int sumRootToLeaf(TreeNode* root) {
        size_t res = 0;
        size_t bits = 0;
        dfs(root, bits, res);
        return res;
    }
};
