/*
https://stepik.org/lesson/311541/step/7?unit=293969

Коровы в стойла

На прямой расположены стойла, в которые необходимо расставить коров так, чтобы минимальное растояние между коровами было как можно больше.

Входные данные

В первой строке вводятся числа NN (2 < N < 10\,0012<N<10001) - количество стойл и KK (1 < K < N)(1<K<N) - количество коров. 
Во второй строке задаются NN натуральных чисел в порядке возрастания - координаты стойл (координаты не превосходят 10^910 
9
 ).

Выходные данные

Выведите одно число - наибольшее возможное допустимое расстояние.

Sample Input:

5 3
1 2 3 100 1000
Sample Output:

99

*/


#include <bits/stdc++.h>


using namespace std;
 

bool check(const vector<long long>& v, long long k, long long dist) {
    if (v.empty()) {
        return false;
    }
    --k; // place the first cow at the v[0]
    long long curDist = dist;
    for (int i = 1; i < v.size(); ++i) {
        if (k == 0) {
            return true;
        }
        if (curDist > v[i] - v[i - 1]) {
            curDist -= v[i] - v[i - 1];
        } else {
            curDist = dist;
            --k; // place  cow at v[i]
        }
    }
    return k <= 0;
}

int main(){
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    long long low = 0, high = v[n - 1] - v[0];
    long long res = -1;
    while (low <= high) {
        long long mid = high - (high - low) / 2;
        if (check(v, k, mid)) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << res;
}
