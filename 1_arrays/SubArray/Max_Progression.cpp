/*
  Найти длину максимальной уюывающей геометрической прогрессии в массиве
*/
#include <bits/stdc++.h>

using namespace std;

int f(vector<int>a) {
    int start = 0, sz = a.size();
    int ans = 1, curr = 1;
    float q = 0;
    int mode = 0;
    int i = 0;
    while (i < sz) {
        while (i + 1 < sz && a[i] < a[i + 1]) {
            ++i;
        }
        if (i == sz - 2) {
            if (a[i] > a[i + 1]) {
                curr = 2;
            } else {
                curr = 1;
            }
            return max(curr, ans);
        }
        curr = 2;
        q = float(a[i]) / float(a[i + 1]);
        i++;
        while (i + 1 < sz && float(a[i]) / float(a[i + 1]) == q) {
            curr++;
            i++;
        }
        ans = max(ans, curr);
    }
    ans = max(ans, curr);
    return ans;

}

int main() {
    cout << f({7, 6, 27, 9, 3, 1, 5, 4, 2, 1, 1});
}
