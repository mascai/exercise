/** https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int solve(TreeNode* node, int curr_sum = 0) {
        if (node == nullptr) {
            return 0;
        }
        curr_sum = curr_sum * 10 + node->val;
        if (node->left == nullptr and node->right == nullptr) {
            return curr_sum;
        }
        return solve(node->left, curr_sum) + solve(node->right, curr_sum);
    }
    
    int sumNumbers(TreeNode* root) {
        return solve(root);
    }
};
