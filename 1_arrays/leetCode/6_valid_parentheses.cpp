/* https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3610/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> cnt;
        for (auto ch : s) {
            if (ch == '(' or ch == '[' or ch == '{') {
                cnt.push(ch);
            } else {
                if (cnt.empty()) {
                    return false;
                }
                if (ch == ')' and cnt.top() == '(' or
                    ch == ']' and cnt.top() == '[' or
                    ch == '}' and cnt.top() == '{') {
                    cnt.pop();
                } else {
                    return false;
                }
            }
        }
        return cnt.empty();
    }
};
