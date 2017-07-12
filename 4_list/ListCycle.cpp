/*


Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if (A == NULL || A->next == NULL){
        return NULL;
    }
    ListNode *slow = A, *fast = A;
    while(slow && fast){
        slow = slow->next;
        if (fast->next == NULL){
            return NULL;
        } else {
            fast = fast->next->next;
        }
        if (slow == fast){
            break;
        }
    }
    if (fast == NULL || slow == NULL){
        return NULL;
    }
    ListNode *curr = A;
    while (curr){
        if (curr == fast){
            return curr;
        }
        curr = curr->next;
        fast = fast->next;
    }
}
