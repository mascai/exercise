/* https://leetcode.com/problems/copy-list-with-random-pointer/

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
 

Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
The number of nodes will not exceed 1000.

*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// Solution 1
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* fakeHead = new Node(-1);
        Node* curOld = head;
        Node* curNew = fakeHead;
        unordered_map<Node*, Node*> nodes; 
        // copy value
        while (curOld) {
            curNew->next = new Node(curOld->val);
            nodes[curOld] = curNew->next;
            curNew = curNew->next;
            curOld = curOld->next;
        }
        
        // copy random ptr
        curOld = head;
        curNew = fakeHead;
        while (curOld) {
            if (curOld->random) {
                curNew->next->random = nodes[curOld->random];
            }
            curNew = curNew->next;
            curOld = curOld->next;
        }
        return fakeHead->next;
    }
};

// Solution2
class Solution {
public:
    Node* foo(Node* cur, unordered_map<Node*, Node*>& m) {
        if (cur == NULL) {
            return cur;
        }
        auto iter = m.find(cur);
        if (iter != m.end()) {
            return m[cur];
        }
        Node* newNode = new Node(cur->val);
        m[cur] = newNode;
        newNode->next = foo(cur->next, m);
        newNode->random = foo(cur->random, m);
        return newNode;
        
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        return foo(head, m);
    }
};
