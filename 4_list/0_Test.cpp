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

void Print(ListNode *l){
    while(l != NULL){
        cout << l->val << "  ";
        l = l->next;
    }
    cout << endl;
}

ListNode* VecToList(vector<int>v){
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


int main() {
    vector<int>v = {1, 2, 4, 8, 16};
    ListNode *head = VecToList(v);
    Print(head);
    //Print(ReverseList(head));
}
