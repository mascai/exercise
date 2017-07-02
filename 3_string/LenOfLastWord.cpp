/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.
*/

int Solution::lengthOfLastWord(const string &A) {
    if (A.size() == 0){
        return 0;
    }
    bool f = false;
    stringstream ss;
    string prev;
    for (int i = 0; i < A.size(); i++){
        if (A[i] != ' ') {
            f = true;
            ss << A[i];
        }
        if (A[i] == ' '){
            if (f){
                prev = ss.str();
            }
            ss.str("");
            f = false;
        }
    }
    string ans  = ss.str();
    if (ans.size() == 0){
        if (prev.size() != 0){
            return prev.size();
        } else {
            return 0;
        }
    } else {
        return ans.size();
    }
}




class Solution {
    public:
        int lengthOfLastWord(const string &s) {
            int len = 0;
            while (*s) {
                if (*s != ' ') {
                    len++;
                    s++;
                    continue;
                }
                s++;
                if (*s && *s != ' ') len = 0;
            }
            return len;

        }
};


