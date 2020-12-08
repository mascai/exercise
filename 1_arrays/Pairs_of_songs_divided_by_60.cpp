/*
https://leetcode.com/explore/featured/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3559/

You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

 

Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
Example 2:

Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
 

Constraints:

1 <= time.length <= 6 * 104
1 <= time[i] <= 500
*/

// Solution 1
class Solution {
public:
    int comb2(int n) {
        return n * (n - 1) / 2;
    }
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, vector<int>> cnt; // offset, ids
        for (int i = 0; i < time.size(); ++i) {
            cnt[time[i] % 60].push_back(i);
        }
        int res = 0;
        if (cnt.find(0) != cnt.end()) {
            res += comb2(cnt[0].size());
        }
        if (cnt.find(30) != cnt.end()) {
            res += comb2(cnt[30].size());
        }
        for (auto [key, val] : cnt) {
            if (key != 0 and key != 30) {
                int key2 = 60 - key;
                auto it2 = cnt.find(key2);
                if (it2 != cnt.end() and key < key2) {
                    res += val.size() * (it2->second.size());
                }
            }
        }
        return res;
    }
};

// Solution 2 (editorials in Java)

class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int count = 0, n = time.length;
        for (int i = 0; i < n; i++) {
            // j starts with i+1 so that i is always to the left of j
            // to avoid repetitive counting
            for (int j = i + 1; j < n; j++) {
                if ((time[i] + time[j]) % 60 == 0) {
                    count++;
                }
            }
        }
        return count;
    }
}
