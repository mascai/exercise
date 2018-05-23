/*
  Given a read only array of n + 1 integers between 1 and n, 
  find one number that repeats in linear time using less than O(n) space 
  and traversing the stream sequentially O(1) times.
  
  Sample Input:

[3 4 1 4 1]

Sample Output:

1

If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1
*/


#include <math.h>

int Solution::repeatedNumber(const vector<int> &A) {
    int sz = A.size() - 1;
    int id = 0;
    int sq= floor(sqrt(sz));
    int part_size = A.size() / sz;
    map<int, int>cnt; // elem and counter of elem
    for (int i = 0; i < A.size(); i += sq) {
        int curr_size = 0;
        for (int j = i; j < A.size() && j <= i + sq; j++) {
            ++curr_size;
        }
        if (curr_size > part_size) {
            for (int j = i; j < A.size() && j <= i + sq; j++) {
                cnt[A[j]]++;
            }
        }
    }
    for (auto item : cnt) {
        int cnt_num = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == item.first) {
                ++cnt_num;
            }
        }
        if (cnt_num > 1) {
            return item.first;
        }
    }
    return -1;
}


