/* https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3


*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* foo(const vector<int> &v, int l, int r) {
    if (l > r) {
        return NULL;
    }
    if (l == r) {
        return new TreeNode(v[l]);
    }
    int mid = (r + l) / 2;
    TreeNode *res = new TreeNode(v[mid]);
    res->left = foo(v, l, mid - 1);
    res->right = foo(v, mid + 1, r);
    return res;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    if (A.empty()) {
        return NULL;
    }
    return foo(A, 0, A.size() - 1);
}
