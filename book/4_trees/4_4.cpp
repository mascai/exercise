/*
Является ли дерево сбалансированным (разность высот правого и левого поддеревьев не больше 1)
*/

int Height(Node *root){
    if (root == NULL){
        return 0;
    }
    return 1 + max(Height(root->left), Height(root->right));
}

bool IsBalanceBST(Node *root){
    if (root == NULL){
        return true;
    }
    if (abs(Height(root->left) - Height(root->right)) > 1){
        return false;
    }
    return IsBalanceBST(root->left) && IsBalanceBST(root->right);
}
