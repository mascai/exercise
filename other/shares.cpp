#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int main() {
    vector<int>prev(MAX, INT_MIN),
               next(MAX, INT_MIN);
    next[0] = 0;
    int day = 0, price = 0;
    ifstream fin("data.csv");
    string str;
    char ch;
    while (getline(fin, str)) {
        stringstream ss;
        ss << str;
        ss >> day >> ch >> price;

        for (int i = 0; i < MAX; i++) {
            prev[i] = next[i];
        }

        for (int i = 0; i < MAX; i++) {
            if (prev[i] == INT_MIN) {
                continue;
            }
            if (i < MAX - 1) {
                next[i + 1] = max(next[i + 1], prev[i] - price);
            }
            if (i > 0) {
                next[i - 1] = max(next[i - 1], prev[i] + price);
            }
        }

    }
    fin.close();
    int res = INT_MIN;
    for (int i = 0; i < MAX; i++) {
        next[i] += i * price;
        res = max(next[i], res);
    }
    cout << res;
    return 0;
}
