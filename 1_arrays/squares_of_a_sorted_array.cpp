/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

*/

// Solution 1
// O(n) - time
// O(n) - space
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res, negative, positive;
        partition_copy(
            cbegin(nums), cend(nums), 
            back_inserter(negative), back_inserter(positive), 
            [](int n) {return n < 0;}
        );
        for (auto& i : negative) {
            i *= i;
        }
        for (auto& i : positive) {
            i *= i;
        }
        merge(
            crbegin(negative), crend(negative),
            cbegin(positive), cend(positive),
            back_inserter(res)
        );
        return res;
    }
};

// Solution 2 
// O(n * log(n))
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        sort(begin(nums), end(nums), [](int l, int r) {
            return l * l < r * r;
        });
        for (auto& i : nums) {
            i *= i;
        }
        return nums;
    }
};
