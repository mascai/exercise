/*
Была исходная строка длины 2 ⩽ L ⩽ 150000. К ней многократно приписали её же справа и из
полученной строки в произвольном месте вырезали фрагмент, который и предъявили к опознанию.
По вырезанному фрагменту нужно найти наименьшую из возможных длину исходной строки.
Формат входных данных
S
S.size() <= 150000
Формат выходных данных
L

dabcdab 4
cadabraabracadabraabracadabraabracadab 11
*/

#include <bits/stdc++.h>

using namespace std;

vector<int>KMP(string s) {
    int sz = s.size();
    vector<int>ans(sz);
    for (int i = 1; i < sz; i++) {
        int j = ans[i-1];
        while (j > 0 && s[i] != s[j]) {
            j = ans[j-1];
        }
        if (s[i] == s[j])  ++j;
        ans[i] = j;
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int sz = s.size();
    vector<int>ans;
    ans = KMP(s);
    int end_len = ans.back();
    cout<< sz - end_len;
    return 0;
}
