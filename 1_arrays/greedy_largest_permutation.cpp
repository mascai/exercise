/*
https://www.interviewbit.com/problems/largest-permutation/


Problem Description

Given an integer array A of size N consisting of unique integers from 1 to N. You can swap any two integers atmost B times.

Return the largest lexicographical value array that can be created by executing atmost B swaps.



Problem Constraints
1 <= N <= 106

1 <= B <= 109



Input Format
First argument is an integer array A of size N.

Second argument is an integer B.



Output Format
Return an integer array denoting the largest lexicographical value array that can be created by executing atmost B swaps.



Example Input
Input 1:

 A = [1, 2, 3, 4]
 B = 1
Input 2:

 A = [3, 2, 1]
 B = 2
 
 */
 
 vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> poses(n);
    for (int i = 0; i < n; ++i) {
        poses[A[i] - 1] = i;
    }
    for (int i = 0; i < A.size() and B; ++i) {
        if (A[i] != n) {
            int pos = poses[n - 1];
            swap(A[i], A[pos]);
            swap(poses[A[pos] - 1], poses[n - 1]);
            --B;
        }
        --n;
    }
    return A;
}
