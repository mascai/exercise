/*

Есть ли цикл?

В данной задаче вам нужно проверить, есть ли цикл в неориентированном графе.

Входные данные

В первой строке записано два целых числа nnn, mmm (1≤n≤500;0 ≤m≤n⋅(n−1)21 \leq n \leq 500; 0 \leq m \leq \frac{n \cdot (n - 1)}{2}1≤n≤500;0 ≤m≤2n⋅(n−1)​) - количество вершин и количество ребер.

В следующих mmm строках описаны ребра графа. Каждое ребро задается двумя числами u,vu, vu,v (1≤u,v≤n;u≠v1 \leq u, v \leq n; u \neq v1≤u,v≤n;u=v) - номера концов ребра. Гарантируется, что каждое ребро описано в графе единожды.

Выходные данные

В единственной строке выведите <<YES\texttt{YES}YES>> (без кавычек), если цикл есть и <<NO\texttt{NO}NO>> (без кавычек) иначе.

Sample Input 1:

6 4
1 2
1 3
4 5
5 6

Sample Output 1:

NO

Sample Input 2:

6 4
1 2
1 3
2 3
4 5

Sample Output 2:

YES

*/


#include <bits/stdc++.h>

using namespace std;

bool cycle = false;

void dfs(int start, vector<int>& color, vector<int>& prev, const vector <vector<int>>& g) {
    color[start - 1] = 1; // gray
    for (auto v : g[start - 1]) {
        if (color[v - 1] == 0) {
            prev[v - 1] = start;
            dfs(v, color, prev, g);
        } else if (color[v - 1] == 1 and prev[start - 1] != v) {
            cycle = true;
        }
    }
    color[start - 1] = 2;
}

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    vector<int> color(n, 0); // 0 - white, 1 - gray, 2 - black

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b);
        graph[b - 1].push_back(a);
    }

    vector<int> prev(n, -1);
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            dfs(i, color, prev, graph);
        }
    }
    if (cycle) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}






