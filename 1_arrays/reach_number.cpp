/*


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

