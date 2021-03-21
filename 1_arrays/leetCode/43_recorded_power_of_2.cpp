/*
Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

 

Example 1:

Input: 1
Output: true
Example 2:

Input: 10
Output: false
Example 3:

Input: 16
Output: true
Example 4:

Input: 24
Output: false
Example 5:

Input: 46
Output: true
 

Note:

1 <= N <= 10^9

*/


class Solution {
public:
    unordered_map<int, int> countDigits(int n) { // count digits in input number
        unordered_map<int, int> res;
        while (n > 0) { // assume that input n > 0
            res[n % 10]++;
            n /= 10;
        }
        return res;
    }
    
    bool reorderedPowerOf2(int N) {
        if (N == 1) {
            return true;
        }
        auto curNum = countDigits(N);
        for (int i = 1; i * 2 <= 1'000'000'000; i *= 2) { // overcome overflow
            if (curNum == countDigits(2 * i)) {
                return true;
            }
        }
        return false;
    }
};
