/*
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...

1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.

*/
string Solution::countAndSay(int n) {
    stringstream ss;
    string prev = "1";
    if (n == 1){
        return prev;
    }
    for (int i = 1; i < n; i++){
        char cur_ch = prev[0];
        int cnt = 1;
        for (int j = 1; j < prev.size(); j++){
            if (j == prev.size()){
                ss << cnt << cur_ch;
                prev = ss.str();
                ss.str("");
                break;
            }
            if (prev[j] == cur_ch){
                cnt++;
            }
            if (prev[j] != cur_ch){
                ss << cnt << cur_ch;
                cnt = 1;
                cur_ch = prev[j];
            }
        }
        ss << cnt << cur_ch;
        prev = ss.str();
        ss.str("");
    }
    return prev;
}
