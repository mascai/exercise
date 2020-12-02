/*
https://stepik.org/lesson/307332/step/3?unit=289420

Волновым обходом графа из вершины vv называется такая последовательность вершин u_1, u_2, \ldots u_nu 
1
​	
 ,u 
2
​	
 ,…u 
n
​	
 , что:

u_1u 
1
​	
  = vv
Каждая вершина встречается в последовательности ровно 11 раз и
Все вершины можно разделить на <<волны>>. Каждая волна - несколько подряд идущих вершин.
У каждой вершины (кроме первой) существует вершина из предыдущей волны, с которой она связана и
Нет таких вершин из более ранних волн.
Вам задан связный неориентированный граф, выведите любой его волновой обход.

Входные данные

В первой строке записано два целых числа nn, mm (1 \leq n \leq 500; 0 \leq m \leq \frac{n \cdot (n - 1)}{2}1≤n≤500;0 ≤m≤ 
2
n⋅(n−1)
​	
 ) - количество вершин и количество ребер.

В следующих mm строках описаны ребра графа. Каждое ребро задается двумя числами u, vu,v (1 \leq u, v \leq n; u \neq v1≤u,v≤n;u

=v) - номера концов ребра. Гарантируется, что каждое ребро описано в графе единожды.

В последней строке записано единственное число vv (1 \leq v \leq n1≤v≤n) - номер вершины, из которой следует начинать обход.

Выходные данные

В единственной строке выведите nn чисел - номера вершин в порядке их волнового обхода. Если допустимых волновых обходов несколько, выведите любой.

Sample Input 1:

5 7
3 5
1 4
1 2
2 4
4 5
3 4
1 3
4
Sample Output 1:

4 1 2 5 3

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long


vector<int> bfs(int start, vector<vector<int>>&& graph) {
    vector<int> res {start};
    vector<int> used(graph.size(), 0);
    queue<int> q;
    q.push(start);

    used[start - 1] = true;
    while (not q.empty()) {
        int v = q.front();
        q.pop();
        for (auto v : graph[v - 1]) {
            if (not used[v - 1]) {
                used[v - 1] = true;
                q.push(v);
                res.push_back(v);
            }
        }
    }
    return res;
}

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b);
        graph[b - 1].push_back(a); 
    }
    int start; // initial node
    cin >> start;
    
    vector<int> res = bfs(start, std::move(graph));
    for (auto i : res) {
        cout << i << ' ';
    }
}
