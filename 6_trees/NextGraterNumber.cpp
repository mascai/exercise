/*
Given a BST node, return the node which has value just greater than the given node.

Example:

Given the tree

               100
              /   \
            98    102
           /  \
         96    99
          \
           97

Given 97, you should return the node corresponding to 98 as thats the value just greater than 97 in the tree.
If there are no successor in the tree ( the value is the largest in the tree, return NULL).

Using recursion is not allowed.

Assume that the value is always present in the tree.
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
 
 TreeNode* Find(TreeNode *A, int B){
     if (!A){
         return NULL;
     } else if (B < A->val){
         return Find(A->left, B);
     } else if (B > A->val){
         return Find(A->right, B);
     } else {
         return A;
     }
     
 }
 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode *cur = Find(A, B);
    if (!cur){
        return NULL;
    }
    if (cur->right != NULL){
        cur = cur->right;
        while(cur->left){
            cur = cur->left;
        }
        return cur;
    } else {
        struct TreeNode* successor = NULL;
        struct TreeNode* ancessor = A; // start
        while(ancessor != cur){
            if (cur->val < ancessor->val){
                successor = ancessor;
                ancessor = ancessor->left;
            } else {
                ancessor = ancessor->right;
            }
        }
        return successor;
    }
    
}
