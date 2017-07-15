/*
Reverse a linked list using recursion.

Example :
Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode *head;
ListNode* Solution::reverseList(ListNode* p) {
    if (p->next == NULL || p == NULL) {
        return p;
    }
    ListNode *nextNode = p->next;
    ListNode *head = reverseList(p->next);
    nextNode->next = p;
    p->next = NULL;

    return head;
}
