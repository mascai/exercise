/*
От вас требуется написать функцию, которая возвращает максимальную прибыль от одной сделки с одной акцией (сначала покупка, потом продажа). Исходные данные — массив вчерашних котировок stock_prices_yesterday с ценами акций Apple. 

Информация о массиве:

    Индекс равен количеству минут с начала торговой сессии (9:30 утра).
    Значение в массиве равно стоимости акции в это время.

Например: если акция в 10:00 утра стоила 20 долларов, то
stock_prices_yesterday[30] = 20.

Допустим, имеем некоторые условия:

stock_prices_yesterday = [10, 7, 5, 8, 11, 9]

profit = get_max_profit(stock_prices_yesterday)
#вернет 6 (купили за 5, продали за 11)
*/
#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <memory>

using namespace std;

int maxProfit(const vector<int>& v) {
    if (v.size() < 2) {
        return 0;
    }
    int minPrice = v[0],
        maxDiff = v[1] - v[0],
        currDiff;
    for (int i = 2; i < v.size(); ++i) {
        currDiff = v[i] - minPrice;
        minPrice = min(minPrice, v[i]);
        maxDiff = max(maxDiff, currDiff);
    }
    return maxDiff;
}

int main() {
    vector<int> v {10, 7, 5, 8, 11, 9};
    cout << maxProfit(v);
}
