/* https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3603/
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
*/


// Solution2 
// O(2^N)
class Solution {
public:
    void foo(const vector<int>& v, int x, int cur, int& res, int l, int r) {
        if (x == 0) {
            res = min(res, cur);
        }
        if (x > 0 and l <= r) {
            cur++;
            foo(v, x - v[l], cur, res, l + 1, r);
            foo(v, x - v[r], cur, res, l, r - 1);
        }
    }
    int minOperations(vector<int>& nums, int x) {
        int cur = 0, res = INT_MAX;
        foo(nums, x, cur, res, 0, nums.size() - 1);
        if (res == INT_MAX) {
            return -1;
        }
        return res;
    }
};
