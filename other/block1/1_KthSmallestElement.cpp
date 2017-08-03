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

/ O(N)
    
 The C++ nth_element makes sure the nth element is in its correct position. And it is O(n), so with the help of STL:nth_element, it will be O(n).


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[nums.size() - k];
    }
};

//////////////////////

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

Make Heap using STL

A Heap is a data structure that is also a tree. The heap satifies that any parent nodes are greater/smaller than its children nodes depending on whether it is a max heap or min heap. So if we make these numbers into a heap and remove its maximum (root value) K-1 times, we have its K-th largest number.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i ++) {
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return nums.front();
    }
};

The pop_heap removes the front element (root) of the heap and move it to the last element, so the size of the heap array is shrinked by one.
Binary Search

If we count that there are K-1 numbers larger than x in the array, then x is the answer. At the begining, the min and max ranges can be set, with binary search, if there are more than K values larger than mid, then the value should be within the range [mid+1, max] otherwise [min, mid-1].
	

class Solution {
public:
    int countLargerOrEqualThanK(vector<int>& nums, int k) {
        auto c = 0;
        for (auto x: nums) {
            if (x >= k) {
                c ++;
            }
        }
        return c;
    }
 
    int findKthLargest(vector<int>& nums, int k) {
        int max = *max_element(nums.begin(), nums.end());
        int min = *min_element(nums.begin(), nums.end());
        while (min <= max) {
            int mid = min + (max - min) / 2;
            auto c = countLargerOrEqualThanK(nums, mid);
            if (c >= k) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return max;
    }
};

Binary search algorithm takes O(logn) complexity but counting the numbers takes O(n) and that is why the over complexity is O(n*logn).
nth_element

