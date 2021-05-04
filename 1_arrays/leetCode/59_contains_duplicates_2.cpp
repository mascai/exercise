/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> cnt;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = cnt.find(nums[i]);
            if (iter != cnt.end()) {
                for (auto elem : iter->second) {
                    if (abs(elem - i) <= k) {
                        return true;
                    }
                }
            }
            cnt[nums[i]].push_back(i);
        }
        return false;
    }
};
