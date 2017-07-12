
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

    Note:
    Given m, n satisfy the following condition:
    1 ≤ m ≤ n ≤ length of list
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
vector<ListNode*>Reverse(ListNode *head){
    vector<ListNode*>ans; // {end, start)
    ListNode *start  = head, *curr = head, *prev = NULL, *next;
    ans.push_back(start);
    while (curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    ans.push_back(head);
    return ans;
}
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    if (A == NULL || A->next == NULL){
        return A;
    } 
    ListNode *p = A, *before_start = NULL, *after_end = NULL;
    for (int i = 0; i < m - 1; i++){
        before_start = p;
        p = p->next;
    }
    ListNode *start = p;
    p = A;
    for (int i = 0; i < n - 1; i++){
        p = p->next;
    }
    if (p->next != NULL){
        after_end = p->next;
        p->next = NULL;
    }
    vector<ListNode*>ans = Reverse(start);
    if (before_start == NULL){
        A = ans[1];
    } else {
        before_start->next = ans[1];
    }
    if (after_end){
        ListNode *tmp = ans[0];
        tmp->next = after_end;
    }
    return A;
}
