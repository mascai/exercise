#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = (low - 1);
    for (int j = low; j < high; ++j) {
        if (vec[j] < pivot) {
            ++i;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}

// Example quickSort(v, 0, v.size() - 1);
void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int pos = partition(vec, low, high);
        quickSort(vec, low, pos - 1);
        quickSort(vec, pos + 1, high);
    }
}

int main() {
    vector<int> v{10, 7, 8, 9, 1, 5};
    int n = v.size();
    quickSort(v, 0, n - 1);
    for (auto cur : v) {
        cout << cur << ' ';
    }
}
