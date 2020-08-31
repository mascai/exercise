/*


Компоненты связности

Дан неориентированный граф, заданный своим списком ребер. Требуется определить компоненты связности в нем.

Входные данные

В первой строке записано два целых числа NNN, MMM (1≤N≤20 0001 \le N \le 20\,0001≤N≤20000, 1≤M≤200 0001 \le M \le 200\,0001≤M≤200000) - количество вершин и количество ребер.

В следующих MMM строках описаны ребра графа. Каждое ребро задается двумя числами u,vu, vu,v (1≤u,v≤N;u≠v1 \leq u, v \leq N; u \neq v1≤u,v≤N;u=v) - номера концов ребра.

Выходные данные

На первой строке выходного файла выведите число LLL - количество компонент связности заданного графа. На следующей
строке выведите NNN чисел из диапазона от 111 до LLL - номера компонент связности, которым принадлежат соответствующие вершины. Компоненты связности следует занумеровать от 111 до LLL в порядке возрастания минимального номера вершины в компоненте.

Sample Input 1:

4 2

1 2

3 4

Sample Output 1:

2

1 1 2 2 

Sample Input 2:

2 1

2 1

Sample Output 2:

1

1 1 



*/


#include <bits/stdc++.h>

using namespace std;


void dfs(int node, const vector<vector<int>>& graph, vector<int>& used, int color) {
    used[node - 1] = color;
    for (auto v : graph[node - 1]) {
        if (not used[v - 1]) {
            dfs(v, graph, used, color);
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    string s;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        int a = stoi(s);
        cin >> s;
        int b = stoi(s);
        graph[a-1].push_back(b);
        graph[b-1].push_back(a);
    }
    int res = 0;
    vector<int> used(n, 0);

    for (int i = 0; i < n; ++i) {
        if (not used[i]) {
            ++res;
            dfs(i + 1, graph, used, res);
        }
    }
    cout << res << endl; // number of connected components
    for (auto i : used) {
        cout << i << ' ';
    }
    return 0;
}
