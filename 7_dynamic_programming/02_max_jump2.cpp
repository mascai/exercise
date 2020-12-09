/*
https://stepik.org/lesson/307326/step/3?thread=solutions&unit=289414

Кузнечик135

Перед клетчатой полоской длины nn сидит кузнечик. В каждой клетке написано целое число. Когда кузнечик оказывается в какой-то клетке, ему дают конфет в том количестве, которое записано в этой клетке. Кузнечик умеет прыгать на следующую ступеньку, через две и через четыре ступеньки. То есть, если кузнечик сидит в клетке с номером ii, то за один шаг он может оказаться в клетках с номерами i + 1i+1, i + 3i+3, i + 5i+5. Помогите кузнечику - определите, какое максимальное количество конфет он может съесть, если в итоге он должен оказаться в последней клетке? Обратите внимание, количество конфет может быть отрицательно.

Входные данные

В первой стркое записано единственное целое число nn (1 \leq n \leq 10^51≤n≤10 
5
 ) - длина полоски.

Во второй строке записано nn целых чисел a_ia 
i
​	
  (-10^9 \leq a_i \leq 10^9−10 
9
 ≤a 
i
​	
 ≤10 
9
 ) - количество конфет в каждой клетке.

Выходные данные

Выведите одно число - максимальное количество конфет, которое может собрать кузнечик.

Sample Input 1:

5
4 7 6 6 6
Sample Output 1:

29
Sample Input 2:

10
-4 -4 -5 -2 1 3 1 2 -4 -3
Sample Output 2:

2


*/


#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    int arr[n];
    vector<long long> dp(n+1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    dp[0] = 0;
    dp[1] = arr[0];

    for (int i = 2; i <= n; ++i) {
        if (i < 3) {
            dp[i] = dp[i - 1] + arr[i - 1];
        } else if (i < 5) {
            dp[i] = max(dp[i - 1], dp[i - 3]) + arr[i - 1];
        } else {
            dp[i] = max(dp[i - 1], max(dp[i - 3], dp[i - 5])) + arr[i - 1];
        }
        
    }
    cout << dp[n];

    return 0;
}
