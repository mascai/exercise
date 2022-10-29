/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100

*/


// Solution 1 O(V + E)
int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        rec(root, d);
        return d;
    }
    
    int rec(TreeNode* root, int &d) {
        if(root == NULL) return 0;
        int ld = rec(root->left, d);
        int rd = rec(root->right, d);
        d=max(d,ld+rd);
        return max(ld,rd)+1;
    }
}

// Solution 2

class Solution {
public:
    void rec(TreeNode* root, int& res, unordered_map<TreeNode*, int>& memo) {
        if (root == nullptr) {
            return;
        }
        res = max(res, memo[root->left] + memo[root->right] + 1);
        rec(root->left, res, memo);
        rec(root->right, res, memo);
    }

    int calculate_len(TreeNode* node, unordered_map<TreeNode*, int>& memo) {
        if (node == nullptr) {
            return 0;
        }
        int len_left = calculate_len(node->left, memo) + 1;
        int len_right = calculate_len(node->right, memo) + 1;
        memo[node] = max(len_left, len_right);
        return  max(len_left, len_right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        unordered_map<TreeNode*, int> memo;
        calculate_len(root, memo);
        
        rec(root, res, memo);
        return res - 1;
    }
};
