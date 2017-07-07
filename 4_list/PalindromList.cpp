/*


Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:
- Expected solution is linear in time and constant in space.

For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.


*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* Reverse(ListNode* head) {
    ListNode *prev, *curr, *next;
    curr = head;
    prev = NULL;
    while (curr != NULL) { 
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

 int Len (ListNode *A) {
    int cnt = 0;
    while (A != NULL) {
        cnt++;
        A = A->next;
    }
    return cnt;
 }

int Solution::lPalin(ListNode* a) {
    int n = Len(a);
    ListNode *mid = a;
    for (int i = 0; i < n / 2 ; i++){
        mid = mid->next;
    }
    ListNode *rev = Reverse(mid);
    for (int i = 0; i < n / 2; i++){
        if(a->val != rev->val){
            return 0;
        } 
        a = a->next;
        rev = rev->next;
    }
    return 1;
}
