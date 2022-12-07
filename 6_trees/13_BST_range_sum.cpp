

/**
https://leetcode.com/problems/range-sum-of-bst/description/

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }

        long long res = 0;
        if (root->val < low) {
            res += rangeSumBST(root->right, low, high);
        } else if (root->val > high) {
            res += rangeSumBST(root->left, low, high);
        } else {
            res += root->val + rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high);
        }
        return res;
    }
};
