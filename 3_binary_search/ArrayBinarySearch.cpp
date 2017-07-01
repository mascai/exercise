/*
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

        Integers in each row are sorted from left to right.
        The first integer of each row is greater than or equal to the last integer of the previous row.

Example:

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem

*/
int Solution::searchMatrix(vector<vector<int> > &a, int x) {
    int m = a.size(),
        n = a[0].size();
    int low = 0, high = m * n - 1;
    //int ans = 0;
    while (low <= high){
        int mid  = (low + high) / 2;
        if (x == a[mid / n][mid % n]){
            return 1;
        } else if (x > a[mid / n][mid % n]){
            low  = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}
