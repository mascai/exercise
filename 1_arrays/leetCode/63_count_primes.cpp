/*
Count primes less than n
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3738/
*/


class Solution {
public:
    
    int countPrimes(int n) {
        int res = 0;
        vector<int> cnt(n+1, 0);
        for (int i = 2; i < n; ++i) {
            if (cnt[i] == 0) {
                ++res;
                for (int j = i * 2; j < n; j += i) {
                    cnt[j] = 1;
                }
            }
        }
        return res;
    }
};
