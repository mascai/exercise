/*
Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.

Notice that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return {1};
        }
        vector<int> prev {1, 1};
        if (rowIndex == 1) {
            return prev;
        }
        for (int i = 2; i <= rowIndex; ++i) {
            vector<int> cur(i+1);
            cur[0] = cur[i] = 1;
            for (int j = 1; j < i; ++j) {
                cur[j] = prev[j - 1] + prev[j];
            }
            prev = cur;
        }
        return prev;
    }
};
