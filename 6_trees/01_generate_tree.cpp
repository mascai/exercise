/*
	Обход раскрашенного дерева
На вход задачи подаётся дерево, каждый узел которого покрашен в белый,
чёрный или серый цвет. Необходимо найти сколько вершин на путях от корня к листьям
имеют белый цвет, при условии что до попадания в белую вершину путь прошёл через
чёрную.
	Input format
Деревья закодированы скобочными выражениями.
После открывающей скобки идёт цвет вершины b, w или g и если у узла есть потомки,
то потомки перечислены через запятую. Длина описания дерева не превосходит 10000
символов.
	Output format
N – число искомых вершин
	Examples
Input					Output
(g,(w),(b,(w),(g,(w))),(b,(w)))
					3
(w,(b),(b,(g,(w),(b))))
					1
*/


#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char color;
    vector<Node*>children;
    Node *parent;
    Node (Node *_parent) : parent(_parent) {}
};

Node* create_node(Node *root = nullptr) {
    char ch;
    Node *temp;
    while (cin >> ch) {
        switch(ch) {
            case '(':
                temp = new Node(root);
                break;
            case 'g':
                temp->color = 'g';
                break;
            case 'w':
                temp->color = 'w';
                break;
            case 'b':
                temp->color = 'b';
                break;
            case ')':
                return temp;
            case ',':
                temp->children.push_back(create_node(temp));
                break;
            default:
                cout << "Bad input: " << ch << endl;
        }
    }
}

void print_tree(Node *root) {
	cout << '(' << root->color;
	for (int i=0; i< root->children.size(); i++) {
		cout << ',';
		print_tree(root->children[i]);
	}
	cout << ')';
}

int find_white_node(Node *root, bool flag) {
    int ans = 0;
    if (root->color == 'b') {
        flag = 1;
    }
    if (root->color == 'w' && flag) {
        ans++;
    }
    for (int i = 0; i < root->children.size(); i++) {
        ans += find_white_node(root->children[i], flag);
    }
    return ans;
}

int main() {
    Node *root;
    root = create_node();
    cout << find_white_node(root, false);
}
