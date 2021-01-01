/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur1 = head;
        ListNode* cur2 = head;
        
        int i;
        for (i = 0; i <= n and cur1; ++i) {
            cur1 = cur1->next;
        }
        if (i == n and cur1 == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while (cur1) {
            cur2 = cur2->next;
            cur1 = cur1->next;
        }
        ListNode* temp = cur2->next;;
        cur2->next = cur2->next->next;
        delete temp;
        return head;
    }
};
