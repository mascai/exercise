/* https://leetcode.com/problems/minimum-size-subarray-sum/description/

Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

*/


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int res = INT_MAX;
        bool flag = false;
        long long curr_sum = 0;

        while (start <= end and start < nums.size()) {
            while (end < nums.size() and curr_sum < target) {
                curr_sum += nums[end++];
            }

            //cout << start << "  " << end << " Sum=" << curr_sum << endl;
            if (curr_sum >= target) {
                res = min(res, end - start);
                flag = true;
            } else {
                break;
            }
            curr_sum -= nums[start];
            start++;

             
        }
        if (flag) {
            return res;
        }
        return 0;
    }
};
