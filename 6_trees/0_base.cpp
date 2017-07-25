#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* NewNode(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* InsertNode(Node* root, int data){
    if (!root){
        root = NewNode(data);
    } else if (data <= root->data){
        root->left = InsertNode(root->left, data);
    } else {
        root->right = InsertNode(root->right, data);
    }
    return root;
}

bool SearchNode(Node *root, int data){
    if (!root){
        return false;
    }
    if (data < root->data){
        return SearchNode(root->left, data);
    } else if (data > root->data){
        return SearchNode(root->right, data);
    } else {
        return true;
    }
}

void Print(Node *root){
    if (!root){
        return;
    }
    Print(root->left);
    cout << root->data << ' ';
    Print(root->right);
}

main() {
    Node *root = NULL;
    root = InsertNode(root,15);
	root = InsertNode(root,10);
	root = InsertNode(root,20);
	root = InsertNode(root,25);
	root = InsertNode(root,8);
    root = InsertNode(root,12);
    Print(root);
}
