/*

Имеется лестница, в которой N ступенек. Кузнечик находится перед лестницей. Он прыгает
только вверх и способен прыгнуть вверх не более, чем на M ступенек.
Определить, сколькими способами кузнечик может допрыгать да самой верхней ступеньки.
1 ⩽ M ⩽ N ⩽ 30
Для N = 5 и M = 2 имеется 8 маршрутов: (1,2,3,4,5)
(1,2,3,5)
(1,2,4,5)
(1,3,4,5)
(1,3,5)
(2,3,4,5)
(2,3,5)
(2,4,5)
*/


#include <bits/stdc++.h>

using namespace std;

int foo (int n, int m, vector<int>& v) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (v[n] > -1) {
        return v[n];
    }
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        sum += foo(n - i, m, v);
    }
    v[n] = sum;
    return v[n];
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    vector<int>v(n + 1, -1);
    int ans = foo(n, m, v);
    printf("%d", ans);
    return 0;
}
