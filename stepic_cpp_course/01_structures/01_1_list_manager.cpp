/*
Реализуйте контейнер, обрабатывающий следующие запросы:

1. insert val after pos - вставить элемент со значением val после элемента с номером pos (в 0 индексации). 

При вставке в начало pos = -1.

2. erase after pos - удалить элемент, идущий после элемента с номером pos (в 0 индексации). 

При удалении из начала pos = -1.

3.  get pos - вернуть значение элемента с номером pos (в 0 индексации). 

Входные данные
В первой строке вводится одно целое число  - количество запросов m.

0 \leqslant  m \leqslant 10000⩽ m⩽1000.

В каждой из следующих m строк содержится целое число от 1 до 3 - номер запроса, и целое число pos.

Для запроса 1 типа так же вводится значение |val| \leqslant 1000∣val∣⩽1000.

Гарантируется, что все запросы корректны.

Выходные данные
Для запросов 3 типа выведите ответ на запрос - каждый в отдельной строке.

Sample Input:

10
1 -1 2
1 0 3
1 1 4
3 0
3 1
3 2
2 0
2 0
3 0
2 -1
Sample Output:

2
3
4
2
*/


#include <bits/stdc++.h>

using namespace std;
  
enum class Mode {
    INSERT = 1,
    ERASE = 2,
    GET = 3
};


struct Node {
    Node(int v) : val(v), next(nullptr) {}
    int val;
    Node* next;
};


class List {
public:
    List() {
        fakeHead_ = new Node(-1);
    }

    ~List() {
        while (fakeHead_) {
            Node* cur = fakeHead_;
            fakeHead_ = fakeHead_->next;
            delete cur;
        }
    }

    void insertAfter(int pos, int val) {
        int curPos = -1;
        Node* curNode = fakeHead_;
        while (curPos < pos) {
            curNode = curNode->next;
            ++curPos;
        }
        Node* newNode = new Node(val);
        if (curNode->next) {
            newNode->next = curNode->next;  
        }
        curNode->next = newNode;
    }

    void eraseAfter(int pos) {
        int curPos = -1;
        Node* curNode = fakeHead_;
        while (curPos < pos) {
            curNode = curNode->next;
            ++curPos;
        }
        if (curNode->next) {
            Node* toDelete = curNode->next;
            curNode->next = curNode->next->next;
            delete toDelete;  
        }
    }

    int getElement(int pos) {
        int curPos = 0;
        Node* curNode = fakeHead_->next;
        while (curNode and curPos < pos) {
            curNode = curNode->next;
            ++curPos;
        }
        if (curPos < pos) {
            throw std::runtime_error("Length of list less than pos");
        }
        return curNode->val;
    }

private:
    Node* fakeHead_ = nullptr;
};

int main()
{
    int m, mode;
    int val, pos;
    List list;

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> mode;
        cin >> pos;
        if (mode == static_cast<int>(Mode::INSERT)) {
            cin >> val;
            list.insertAfter(pos, val);
        } else if (mode == static_cast<int>(Mode::ERASE)) {
            list.eraseAfter(pos);
        } else if (mode == static_cast<int>(Mode::GET)) {
            cout << list.getElement(pos) << ' '; 
        }
    }
}
