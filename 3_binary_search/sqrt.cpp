/*
Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3
*/
int Solution::sqrt(int n) {
    int start  = 1, end = n, ans;
    if (n == 0){
        return 0;
    }
    while (start <= end){
        int mid = (start + end) / 2;
        if (mid <= n / mid){ // mid * mid => may be overflow
            start = mid + 1; 
            ans = mid;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}
