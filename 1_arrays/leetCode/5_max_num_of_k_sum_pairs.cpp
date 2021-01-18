/*
You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109
*/


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (auto num : nums) {
            cnt[num]++;
        }
        int res = 0;
        for (auto iter = cnt.begin(); iter != cnt.end(); ++iter) {
            //cout << "------------\n";
            //cout << iter->first << ' ' << iter->second << endl;
            auto iter2 = cnt.find(k - iter->first);
            if (iter2 != cnt.end()) { // found
                //cout << "FOUND\n";
                if (iter == iter2) {
                    //cout << "EQUAL\n";
                    if (iter->second > 1) {
                        //cout << "ADDED\n";
                        res += iter->second / 2;
                        cnt[iter->first] -= iter->second / 2;
                    } 
                } else {
                    //cout << "COND " << iter->second << ' ' << iter2->second << endl;
                    if (iter->second > 0 and iter2->second > 0) {
                        int temp = min(iter->second, iter2->second);
                        res += temp;
                        cnt[iter->first] -= temp;
                        cnt[iter2->first] -= temp;
                    }
                }
            }
        }
        return res;
    }
};
