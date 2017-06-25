/*
Max Sum Contiguous Subarray


Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.
*/


int Solution::maxSubArray(const vector<int> &a) {
   int n = a.size();
   int ans = a[0],
	sum = 0,
	min_sum = 0;
    for (int r=0; r<n; ++r) {
    	sum += a[r];
    	ans = max (ans, sum - min_sum);
    	min_sum = min (min_sum, sum);
    }
    return ans;
}


int Solution::maxSubArray(const vector<int> &A) { // O(N^2)
   int max = INT_MIN, n = A.size();
   for (int i = 0; i < n; i++){ // start index
       int sum = 0;
       for (int sz = 1; sz <= n; sz++){ // size of sequence
           if (sz + i > n){
               break;
           }
           sum += A[i + sz - 1];
           if (sum >= max){
               max = sum;
           }
       }
   }
   
   return max;
}
