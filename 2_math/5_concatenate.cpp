/*
Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

 

Example 1:

Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1. 
Example 2:

Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
Example 3:

Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 109 + 7, the result is 505379714.
 

Constraints:

1 <= n <= 105


*/

// Solution 1

// O(n)
class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        int64_t res = 0;
        for (int i = 1; i <= n; ++i) {
            int curLen = ceil(log2(i + 1));
            res = ((res << curLen) + i) % MOD;
        }
        return res;
    }
};

// Solution2
// O(n * log2(n))
class Solution {
public:
    int concatenatedBinary(int n) {
        /*
        1 -- 1
        2 -- 110
        3 -- 11011
        
        F(n) = F(n - 1) + binary(n)
        */
        int res = 0;
        int curPow = 0;
        for (int i = n; i >= 1; --i) {
            int j = i;
            while (j > 0) {
                if (j % 2) {
                    res += pow(2, curPow);
                }
                ++curPow;
                j /= 2;
            }
        }
        return res;
    }
};
