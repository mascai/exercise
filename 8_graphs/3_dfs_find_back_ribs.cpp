/*
https://stepik.org/lesson/307331/step/5?unit=289419

Связный граф
Древесное ребро - ребро, которое участвует в dfs обходе графа
Обратное ребро (back rib) - все остальные ребра


Обратные ребра

Дан связный неориентированный граф, заданный своим списком ребер. Требуется определить количество обратных ребер в этом графе.

Входные данные

В первой строке записано два целых числа nn, mm (1 \leq n \leq 500; 0 \leq m \leq \frac{n \cdot (n - 1)}{2}1≤n≤500;0 ≤m≤ 
2
n⋅(n−1)
​	
 ) - количество вершин и количество ребер.

В следующих mm строках описаны ребра графа. Каждое ребро задается двумя числами u, vu,v (1 \leq u, v \leq n; u \neq v1≤u,v≤n;u

=v) - номера концов ребра. Гарантируется, что каждое ребро описано в графе единожды.

Выходные данные

Выведите единственное целое число - количество обратных ребер в графе. Если возможных ответов несколько, выведите любой.

Sample Input 1:

5 7
1 2
1 4
1 3
5 2
4 2
2 3
3 4
Sample Output 1:

3
Sample Input 2:

6 5
1 6
4 1
6 3
5 1
2 4
Sample Output 2:

0
Sample Input 3:

10 13
1 8
8 9
10 9
10 3
3 7
7 6
6 4
4 2
5 2
8 2
6 8
1 7
6 1
Sample Output 3:

4


*/



#include <bits/stdc++.h>

using namespace std;


void dfs(int node, const vector<vector<int>>& graph, vector<int>& used) {
    used[node - 1] = 1;
    for (auto v : graph[node - 1]) {
        if (not used[v - 1]) {
            dfs(v, graph, used);
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    string s;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b);
        graph[b-1].push_back(a);
    }
    int res = 0;
    vector<int> used(n, 0);

    dfs(1, graph, used);
    long long cntUsed = count(begin(used), end(used), 1);
    cout << m - cntUsed + 1<< endl;

    return 0;
}
