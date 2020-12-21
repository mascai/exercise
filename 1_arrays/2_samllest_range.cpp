/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3573/

Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, and add x to A[i] (only once).

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.

 

Example 1:

Input: A = [1], K = 0
Output: 0
Explanation: B = [1]
Example 2:

Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]
Example 3:

Input: A = [1,3,6], K = 3
Output: 3
Explanation: B = [4,6,3]
 

Note:

1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000

*/


class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        if (A.size() < 2) {
            return 0;
        }
        int n = A.size();
        sort(begin(A), end(A));
        int mx, mn;
        int right = A[n - 1] - K;
        int left = A[0] + K;
        int res = A[n - 1] - A[0];
        for (int i = 0; i < n - 1; ++i) {
            mx = max(right, A[i] + K);
            mn = min(left, A[i + 1] - K);
            res = min(res, mx - mn);
        }
        return res;
    }
};
