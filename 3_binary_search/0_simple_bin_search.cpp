#include <bits/stdc++.h>

using namespace std;

// return id of K
int bin_search(const vector<int>& v, int k) {
    int low = 0, high = v.size() - 1;
    while (low <= high) {
        int mid = (low+ high) / 2;
        if (v[mid] == k) {
            return mid;
        } else if (v[mid] > k){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return - 1;
}

int main(){
    vector<int>v = {2, 4, 5, 7, 10};
    cout << bin_search(v, 7);
}
