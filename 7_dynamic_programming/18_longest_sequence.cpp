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

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return max_len(dp, nums, 0, -1);
    }
    
    int max_len(vector<vector<int>>& dp, vector<int>& nums, int i, int prev) {
        if (i == nums.size()) {
            return 0;
        }
        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }
        int take = 0, donttake = max_len(dp, nums, i + 1, prev);
        if (prev == -1 or nums[i] > nums[prev]) {
            take = 1 + max_len(dp, nums, i + 1, i);
        }
        return dp[i][prev + 1] = max(take, donttake);
    }
};
