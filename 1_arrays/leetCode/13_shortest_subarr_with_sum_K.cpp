/*
Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.

 

Example 1:

Input: A = [1], K = 1
Output: 1
Example 2:

Input: A = [1,2], K = 4
Output: -1
Example 3:

Input: A = [2,-1,2], K = 3
Output: 3
 

Note:

1 <= A.length <= 50000
-10 ^ 5 <= A[i] <= 10 ^ 5
1 <= K <= 10 ^ 9

*/



// Solution 1

class Solution {
   public:
   int shortestSubarray(vector<int> &A, int K) {
      int n = A.size();
      int ans = n + 1;
      int j = 0;
      int sum = 0;
      deque<int> dq;
      for (int i = 0; i < n; i++) {
         if (i > 0)
         A[i] += A[i - 1];
         if (A[i] >= K) {
            ans = min(ans, i + 1);
         }
         while (!dq.empty() && A[i] - A[dq.front()] >= K) {
            ans = min(ans, i - dq.front());
            dq.pop_front();
         }
         while (!dq.empty() && A[i] <= A[dq.back()])
         dq.pop_back();
         dq.push_back(i);
      }
      return ans == n + 1 ? -1 : ans;
   }
};

// Solution 2
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> pref(A.size() + 1, 0);
        int maxVal = INT_MIN;
        long long total = 0;
        for (int i = 1; i < A.size() + 1; ++i) {
            pref[i] = pref[i - 1] + A[i - 1]; 
            maxVal = max(maxVal, A[i - 1]);
            tota
        }
        if (maxVal >= K) {
            return 1;
        }
        int res = -1;

        for (int i = 0; i < A.size() + 1; ++i) {
            for (int j = i; j < A.size() + 1; ++j) {
                if (pref[j] - pref[i] >= K) {
                    if (res == -1 or res > j - i) {
                        res = j - i;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
