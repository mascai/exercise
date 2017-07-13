/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]

Elements for which no smaller element exist, consider next smaller element as -1.

Example:

Input : A : [4, 5, 2, 10]
Return : [-1, 4, -1, 2]

Example 2:

Input : A : [3, 2, 1]
Return : [-1, -1, -1]
*/

vector<int> Solution::prevSmaller(vector<int> &a) {
    vector<int>ans(a.size(), -1);
    stack<int>st;
    for (int i = 1; i < a.size(); i++){
        st.push(a[i-1]);
        while(!st.empty()){
            if (st.top() < a[i]){
                ans[i] = st.top();
                break;
            } else {
                st.pop();
            }
        }
    }
    return ans;
}
