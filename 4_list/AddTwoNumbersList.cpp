/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int Len(ListNode *tmp){
    int cnt = 0;
    while(tmp){
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if (A == NULL){
        return B;
    }
    if (B == NULL){
        return A;
    }
    int A_sz = Len(A), B_sz = Len(B);
    ListNode *maxl = A, *minl = B;
    if (A_sz < B_sz){
        maxl = B;
        minl = A;
    }
    ListNode *head = maxl;
    int summ = 0, ten = 0;
    for (int i = 0; i < min(A_sz, B_sz); i++){
        summ = maxl->val + minl->val + ten;
        maxl->val = summ % 10;
        ten = summ / 10;
        maxl = maxl->next;
        minl = minl->next;
    }
    if (ten == 0){
        return head;
    }
    if (ten != 0 && A_sz != B_sz){
        for (int i = min(A_sz, B_sz); i < max(A_sz, B_sz); i++){
            summ = maxl->val + ten;
            maxl->val = summ % 10;
            ten = summ / 10;
            if (maxl->next == NULL){
                break;
            }
            maxl = maxl->next;
        }
    }
    if (ten != 0){
        ListNode *dec = new ListNode(ten);
        maxl->next = dec;
    }
    return head;
}
