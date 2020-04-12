/*


Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0


*/

class Solution {
    public:
        int searchInsert(vector<int> &A, int target) {
            int n = A.size();
            int start = 0, end = n - 1;
            int mid;
            while(start <= end){
                mid = (start + end) / 2;
                if(target == A[mid]){
                    return mid;
                }
                else if(target < A[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
            return start;
        }
};

