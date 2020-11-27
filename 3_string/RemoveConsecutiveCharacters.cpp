/*
Remove Consecutive Characters
https://www.interviewbit.com/problems/remove-consecutive-characters/

Problem Description

Given a string A and integer B, remove all consecutive same characters that have length exactly B.



Problem Constraints
1 <= |A| <= 100000

1 <= B <= |A|



Input Format
First Argument is string A.

Second argument is integer B.



Output Format
Return a string after doing the removals.



Example Input
Input 1:

A = "aabcd"
B = 2
Input 2:

A = "aabbccd"
B = 2


Example Output
Output 1:

 "bcd"
Output 2:

 "d"


Example Explanation
Explanation 1:

 "aa" had length 2.
Explanation 2:

 "aa", "bb" and "cc" had length of 2.

*/

string Solution::solve(string A, int B) {
    string res;
    int len = 0, curLen = 1;
    for (int i = 0; i < A.size(); ++i) {
        bool isInsert = true;
        curLen = 1;
        int pos = i;
        while (i + 1 < A.size() and A[i] == A[i + 1]) {
            ++i;
            ++curLen;
            if (curLen == B) {
                isInsert = false;
                break;
            }
        }
        if (isInsert) {
            res.insert(len, curLen, A[pos]);
            len += curLen;
        }
    }
    return res;
}
