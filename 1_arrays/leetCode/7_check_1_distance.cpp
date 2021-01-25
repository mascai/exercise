/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3616/

*/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        if (k == 0) {
            return true;
        }
        int dist = 0;
        int start = 0; // first 1
        while (start < nums.size() and nums[start] == 0) {
            ++start;
        }
        if (start == nums.size()) {
            return true;
        }
        for (int i = start + 1; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++dist;
            } else {
                if (dist < k) {
                    return false;
                }
                dist = 0;
            }
        }
        return true;
    }
};
