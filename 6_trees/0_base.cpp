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

int Height(Node *root){
    int h1 = 0, h2 = 0;
    if (root == NULL){
        return 0;
    }
    return 1 + max(Height(root->right), Height(root->left));
}

//returns width of level @k
int getWidth(Node *root, int k){
    if (root == NULL){
        return NULL;
    }
    if (k == 1){
        return 1;
    }  else if (k > 1){
        return getWidth(root->left, k-1) +  getWidth(root->right, k-1);
        getWidth(root->right, k - 1);
    }

}

int Width(Node* root){
    int maxWidth = 0;
    int curWidth = 0;
    int h = Height(root);
    for (int i = 1; i < h; i++){
        curWidth = getWidth(root, i);
        maxWidth = max(maxWidth, curWidth);
    }
    return maxWidth;
}


main() {
    Node *root = NULL;
    root = InsertNode(root,3);
    root = InsertNode(root,1);
	root = InsertNode(root,2);
	root = InsertNode(root,4);
	root = InsertNode(root,5);
    root = InsertNode(root,6);
    Print(root);

    cout << endl << Height(root) << endl;
    cout << Width(root) << endl;
}
