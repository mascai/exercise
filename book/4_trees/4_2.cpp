Node* CreateMinBST(vector<int>v, int start, int end);
Node* CreateMinBST(vector<int>v){
    return CreateMinBST(v, 0, v.size() - 1);
}

Node* CreateMinBST(vector<int>v, int start, int end){
    if (end < start){
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *n = new Node();
    n->data = v[mid];
    n->left = CreateMinBST(v, start, mid - 1);
    n->right = CreateMinBST(v, mid + 1, end);
    return n;
}

main() {
    Node *root = NULL;
    vector<int>v = {1, 2, 3, 4, 5, 6, 7};
    root = CreateMinBST(v);
    Print(root);
    cout << endl;
    cout << Width(root) << ' ' << Height(root) << endl;
}
