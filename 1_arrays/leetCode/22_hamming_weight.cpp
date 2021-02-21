// https://leetcode.com/problems/number-of-1-bits/submissions/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n > 0) {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};
