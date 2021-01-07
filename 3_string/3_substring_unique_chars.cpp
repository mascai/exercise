/*
https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/779/

Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = -1;
        int res = 0;
        int n = s.size();
        unordered_map<char, int> cnt;
        for (int i = 0; i < n; ++i) {
            if (cnt.count(s[i]) and cnt[s[i]] > start) {
                start = cnt[s[i]];
            }
            cnt[s[i]] = i;
            res = max(res, i - start);
        }
        return res;
    }
};

// Solution 2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cnt;
        int res = 0;
        if (s.empty()) {
            return res;
        }
        for (int i = 0; i < s.size(); ++i) {
            cnt.insert(s[i]);
            int len = 1;
            while (i + len < s.size() and cnt.find(s[i + len]) == cnt.end()) {
                cnt.insert(s[i + len]);
                ++len;
            }
            res = max(res, len);
            cnt.clear();
        }
        return res;
    }
};
