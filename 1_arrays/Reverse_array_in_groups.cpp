/*
Given an array of positive integers. Reverse every sub-array of K group elements.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines of input. The first line of each test case consists of an integer N(size of array) and an integer K separated by a space. The second line of each test case contains N space separated integers denoting the array elements.

Output:
For test case, print the modified array.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 107
1 ≤ A[i] ≤ 1018

Example:
Input
1
5 3
1 2 3 4 5

Output
3 2 1 5 4

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> revGroup(vector<int> vec, int k) {
    vector<int> ans;
    for (int i = 0; i < vec.size(); i += k) {
        int j = i + k - 1;
        while (j >= i) {
            if (j < vec.size()) {
                ans.push_back(vec[j]);
            }
            j--;
        }
    }
    return ans;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
	    int n, k;
	    cin >> n >> k;
	    vector<int>vec(n);
	    for (int i = 0; i < n; ++i) {
	        cin >> vec[i];
	    }
	    auto ans = revGroup(vec, k);
	    for (auto item : ans) {
	        cout << item << ' ';
	    }
	    cout << endl;
	    
	}
	return 0;
}
