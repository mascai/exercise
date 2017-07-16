/*
Напишите метод для вычисления всех перестановок строки, состоящей из
уникальных символов.
*/
#include <iostream>
#include <stdio.h>
#define For(x,n) for(int x = 0; x < n; ++x)
#include <bits/stdc++.h>
using namespace std;
void getPerms(string pref, string s, vector<string>& ans);
vector<string> getPerms(string s){
    vector<string> ans;
    getPerms("", s, ans);
    return ans;
}
void getPerms(string pref, string s, vector<string>& ans){
  int len = s.size();
  if (len == 0){
    ans.push_back(pref);
  }
  for (int i = 0; i < len; i++){
    string before = s.substr(0, i),
           after = s.substr(i+1, len);
    char c = s[i];
    getPerms(pref + c, before + after, ans);
  }
}

int main()
{
   string v = "abcdef";
   vector<string> ans = getPerms(v);
   for (auto& i : ans){
    cout << i << ' ';
   }
}


