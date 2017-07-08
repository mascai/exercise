/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    while (tmp){
        tmp = tmp->next;
        cnt++;
    }
    return cnt;
} 
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int n = Len(A);
    B = B % n;
    if (B == 0){
        return A;
    }
    ListNode *p = A;
    for (int i = 0; i < n - B - 1; i++){
        p = p->next;
    }
    ListNode *tmp = p->next;
    p->next = NULL;
    ListNode *head = tmp;
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = A;
    return head;
}
