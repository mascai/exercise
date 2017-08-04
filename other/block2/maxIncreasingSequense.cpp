#include <iostream>
#include<bits/stdc++.h>
using namespace std ;

int maxIncreasingSequense(const vector<int>& v){
    int ans = 1; // max length
    int sz = v.size();
    if (sz < 2){
        return sz;
    }
    int cnt = 1;
    for(int i = 1; i < sz; i++){
        if (v[i - 1] <= v[i]){
            cnt++;
        } else {
            ans = max(cnt, ans);
            cnt = 1;
        }
        if (i == sz - 1){
            ans = max(cnt, ans);
        }
    }
    return ans;
}

int main() {
    vector<int>v = {1, 0, 1, 2, 3, 5 , 4 , 5, 6, 7, 8, 9, 10, 0};
    cout << maxIncreasingSequense(v);
    return 0;
}
