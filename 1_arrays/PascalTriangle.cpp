/*


Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]


*/

vector<vector<int> > Solution::generate(int n) {
    vector<vector<int>>v;
    if (n == 0){
        return v;
    }
    vector<int>row;
    vector<int>prev;
    row.push_back(1);
    v.push_back(row);
    if (n == 1){
        return v;
    }
    row.push_back(1);
    v.push_back(row);
    if (n == 2){
        return v;
    }

    for (int i  = 3; i <= n; i++){
        prev = row;
        row.clear();
        row.push_back(1);
        for (int j = 0; j < prev.size() - 1; j++){
            row.push_back(prev[j] + prev[j + 1]);
        }
        row.push_back(1);
        v.push_back(row);
    }
    return v;
}
