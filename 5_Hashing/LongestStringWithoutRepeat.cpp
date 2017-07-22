/*

Given a string,
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

*/
int Solution::lengthOfLongestSubstring(string A) {
    int i = 0, j = 0;
    int cur = 0, ans = 0; //size
    map<char, int>hash;
    while (j < A.size()){
        if (hash.end() == hash.find(A[j])){
            hash[A[j]] = 1;
            j++;
            cur++;
        } else {
            while (A[i] != A[j]){
                hash.erase(A[i]);
                i++;
                cur--;
            }
            if (i != j){
                i++;
            }
            hash.erase(A[j]);
            cur--;
        }
        ans = max(ans, cur);
    }
    return ans;
}
