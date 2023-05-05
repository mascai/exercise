/*
https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
*/

class Solution {
public:
    int is_vowel(const char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }

    int maxVowels(string s, int k) {
        int start = 0;
        int end = 1;
        int curr = is_vowel(s[0]);
        int res = curr;
        while (end < s.size()) {
            if (end - start + 1 > k) {
                curr -= is_vowel(s[start++]);
            }
            curr += is_vowel(s[end++]);
            res = max(res, curr);
        }
        return res;
    }
};
