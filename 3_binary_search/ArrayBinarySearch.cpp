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


// Second version of solution
int getElement(const vector<vector<int> > &A, const int id) {
    int i = id / A[0].size();
    int j = id - i * A[0].size();
    return A[i][j];
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int rows = A.size();
    if (rows == 0) {
        return 0;
    }
    int cols = A[0].size();
    int start = 0, end = rows * cols - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        int cur = getElement(A, mid);
        if (cur == B) {
            return 1;
        } else if (B < cur) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return 0;
}

