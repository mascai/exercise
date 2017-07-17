/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,
1. Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
2. Entries should be sorted within themselves.

Example :
If n = 4 and k = 2, a solution is:
[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]

*/
void rec(vector<vector<int>>&ans, vector<int>word, int n, int k, int index);
vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int>>ans;
    vector<int>word;
    if (n == 0 || k == 0 || k > n){
        return ans;
    }
    rec(ans, word, n, k, 0);
    return ans;
}

void rec(vector<vector<int>>&ans, vector<int>word, int n, int k, int index){
    if (k == 0){
        ans.push_back(word);
        return;
    }
    for (int i = index + 1; i <= n; i++){
        word.push_back(i);
        rec(ans, word, n, k - 1, i);
        word.pop_back();
    }
}
