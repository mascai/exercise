/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3643/
*/


class Solution {
public:
    int get_water(const vector<int>& v, int l, int r) {
        return min(v[r], v[l]) * (r - l);
    }
    
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        
        int res = 0;
        while (l < r) {
            res = max(res, get_water(height, l, r));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};
