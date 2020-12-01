/*
https://leetcode.com/problems/number-of-ways-to-split-a-string/


Given a binary string s (a string consisting only of '0's and '1's), we can split s into 3 non-empty strings s1, s2, s3 (s1+ s2+ s3 = s).

Return the number of ways s can be split such that the number of characters '1' is the same in s1, s2, and s3.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: s = "10101"
Output: 4
Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
"1|010|1"
"1|01|01"
"10|10|1"
"10|1|01"
Example 2:

Input: s = "1001"
Output: 0
Example 3:

Input: s = "0000"
Output: 3
Explanation: There are three ways to split s in 3 parts.
"0|0|00"
"0|00|0"
"00|0|0"
Example 4:

Input: s = "100100010100110"
Output: 12
 

Constraints:

3 <= s.length <= 10^5
s[i] is '0' or '1'.


*/


class Solution {
public:
    int numWays(string s) {
        long long ones = 0;
        long long n = s.size();
        const int MOD = 1000000007;
        
        for (int i = 0; i < n; ++i) {
            ones += s[i] - '0';
        }
        if (ones == 0) {
            return ((n - 2) * (n - 1) / 2) % MOD;
        }
        if (ones % 3 != 0) {
            return 0;
        }
        long long cur = 0;
        long long ways1 = 0, ways2 = 0;
        for (auto ch : s) {
            cur += ch - '0';
            if (cur == ones / 3) {
                ways1++;
            }
            if (cur == ones * 2 / 3) {
                ways2++;
            }
        }
        return (ways1 * ways2) % MOD;
    }
};
