// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/

class Solution {
public:
    int cnt_neg(const vector<int>& v) {
        if (v.back() >= 0) {
            return 0;
        }
        int low = 0, high = v.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (v[mid] < 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return v.size() - low;

    }

    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            res += cnt_neg(grid[i]);
        }
        return res;
    }
};
