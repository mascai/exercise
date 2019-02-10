/*
В базе данных хранится N записей, вида (Name; a1; a2; : : : ; ak) – во всех записях одинаковое
число параметров. На вход задачи подаётся приоритет полей – перестановка на числах 1; : : : ; k –
записи нужно вывести в соответствии с этим приоритетом.
В случае, если в БД две записи (A; 3; 2) и (B; 1; 3), а приоритет полей 2; 1, то запись B должна
быть выведена раньше записи A, т.к. приоритет второго поля выше первого. В случае записей
(A; 3; 2) и (B; 1; 2), A важнее B, т.к. значение вторых компонент равно, а первая компонента у A
больше.

Формат входных данных
N ⩽ 1000
k : 1 ⩽ k ⩽ 10
p1 p2 : : : pk – перестановка на k числах, разделитель пробел
N строк вида
Name a1 a2 : : : ak – разделитель пробел
Формат выходных данных
N строк с именами в порядке, согласно приоритету

3
3
2 1 3
A 1 2 3
B 3 2 1
C 3 1 2

B
A
C

*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    string name;
    vector<int>num;
};

vector<int>prior;

bool cmp(Node a, Node b) {
    for (int i = 0; i < prior.size(); i++) {
        if (a.num[prior[i] - 1] > b.num[prior[i] - 1]) {
            return true;
        } else if (a.num[prior[i] - 1] < b.num[prior[i] - 1]) {
            return false;
        }
    }
    return true;
}

int main(){
	int n, k;
	cin >> n;
	cin >> k;
	int temp;
	for (int i = 0; i < k; i++) {
        cin >> temp;
        prior.push_back(temp);
	}
	vector<Node>v;
	vector<int>cur(k);
	string name;
	for (int i = 0; i < n; i++) {
	    cin >> name;
        for (int j = 0; j < k; j++) {
            cin >> cur[j];
        }
        v.push_back({name, cur});
	}
    sort(begin(v), end(v), cmp);
    for (int i = 0; i < n; i++) {
        cout << v[i].name << endl;
    }
	return 0;
}
