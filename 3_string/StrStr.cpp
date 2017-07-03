int Solution::strStr(const string &s1, const string &s2) { // find s2 in s1
    int n = s1.size(), m = s2.size();
    if (m == 0 || n == 0 && m == 0){
        return -1;
    }
    for (int i = 0; i + m - 1 < n; i++){
        int j = 0;
        for (j = 0; s1[i + j] == s2[j] && j < m; j++);
        if (j == s2.size()){
            return i;
        }
    }
    return -1;
}
