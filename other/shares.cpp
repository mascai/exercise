/*
Вы можете идеально предсказать цену определенной акции на следующие N дней. Вы хотите заработать на этом знании, но хотите продавать или покупать не больше одной акции в день. Другими словами, каждый день вы будете либо покупать одну акцию, либо продавать одну акцию, либо ничего не делать. Изначально у вас нет акций, и вы не можете продать акцию, когда у вас их нет. В конце N дней вы хотите опять остаться без акций, но хотите заработать как можно больше.
Входные данные

В первой строке находится целое число N (2 ≤ N ≤ 3·105) — число дней.

Во второй строке находятся N целых чисел, p1, p2, ..., pN (1 ≤ pi ≤ 106). Цена одной акции в i-й день равна pi.
Выходные данные

Выведите максимальную сумму, которую вы можете заработать к концу N дней.
*/

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
