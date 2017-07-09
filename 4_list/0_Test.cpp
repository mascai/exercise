#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#define For(x,n) for(int x = 0; x < n; ++x)

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Длина списка
int Len(ListNode *head){
    int cnt = 0;
    while (head){
        head = head->next;
        ++cnt;
    }
    return cnt;
}

void Print(ListNode *l){
    while(l != NULL){
        cout << l->val << "  ";
        l = l->next;
    }
    cout << endl;
}

ListNode* VecToList(vector<int>v){
    if (v.size() == 0){
        return nullptr;
    }
    ListNode *head = new ListNode(v[0]);
    ListNode *p = head;
    for (size_t i = 1; i < v.size(); i++){
        ListNode *temp = new ListNode(v[i]);
        p->next = temp;
        p = p->next;
    }
    return head;
}

ListNode* ReverseList(ListNode *head){
    ListNode *prev = NULL, *curr = head, *next;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

ListNode* InsertPos(ListNode *head, int x, int pos){
    ListNode *tmp = new ListNode(x);
    if (pos == 0){
        if (head != NULL){
            tmp->next = head;
        }
        head = tmp;
        return head;
    }
    ListNode *prev = NULL, *p = head;
    int i = 0;
    while (p->next != NULL && i < pos - 1){
        p = p->next;
        i++;
    }
    if (p->next){ // not last element
        tmp->next = p->next;
    } else {
        tmp->next = NULL;
    }
    p->next = tmp;
    return head;
}

ListNode* DeletePos(ListNode *head, int pos){
    if (pos < 0 || pos > Len(head) - 1){
        cout << "Position out of bounds." << endl;
        return NULL;
    }
    int i = 0;
    ListNode *prev = head , *curr = head;
    if (pos == 0){
        prev = head;
        head = head->next;
        return head;
    }
    while (i < pos - 1 && prev->next){
        prev = prev->next;
        i++;
    }
    curr = prev->next;
    if (curr->next != NULL){
        prev->next = curr->next;
    } else {
        prev->next = NULL;
    }
    return head;
}

ListNode* merge(ListNode* A, ListNode* B){
    if(A == NULL){
        return B;
    }
    if(B == NULL){
        return A;
    }

    ListNode* head = NULL;

    if(A->val < B->val){
        head = A;
        A = A->next;
    }
    else{
        head = B;
        B = B->next;
    }

    ListNode* temp = head;

    while(A != NULL && B != NULL){
        if(A->val < B->val){
            temp->next = A;
            A = A->next;
        }
        else{
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }

    if(A != NULL){
        temp->next = A;
    }
    else{
        temp->next = B;
    }

    return head;
}

int main() {
    vector<int>v = {1, 2, 3, 4, 5};
    ListNode *head = VecToList(v);
    Print(head);
    //Print(InsertPos(head, 10, 5));
    Print(DeletePos(head, 5));
}
