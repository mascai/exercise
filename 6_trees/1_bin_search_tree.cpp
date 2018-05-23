#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* new_node(int  _data) {
    Node *temp = new Node();
    temp->data = _data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert_node(Node *root, int data) {
    if (root == NULL) {
        root = new_node(data);
        return root;
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

bool search_node(Node *root, int data) {
    if (root == NULL) {
        return false;
    }
    if (data == root->data) {
        return true;
    }
    if (data <= root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}


int main() {
    Node *root = new Node();
    root = insert_node(root, 15);
    root = insert_node(root, 10);
    root = insert_node(root, 20);
    root = insert_node(root, 25);
    root = insert_node(root, 8);
    root = insert_node(root, 12);
    
    if (search_node(root, 111)) {
        cout << "Found " << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
