/*
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool myCmp(Interval a, Interval b) {
            return a.start < b.start;
        }

        vector<Interval> Solution::merge(vector<Interval> &intervals) {
            if(intervals.size() < 2) {
                return intervals;
            }
            sort(intervals.begin(), intervals.end(), myCmp);
            int first = 0;
            for(int second = 1; second < intervals.size(); second++) {
                // There is overlap in intervals at first and second position.
                if(intervals[second].start <= intervals[first].end) {
                    // We merge the second interval into the first one and modify the first interval to reflect it. 
                    intervals[first].end = max(intervals[second].end, intervals[first].end);
                }
                else {
                    // No overlap between first and second. Move forward. 
                    ++first;
                    intervals[first].start = intervals[second].start;
                    intervals[first].end = intervals[second].end;
                }
            }
            
            return intervals;
        }
