/*

https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/931/
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while (not q.empty()) {
            int sz = q.size();
            vector<int> level;
            for (auto j = 0; j < sz; ++j) {
                auto curNode = q.front();
                q.pop();
                level.push_back(curNode->val);
                if (curNode->left) {
                    q.push(curNode->left);
                }
                if (curNode->right) {
                    q.push(curNode->right);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};
