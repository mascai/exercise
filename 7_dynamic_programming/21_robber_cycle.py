"""https://leetcode.com/problems/house-robber-ii/submissions/886517100/?envType=study-plan&id=dynamic-programming-i

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000


"""


class Solution:
    def rob(self, nums: List[int]) -> int:
        def solve(nums):
            n = len(nums)

            dp = [0] * (n + 1)
            dp[0] = 0
            dp[1] = nums[0]
            for i in range(1, n):
                dp[i + 1] = max(dp[i], dp[i - 1] + nums[i])
            return dp[n]
        
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums)
        return max(solve(nums[1:]), solve(nums[:-1]))
