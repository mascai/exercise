/*


Given a set of distinct integers, S, return all possible subsets.

    Note:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        Also, the subsets should be sorted in ascending ( lexicographic ) order.
        The list is not necessarily sorted.

Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

*/
void Foo(vector<int> &A, int index, vector<int> &cur, vector<vector<int> > &res);
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>>res;
    vector<int>cur;
    sort(begin(A), end(A));
    Foo(A, 0, cur, res);
    sort(begin(res), end(res));
    return res;
}

void Foo(vector<int> &A, int index, vector<int> &cur, vector<vector<int> > &res){
    if (index >= A.size()){
        res.push_back(cur);
        return;
    }
    //ignore 
    Foo(A, index + 1, cur, res);
    
    //include element
    cur.push_back(A[index]);
    Foo(A, index + 1, cur, res);
    cur.pop_back();
}
