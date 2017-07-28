/*
Find the kth smallest element in an unsorted array of non-negative integers.

Definition of kth smallest element

    kth smallest element is the minimum possible n such that there are at least k elements in the array <= n.
    In other words, if the array A was sorted, then A[k - 1] ( k is 1 based, while the arrays are 0 based ) 

NOTE
You are not allowed to modify the array ( The array is read only ).
Try to do it using constant extra space.

Example:

A : [2 1 4 3 2]
k : 3

answer : 2

*/

int Solution::kthsmallest(const vector<int> &A, int k) {
    int n = A.size();
    int low = INT_MIN, high = INT_MAX;
    for (int i = 0; i < n; i++){
        if (!(A[i] >= low && A[i] <= high)){
            continue;
        }
        int cnt = 0 , cnt1 = 0;
        for (int j = 0; j < n; j++){
            if (i != j && A[j] > A[i]){
                cnt++;
            } 
            if (A[i] == A[j]){
                cnt1++;
            }
            if (cnt > k){
                break;
            }
        }
        if (cnt + cnt1 < k){
            low = A[i] + 1;
        } else if (cnt >= k){
            high = A[i] - 1;
        }
        if (cnt < k && cnt + cnt1 >= k){
            return A[i];
        }
    }
}
