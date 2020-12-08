/*
https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/942/

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7


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
    TreeNode* helper(vector<int>& inorder, int iStart, int iEnd, vector<int>& postorder, int pStart, int pEnd){
        if (iEnd < iStart or pEnd < pStart) {
            return NULL;
        }
        int cur = postorder[pEnd];
        TreeNode* head = new TreeNode(cur);
        int val = 0;
        while (head->val != inorder[val]) {
            ++val;
        }
        head->left = helper(inorder, iStart, val-1, postorder, pStart, val+pStart-iStart-1);
        head->right = helper(inorder, val+1, iEnd, postorder, val+pStart-iStart, pEnd-1);
        return head;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
