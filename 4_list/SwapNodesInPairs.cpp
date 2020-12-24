/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes. Only nodes itself may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swap(ListNode* prev, ListNode* next) {
        ListNode* temp = next->next;
        next->next = prev;
        prev->next = temp;
        return next;
    }
    
    ListNode* swapPairs(ListNode* head) {
        ListNode* fake = new ListNode(0);
        fake->next = head;
        ListNode* cur = fake;
        while (cur->next and cur->next->next) {
            cur->next = swap(cur->next, cur->next->next);
            cur = cur->next->next;
        }
        return fake->next;
    }
};
