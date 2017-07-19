/*


For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different

Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1
*/
vector<int>IntToVec(int n){
    vector<int>ans;
    while(n > 0){
        ans.push_back(n % 10);
        n = n / 10;
    }
    return ans;
}

int Solution::colorful(int A) {
    vector<int>v = IntToVec(A);
    unordered_map<int, int>cnt; // number and counter of numbers
    for (auto &i : v){
        ++cnt[i];
        if (cnt[i] > 1){
            return 0;
        }
    }
    int len = v.size();
    if (len == 0 || len == 1){
        return 1;
    }
    for (int i = 0; i < len - 1; i++){
        int prod = v[i];
        for (int j = i + 1; j < len; j++){
            prod *= v[j];
            ++cnt[prod];
            if (cnt[prod] > 1){
                return 0;
            }
        }
    }
    return 1;
}
