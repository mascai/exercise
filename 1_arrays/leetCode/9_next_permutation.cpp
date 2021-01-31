/* https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/583/week-5-january-29th-january-31st/3623/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]

*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    // 1 2 3 4 -- > 1 2 4 3
    // 1 4 2 3 -- > 1 4 3 2
    // 1 4 3 2 -- > 4 1 2 3 
        int i = -1, j;
        for (i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i == -1) {
            reverse(begin(nums), end(nums));
        } else {
            for (j = nums.size() - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    break;
                }
            }
            swap(nums[i], nums[j]);
            reverse(begin(nums) + i + 1, end(nums));
        }
    }
};
