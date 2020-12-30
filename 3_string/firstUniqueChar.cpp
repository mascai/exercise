/*
https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/

Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
 
*/


class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> cnt; // <char, first index of the char>
        for (int i = 0; i < s.size(); ++i) {
            auto it = cnt.find(s[i]);
            if (it == cnt.end()) {
                cnt[s[i]] = i;
            } else {
                cnt[s[i]] = -1;
            }
        }
        int minId = s.size();
        for (auto [key, val] : cnt) {
            if (val != -1) {
                minId = min(minId, val);
            }
        }
        if (minId == s.size()) {
            return -1;
        }
        return minId;
    }
};
