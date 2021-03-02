/* https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3658/
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
 

Constraints:

2 <= nums.length <= 104
1 <= nums[i] <= 104

*/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) { // {1, 2, 2, 4}
        int n = nums.size();
        long long good = static_cast<long long>(n) * (1 + n) / 2; // 10
        long long bad = 0; // 9
        
        long long goodSquares = 0; // 30
        long long badSquares = 0; // 25
        for (int i = 1; i <= nums.size(); ++i) {
            bad += nums[i - 1];
            badSquares += nums[i - 1] * nums[i - 1];
            goodSquares += i * i;
            
        }
        
        int diff = good - bad; // missed - doubled = 1
        int summ = (goodSquares - badSquares) / diff; //  missed + doubled = 5
        int missed = (diff + summ) / 2; // 3
        int doubled = summ - missed; // 2
        return {doubled, missed};
    }
};
