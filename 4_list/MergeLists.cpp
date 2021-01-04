/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15

The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20


*/



// Solution 1
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL and l2 == NULL) {
            return NULL;
        }
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* head;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        ListNode* cur = head;
        while (l1 or l2) {
            if (l1 == NULL) {
                cur->next = l2;
                break;
            }
            if (l2 == NULL) {
                cur->next = l1;
                break;
            }
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        return head;
    }
};


// Solution 2
class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            if(l1 == NULL) return l2;
            if(l2 == NULL) return l1;

            ListNode* head = NULL;    // head of the list to return

            // find first element (can use dummy node to put this part inside of the loop)
            if(l1->val < l2->val) { 
                head = l1; 
                l1 = l1->next; 
            } else { 
                head = l2; 
                l2 = l2->next; 
            }

            ListNode* p = head;     // pointer to form new list

            while(l1 && l2){
                if(l1->val < l2->val) { 
                    p->next = l1; 
                    l1 = l1->next; 
                } else { 
                    p->next = l2; 
                    l2 = l2->next; 
                }
                p = p->next;
            }

            // add the rest of the tail, done!
            if (l1) { 
                p->next=l1;
            } else {
                p->next=l2;
            }

            return head;
            }
};
