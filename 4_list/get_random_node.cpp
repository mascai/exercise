/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();

*/

#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    /** @param head_ The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    
    Solution(ListNode* head) {
        srand((unsigned) time(0));
        head_ = head;
    }
    
    int getLen() {
        int res = 0;
        ListNode* head = head_;
        while (head) {
            head = head->next;
            ++res;
        }
        return res;
    } 

    /** Returns a random node's value. */
    int getRandom() {
        int len = getLen();
        int randomNumber;
        randomNumber = (rand() % len) ;
        
        ListNode* copy = head_;
        int id = 0;
        while (copy and id < randomNumber) {
            copy = copy->next;
            ++id;
        }
        return copy->val;
    }
private:
    ListNode* head_;    
};

int main() {
    ListNode* head = new ListNode(1);
    Solution* obj = new Solution(head);
    ListNode* tail = new ListNode(2);
    head->next = tail;

    cout << "LEN " << obj->getLen() << endl;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 100; ++i) {
        auto temp = obj->getRandom();
        if (temp == 1) {
            ++cnt1;
        } else if (temp == 2) {
            ++cnt2;
        }
        
        cout << "Iteration" << i << " --- " << obj->getRandom() << endl;
    }
    cout << "----------\n";
    cout << "Result: " << "cnt1=" << cnt1 << " cnt2=" << cnt2 << endl; 
    return 0;
}
