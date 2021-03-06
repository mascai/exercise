/*
Веревочки

С утра шел дождь, и ничего не предвещало беды. Но к обеду выглянуло солнце, и в лагерь заглянула СЭС. 
Пройдя по всем домикам и корпусам, СЭС вынесла следующий вердикт: бельевые веревки в жилых домиках не удовлетворяют нормам СЭС. 
Как выяснилось, в каждом домике должно быть ровно по одной бельевой веревке, и все веревки должны иметь одинаковую длину.
В лагере имеется NN бельевых веревок и KK домиков. Чтобы лагерь не закрыли, требуется так нарезать данные веревки, 
чтобы среди получившихся веревочек было KK одинаковой длины.
Размер штрафа обратно пропорционален длине бельевых веревок, которые будут развешены в домиках. 
Поэтому начальство лагеря стремиться максимизировать длину этих веревочек.

Входные данные

В первой строке заданы два числа - NN (1 \leqslant N \leqslant 10\,0011⩽N⩽10001) и KK (1 \leqslant K \leqslant 10\,0011⩽K⩽10001). 
Далее в каждой из последующих NN строк записано по одному числу - длине очередной бельевой веревки. 
Длина веревки задана в сантиметрах. Все длины лежат в интервале от 11 сантиметра до 100100 километров включительно.

Выходные данные

В выходной файл следует вывести одно целое число - максимальную длину веревочек,
удовлетворяющую условию, в сантиметрах. В случае, если лагерь закроют, выведите 00.

Sample Input:

4 11
802
743
457
539
Sample Output:

200
*/

#include <bits/stdc++.h>


using namespace std;

int check(const vector<int> v, int mid) {
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
        res += v[i] / mid;
    }
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
    long long low = 1, high = ceil(accumulate(begin(v), end(v), 0.0) / k) + 1;
    long long max_len = 0;
    while (low <= high) {
        long long mid = high - (high - low) / 2;
        if (check(v, mid) >= k) {
            max_len = max(max_len, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << max_len;
}
