/*
На складе есть провода различной целочисленной длины. Их можно разрезать на части. Необ-
ходимо получить K кусочков одинаковой целочисленной и как можно большей длины. Найти мак-
симальную длину M.
Формат входных данных
В первой строке — количество проводов на складе N и необходимое количество кусочков K. В
следующих N строках — длины проводов.
1 ⩽ N ⩽ 100000
1 ⩽ K ⩽ 100000
Формат выходных данных
M — максимальная длина, на которую можно разрезать все провода так, чтобы получилось не
менее K кусочков.

стандартный ввод  стандартный вывод
5 7
15
12
5
13
6
       6
 */
 
 #include <bits/stdc++.h>

using namespace std;

void bin_search(vector<int>v, int K, int low, int high, int &ans){
	int mid = (high - low) / 2 + low;
	if (mid == low) {
        return;
	}
	int cnt = 0;

	for (int i=0; i< v.size() && v[i] >= mid; i++) {
        cnt += v[i] / mid;
	}
	if (cnt >= K) {
		if (mid > ans) ans = mid;
		bin_search(v, K, mid, high, ans);
	}else {
		bin_search(v, K, low, mid, ans);
	}
}

int main(){
	int n, k,
	    ans = 0,
	    low = 0,
	    high = 0;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
        cin >> v[i];
        high += v[i];
	}
	sort(begin(v), end(v), greater<int>());
	bin_search(v, k, low, high, ans);
	cout << ans;
	return 0;
}
  
