/* https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3649/
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.

*/

class Solution {
public:
    // O(maxStrLen)
    bool check(const string& s, const string& pattern) {
        int len = 0;
        for (int i = 0; i < s.size() and len < pattern.size(); ++i) {
            if (pattern[len] == s[i]) {
                ++len;
            }
        }
        return len == pattern.size();
    }
    
    // O(VectorLen * maxStrLen)
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for (int i = 0; i < d.size(); ++i) {
            if (check(s, d[i])) {
                if (d[i].size() > res.size() or (d[i].size() == res.size() and d[i] < res)) {
                    res = d[i];
                }
            }
        }
        return res;
    }
};
