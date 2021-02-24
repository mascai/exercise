/**
Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6

*/


class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0;
        stack<int> s;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                s.push(-1);
            } else {
                if (s.top() == -1) {
                    s.pop();
                    s.push(1);
                } else {
                    int x = 0;
                    while (s.top() != -1) {
                        x += s.top();
                        s.pop();
                    }
                    x *= 2;
                    s.pop();
                    s.push(x);
                }
            }
        }
        while (not s.empty()) {
            res += s.top();
            s.pop();
        }
        return res;
    }
};
