"""
https://leetcode.com/problems/arithmetic-slices/?envType=study-plan&id=dynamic-programming-i

An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
Example 2:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000
"""

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3:
            return 0

        diffs = []
        for i in range(1, len(nums)):
            diffs.append(nums[i] - nums[i - 1])
        
        res = 0
        cnt = 0
        curr = diffs[0]
        for i in range(1, len(diffs)):
            if diffs[i] == curr:
                cnt += 1
                res += cnt
            else:
                cnt = 0
                curr = diffs[i]
        return res
