/*
https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/787/

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        int direction = 1;
        q.push(root);
        while (not q.empty()) {
            queue<TreeNode*> newq;
            vector<int> level;
            while (not q.empty()) {
                TreeNode* temp = q.front();
                level.push_back(temp->val);
                q.pop();
                
                if (temp->right) {
                    newq.push(temp->right);
                }
                if (temp->left) {
                    newq.push(temp->left);
                }
            }
            if (direction) {
                reverse(begin(level), end(level));
            }
            direction ^= 1;
            res.push_back(level);
            q = std::move(newq);
        }
        return res;
    }
};
