#include <bits/stdc++.h>

using namespace std;

int bin_search_left(vector<int>a, int  x) {
    int low = 0, high = a.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == x) {
            // return mid; // simple bin_search
            ans = mid;
            high = mid - 1;
        } else if ( a[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int bin_search_right(vector<int>a, int x) {
    int low = 0, high = a.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == x) {
            // return mid; // simple bin_search
            ans = mid;
            low = mid + 1;
        } else if (a[mid] < x) {
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int>v_find_left = {1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 4, 8, 12, 13, 13, 13,  17, 111};
    cout << bin_search_left(v_find_left, 1) << endl;
    vector<int>v_find_riight = {1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 4, 8, 12, 13, 13, 13,  17, 111};
    cout << bin_search_right(v_find_riight, 1);
    return 0;
}
