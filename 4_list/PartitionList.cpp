/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
ListNode* Solution::partition(ListNode* head, int x) {
        if (!head) return NULL;
        ListNode * iterator = head;
        ListNode *start = new ListNode(0),
                 *tail = start,
                 *new_head = new ListNode(0),
                 *prev = new_head;
        new_head->next = head;
        
        while (iterator){
            if (iterator->val >= x){
                prev->next = iterator->next;
                tail->next = iterator;
                tail = tail->next;
                iterator = iterator->next;
                tail->next = NULL;
            } else {
                prev = iterator;
                iterator = iterator->next;
            }
        }
        prev->next = start->next;
        return new_head->next;
}   
