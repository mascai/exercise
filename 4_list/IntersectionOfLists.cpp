/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

    Notes:

        If the two linked lists have no intersection at all, return null.
        The linked lists must retain their original structure after the function returns.
        You may assume there are no cycles anywhere in the entire linked structure.
        Your code should preferably run in O(n) time and use only O(1) memory.


*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 int Len (ListNode *A) {
    int cnt = 0;
    while (A != NULL) {
        cnt++;
        A = A->next;
    }
    return cnt;
 }
 
 ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) { // O(M + N)
    int m = Len(A);
    int n = Len(B);
    int d = n - m;
    if (m > n) {
        ListNode *tmp = A;
        A = B; 
        B = tmp;
        d = m - n;
    }
    for (int i = 0; i < d; i++) { 
        B = B->next;
    }
    while (A != NULL && B != NULL) { 
        if (A == B) {
            return A;
        }
        A = A->next;
        B = B->next;
    }
    return NULL;
}

 
 
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) { // O(m*n)
    int m = Len(A);
    int n = Len(B);
    ListNode *tmp = B;
    for (int i = 0; i < m; i++) {
        B = tmp;
        for (int j = 0; j < n; j++) {
            if (A == B) {
                return A;
            }
            B = B->next;
        }
        A = A->next;
    }
    return NULL;
}

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) { // O(M*logN + N*logM)
    int m = Len(A);
    int n = Len(B);
    set<ListNode* >addresses;
    for (int i = 0; i < n; i++) {
        addresses.insert(B);
        B = B->next;
    }
    for (int i = 0; i < m; i++) {
        if (addresses.find(A) != addresses.end()) {
            return A;
        }
        A = A->next;
    }
    return NULL;
}

