/*

*/

// Solution 1
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL and q == NULL) {
            return true;
        }
        if (p == NULL or q == NULL or
            p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};


// Solution 2
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
    string convert(TreeNode* p) {
        if (not p) {
            return "";
        }
        queue<TreeNode*> q;
        q.push(p);
        stringstream res;
        while (not q.empty()) {
            res << '@';
            auto* node = q.front();
            q.pop();
            res << node->val << '#';
            if (node->left) {
                res << '$';
                q.push(node->left);
            }
            if (node->right) {
                res << '&';
                q.push(node->right);
            }
        }
        return res.str();
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return convert(p) == convert(q);
    }
};
