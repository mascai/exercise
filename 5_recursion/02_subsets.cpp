/*
https://leetcode.com/problems/subsets-ii/description/

Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/


class Solution {
public:
    void rec(vector<vector<int>>& res, int pos, vector<int>& cur, vector<int> nums) {
        res.push_back(cur);
        for (int i = pos; i < nums.size(); ++i) {
            if (i != pos and nums[i] == nums[i - 1]) {
                continue;
            }
            cur.push_back(nums[i]);
            rec(res, i + 1, cur, nums);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(begin(nums), end(nums));
        rec(res, 0, cur, nums);
        return res;
    }
};
