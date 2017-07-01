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


