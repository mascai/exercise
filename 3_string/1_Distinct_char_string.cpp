/*
Given a string S, find length of the longest substring with all distinct characters.  For example, for input "abca", the output is 3 as "abc" is the longest substring with all distinct characters.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is String str.

Output:
Print length of smallest substring with maximum number of distinct characters.
Note: The output substring should have all distinct characters.

Constraints:
1 ≤ T ≤ 100
1 ≤ size of str ≤ 10000

Example:
Input:
2
abababcdefababcdab
geeksforgeeks

Output:
6
7

*/


#include <bits/stdc++.h> 

using namespace std;


int foo(string str) {
    int i = 0, j = 0;
    int maxLen = 0;
    set<char> cnt;
    
    while (j < str.size()) {
        if (cnt.find(str[j]) == cnt.end()) {
            cnt.insert(str[j]);
            j++;
            maxLen = max(maxLen, j - i);
        } else {
            cnt.erase(str[i]);
            i++;
        }
    }
    return maxLen;
}


int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
	    string str;
	    cin >> str;
	    cout << foo(str) << endl;
	}
	return 0;
}
