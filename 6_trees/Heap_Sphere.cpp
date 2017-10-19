/* Реализация бинарной кучи */

#include <bits/stdc++.h>

using namespace std;

struct bhnode {
    string data;
    int priority;
};

class binary_heap {
public:
    bhnode *body;
    int     bodysize;
    int     numnodes;
    binary_heap(int maxsize) {
        body = new bhnode[maxsize+1];
        bodysize = maxsize;
        numnodes = 0;
    }
    //~binary_heap();
    bhnode* fetchMin();
    int insert(bhnode node);
    void swap(int a, int b);
    void heapify(int index);

};


void binary_heap::swap(int a, int b) {
    bhnode temp = body[a];
    body[a] = body[b];
    body[b] = temp;
}

bhnode *binary_heap::fetchMin() {
    return numnodes == 0? NULL : body + 1;
}

int binary_heap::insert(bhnode node) {
    if (numnodes > bodysize) {
        return -1; // или расширяем.
    }
    body[++numnodes] = node;
    for (int i = numnodes; i > 1 &&
        body[i].priority > body[i/2].priority;
        i /= 2) {
        swap(i, i/2);

    }
}

void binary_heap::heapify(int index) {
    for (;;) {
    int left = index + index; int right = left + 1;
    // Кто больше, [index], [left], [right]?
    int largest = index;
    if (left <= numnodes && body[left].priority > body[index].priority)
        largest = left;
    if (right <= numnodes &&body[right].priority > body[largest].priority)
        largest = right;
    if (largest == index) break;
        swap(index, largest);
        index = largest;
    }
}

int main() {
    binary_heap* A = new binary_heap(5);
    A->insert({"a", 10});
}

