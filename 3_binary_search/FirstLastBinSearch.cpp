/*
Given a sorted array of integers, find the number of occurrences of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

**Example : **
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.
*/

int BinarySearchFirst(const vector<int>& a, int x){
    int n = a.size();
    int start = 0, end = n - 1;
    int ans = -1;
    while (start <= end){
        int mid = (start + end) / 2;
        if (x == a[mid]){
            ans = mid;
            end = mid - 1;
        } else if (x < a[mid]){
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int BinarySearchLast(const vector<int>& a, int x){
    int n = a.size();
    int start = 0, end = n - 1;
    int ans = -1;
    while (start <= end){
        int mid = (start + end) / 2;
        if (x == a[mid]){
            ans = mid;
            start = mid + 1;
        } else if (x < a[mid]){
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}


int Solution::findCount(const vector<int> &a, int k) {
    int n = a.size();
    //int start = 0, end = n - 1;
    int T = 1, B = -1;
    B = BinarySearchFirst(a, k);
    if (B == -1){
        return 0;
    }
    T = BinarySearchLast(a, k);
    return T - B + 1;
}
