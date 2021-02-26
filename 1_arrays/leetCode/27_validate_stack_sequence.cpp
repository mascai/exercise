/* https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3653/
Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 

Constraints:

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed is a permutation of popped.
pushed and popped have distinct values.


*/

/* O(1) space solution

Please, upvote this solution

The algorithm: (vector ```pushed``` emulates stack, ```pushId``` emulates size of the stack)
1) At i iteration place pushed[i] at the top of the stask. 
2) While pushed[pushId] == popped[poppId]. Pop top-element of the stack
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pushId = -1, poppId = 0;
        for (int i = 0; i < pushed.size(); ++i) {
            pushed[++pushId] = pushed[i];
            while (pushId >= 0 and pushed[pushId] == popped[poppId]) {
                --pushId;
                ++poppId;
            }
        }
        return pushId == -1;
    }
};


// O(N) space solution
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        stack<int> st;
        for (int z = 0; z < pushed.size(); ++z) {
            st.push(pushed[z]);
            while (not st.empty() and i < popped.size() and st.top() == popped[i]) {
                st.pop();
                ++i;
            }
        }
        return st.empty();
    }
};
