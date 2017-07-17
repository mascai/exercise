/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

    Note:

        All numbers (including target) will be positive integers.
        Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        The combinations themselves must be sorted in ascending order.
        CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
        The solution set must not contain duplicate combinations.

Example,
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]


*/
void doWork(vector<int> &candidates, int index, vector<int> &current, int currentSum, int target, vector<vector<int> > &ans) {
    if (currentSum > target) {
        return;
    }
    if (currentSum == target) {
        ans.push_back(current);
        return;
    }
    for (int i = index; i < candidates.size(); i++) {
        current.push_back(candidates[i]);
        currentSum += candidates[i];

        doWork(candidates, i, current, currentSum, target, ans);
        
        current.pop_back();
        currentSum -= candidates[i];
    }
    
}

vector<vector<int>> Solution::combinationSum(vector<int> &candidates, int target) {
        vector<int> current; 
    vector<vector<int> > ans;
    sort(candidates.begin(), candidates.end());
    vector<int> uniqueCandidates;
    for (int i = 0; i < candidates.size(); i++) {
        if (i == 0 || candidates[i] != candidates[i-1]) {
            uniqueCandidates.push_back(candidates[i]);
        }
    }
    doWork(uniqueCandidates, 0, current, 0, target, ans); 
    return ans;
}
