/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool is_overlap(Interval i1, Interval i2) {
    if (max(i1.start, i2.start) > min(i1.end, i2.end)) {
        return false;
    }
    return true;
}
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    if (A.size() < 2) {
        return A;
    }
    sort(begin(A), end(A), [](Interval lhs, Interval rhs) { return lhs.start < rhs.start;});
    vector<Interval> res;
    int first = 0;
    for (int i = 1; i < A.size(); ++i) {
        if (is_overlap(A[i - 1], A[i])) {
            int st = i - 1;
            int left = A[st].start;
            int right = max(A[st].end, A[i].end);
            bool overlap = true;
            while (i < A.size() and overlap) {
                ++i;
                if (i >= A.size()) {
                    overlap = false;
                } else {
                    overlap = is_overlap({left, right}, A[i]);
                    if (overlap) {
                        right = max(right, A[i].end);
                    }
                }
            }
            res.push_back({left, right});
            if (i == A.size()-1 and not is_overlap({left, right}, A.back())) {
                res.push_back(A.back());
            }
        } else {
            res.push_back(A[i - 1]);
        }
    }
    return res;
}
