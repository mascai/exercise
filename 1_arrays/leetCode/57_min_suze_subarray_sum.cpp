/*  https://leetcode.com/problems/minimum-size-subarray-sum/
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        int res = 0;
        for (int i = 0; i < prefixSum.size(); ++i) {
            for (int j = i; j < prefixSum.size(); ++j) {
                if (prefixSum[j] - prefixSum[i] >= target) {
                    if (res == 0) {
                        res = j - i;
                        break;
                    } else {
                        res = min(res, j - i);
                        break;
                    }
                }
            }
        }
        return res;
    }
};
