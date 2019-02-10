/*
Имеется последовательность натуральных чисел, длина которой больше 8. Признаком конца
последовательности является отрицательное число, не входящее в последовательность. Найти мак-
симальное произведение двух элементов последовательности, отстоящих друг от друга не менее,
чем на 8. Гарантируется, что ответ меньше 2000000000.

2
3
4
5
6
7
8
9
1
10
20
30
40
50
35
0

OUTPUT: 350
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int n;
    int maxpref = 1, maxout = 1, xcur = 1, a[8];

    for (int i = 0; i < 8; i++)
        scanf("%d", &a[i]);
    int i = 8;
    int f = 1;
    scanf("%d", &xcur);
    while (xcur > 0){
        if (f == 0) {
            //cin >> xcur;
            if (scanf("%d", &xcur) == 0)
                break;
        }
        f = 0;
        maxpref = max(maxpref, a[i % 8]);
        a[i % 8] = xcur;
        maxout = max(maxout, xcur * maxpref);
        ++i;
    }
    cout << maxout;
    return 0;
}
