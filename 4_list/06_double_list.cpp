/*
https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/
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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* rev_head = reverse(head);
        ListNode* curr = rev_head;
        int carry = 0;
        
        while (true) {
            cout << "curr->val: " << curr->val << endl;
            int val = (curr->val * 2) + carry;
            curr->val = val % 10;
            carry = val / 10;
            
            if (curr->next == NULL) {
                break;
            }
            curr = curr->next;
        }
        if (carry) {
            ListNode* new_head = new ListNode(carry);
            curr->next = new_head;
            curr = curr->next;
        }
        return reverse(rev_head);
    }
};
