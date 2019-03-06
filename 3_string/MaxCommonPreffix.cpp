/*
Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]

The answer would be “a”.

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> pi(string s) {
    int n = s.size();
    vector<int>p(n);
    int j = 0;
    p[0] = 0;
    for (int i = 1; i < n; ++i) {
        while (j > 0 && p[i] == p[j]) {
            j = p[j - 1];
        }
        if (p[i] == p[j]) {
            ++j;
        }
        p[i] = j;
    }
    return p;
}

string pref(vector<string> vec) {
    size_t minLen = vec[0].size();
    for (int i = 1; i < vec.size(); ++i) {
        minLen = min(minLen, vec[i].size());
    }
    
    string ans="";
    for (int i = 0; i < minLen; ++i) {
        char cur = vec[0][i];
        for (int j = 1; j < vec.size(); ++j) {
            if (vec[j][i] != cur) {
                if (ans.size())
                    return ans;
                return "-1";
            }
        }
        ans.push_back(cur);
    }
    if (ans.size())
        return ans;
    return "-1";
}

int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
	    int n;
	    cin >> n;
	    string s, ans;
	    vector<string>vec(n);
	    for (int i = 0; i < n; ++i) {
	        cin >> vec[i];
	        
	    }
	    cout << pref(vec) << endl;
	    
	}
	return 0;
}

////////////////
////////////////
////////////////
////////////////

// O(M*N)

string Solution::longestCommonPrefix(vector<string> &A) {
    string ans = A[0], s = A[0];
    for (int i = 1; i < A.size(); i++){
        string cur = "";
        for (int j = 0; j < min(s.size(), A[i].size()); j++){
            if (s[j] == A[i][j] ){
                cur.push_back(s[j]);
            }
            if ((s[j] != A[i][j] || j == min(s.size(), A[i].size()) - 1) && cur.size() < ans.size()){
                ans = cur;
            }
        }
    }
    return ans;
}


