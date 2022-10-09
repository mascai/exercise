/* https://leetcode.com/problems/permutations/submissions/

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/


class Solution {
public:
    void rec(vector<vector<int>>& res, vector<int>& vec, int cur_pos) {
        if (cur_pos == vec.size() - 1) {
            res.push_back(vec);
        }
        for (int j = cur_pos; j < vec.size(); ++j) {
            swap(vec[j], vec[cur_pos]);
            rec(res, vec, cur_pos + 1);
            swap(vec[j], vec[cur_pos]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        rec(res, nums, 0);
        return res;
    }
};
