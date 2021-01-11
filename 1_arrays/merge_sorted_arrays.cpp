/*

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]


*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        for (int i = m; i < m + n; ++i) {
            nums1[i] = INT_MAX;
        }
        while (i < n + m and j < n) {
            if (nums1[i] > nums2[j]) {
                for (int k = m + n - 1; k > i; --k) {
                    nums1[k] = nums1[k - 1];
                }
                nums1[i++] = nums2[j++];
            } else {
                ++i;
            }
           
        }
    }
};
