/*
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1

On returning, the array A should be :

0 0 0
1 0 1
1 0 1

Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.

*/

void Solution::setZeroes(vector<vector<int> > &A) {
    if (A.size() == 0) {
        return;
    }
    int m = A.size(),
        n = A[0].size();
    vector<int>colon(n, 0),
               row(m, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 0) { // remember zeroes
                colon[j] = 1;
                row[i] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (colon[j] == 1 || row[i] == 1) {
                A[i][j] = 0;
            }
        }
    }
    //return A;
}

