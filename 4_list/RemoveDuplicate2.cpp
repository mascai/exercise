/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL){
        return head;
    }
    ListNode *fakeHead = new ListNode(0);
    fakeHead->next = head;
    ListNode *curr = head, *prev = fakeHead;
    while(curr != NULL){
        while(curr->next != NULL && curr->val == curr->next->val){
            curr = curr->next;
        }
        if (prev->next == curr){
            prev = prev->next;
        } else {
            prev->next = curr->next;
        }
        curr = curr->next;
    }
    return fakeHead->next;
}
