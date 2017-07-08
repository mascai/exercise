/*

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if (A == NULL || A->next == NULL){ // 0, 1 node
        return A;
    }
    ListNode *curr = A, *next = A->next;
    while (curr->next != NULL){
        while(curr->val == next->val){
            if(next->next == NULL){
                curr->next = NULL;
                return A;
            }
            next = next->next;
        }
        curr->next = next;
        curr = next;
    }    
    return A;
    
}
