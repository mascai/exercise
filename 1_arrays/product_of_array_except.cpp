/*
https://leetcode.com/problems/product-of-array-except-self/

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt0 = count(begin(nums), end(nums), 0);
        vector<int> res(nums.size(), 0);
        if (cnt0 > 1) {
            return res;
        } else if (cnt0 == 1) {
            int cur = 1;
            int pos0 = -1;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i]) {
                    cur *= nums[i];
                } else {
                    pos0 = i;
                }
            }
            res[pos0] = cur;
        } else {
            int total = 1;
            for (auto i : nums) {
                total *= i;
            }
            for (int i = 0; i < nums.size(); ++i) {
                res[i] = total / nums[i];
            }
        }
        return res;
    }
};
