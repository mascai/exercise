/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3583/

*/

// Solution 1 (recursion O(2^N)
class Solution {
public:
    
    int foo(int cur, int nstep, int target) {
        if (abs(cur) > abs(target)) {
            return INT_MAX;
        }
        if (cur == target) {
            return nstep;
        }
        int pos = foo(cur + (nstep + 1), nstep + 1, target);
        int neg = foo(cur - (nstep + 1), nstep + 1, target);
        return min(pos, neg);
    }
    
    int reachNumber(int target) {
        return foo(0, 0, target);
    }
};


// Solution 2 O(n)

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int res = 0;
        int curSum = 0;
        while (curSum < target or (target - curSum) % 2) {
            res++;
            curSum += res;
        }
        return res;
    }
};
