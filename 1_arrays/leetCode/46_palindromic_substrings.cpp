/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.

*/


class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            res += countPalindroms(s, i, i);
            res += countPalindroms(s, i, i + 1);
        }
        return res;
    }
    
    int countPalindroms(const string& s, int l, int r) {
        int res = 0;
        while (l >= 0 and r < s.size() and s[l] == s[r]) {
            --l;
            ++r;
            res++;
        }
        return res;
    }
};
