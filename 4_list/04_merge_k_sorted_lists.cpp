/*
https://leetcode.com/problems/merge-k-sorted-lists/

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* point = head;
        
        auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.first > rhs.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                q.push({lists[i]->val, i});    
            }
        }
        while (not q.empty()) {
            auto [min_val, idx] = q.top();
            q.pop();

            point->next = lists[idx];
            point = point->next;
            
            lists[idx] = lists[idx]->next;
            if (lists[idx] != nullptr) {
                q.push({lists[idx]->val, idx});
            }
        }
        return head->next;
    }
    
};
