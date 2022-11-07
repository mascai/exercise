/*
https://leetcode.com/problems/interval-list-intersections/?envType=study-plan&id=algorithm-ii

You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

 
*/


class Solution {
public:
    vector<int> get_intersection(vector<int> l, vector<int> r) {
        // get intersection of two ranges
        if (l[0] > r[0]) {
            swap(l, r);
        }
        if (l[1] < r[0]) {
            return {};
        }
        return  {r[0], min(l[1], r[1])};
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0;
        int j = 0;
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>> res;
        while (i < n and j < m) {
            const vector<int> curr = get_intersection(firstList[i], secondList[j]);
            if (curr.size()) {
                res.push_back(curr);
            }
            if (firstList[i][1] > secondList[j][1]) {
                j++;
            } else {
                i++;
            }
        }
        return res;
    }
};
