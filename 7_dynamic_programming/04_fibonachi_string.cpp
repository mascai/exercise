/*
https://github.com/permCoding/StepikQuickStart/blob/00040add5fd76682ab9356cf29791fd28cc14147/part3/Task25plus.py

Строка Фибоначчи

Строкой Фибоначчи называется строка, состоящая только из 00 и 11, в которой не встречается двух 11 подряд. Вам требуется найти количество таких строк длины nn.

Входные данные

Во входных данных записано одно число nn (0 \leq n \leq 900≤n≤90) - длина строки.

Выходные данные

Выведите одно число - количество строк Фибоначчи длины nn.

Sample Input 1:

1
Sample Output 1:

2
Sample Input 2:

2
Sample Output 2:

3
*/

#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 1; // corner case 
        return 0;    
    }
    vector<long long> cntEnd0(n, 0); // max possible number of '0' at the end of the string 
    vector<long long> cntEnd1(n, 0);

    // strings of length = 1 ---> ['0', '1']
    // strings of length = 2 ---> ['00', '01', '10']
    cntEnd0[0] = 1;
    cntEnd1[0] = 1;

    for (int i = 1; i < n; ++i) {
        cntEnd0[i] = cntEnd0[i - 1] + cntEnd1[i - 1];
        cntEnd1[i] = cntEnd0[i -1];
    }
    cout << cntEnd0[n - 1] + cntEnd1[n - 1];

    return 0;
}
