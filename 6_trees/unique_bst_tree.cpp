/*
https://leetcode.com/problems/unique-binary-search-trees/

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:

1 <= n <= 19

*/


class Solution {
public:
    int numTrees(int n) {
        vector<int> v(n+1);
        v[0] = 1;
        v[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= i - 1; ++j) {
                v[i] += v[j] * v[i - j - 1];
            }
        }
        return v[n];
    }
};
