/*
https://leetcode.com/problems/longest-increasing-subsequence/submissions/

*/


// Solution 1 O(2^N)

class Solution {
public:
    int max_len(const vector<int>& nums, int cur_pos, int prev) {
        if (cur_pos == nums.size()) {
            return 0;
        }
        int take = 0;
        int donttake = max_len(nums, cur_pos + 1, prev);
        if (nums[cur_pos] > prev) {
            take = 1 + max_len(nums, cur_pos + 1, nums[cur_pos]);
        }
        return max(take, donttake);
    }
    int lengthOfLIS(vector<int>& nums) {
        return max_len(nums, 0, INT_MIN);
    }
};

// Solution 2 O(N^2)
