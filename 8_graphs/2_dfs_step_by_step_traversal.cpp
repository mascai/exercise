/*

https://stepik.org/lesson/307331/step/2?unit=289419

Пошаговый обход графа

Пошаговым обходом графа из вершины vv назовём последовательность вершин u_1u 
1
​	
 , u_2u 
2
​	
 , \ldots… u_ru 
r
​	
  такую, что:

u_1 = u_r = vu 
1
​	
 =u 
r
​	
 =v
Каждая вершина графа, достижимая из vv, встречается в ней хотя бы один раз, и
Между любыми двумя соседними вершинами последовательности в графе существует ребро.
Задан связный неориентированный граф и его вершина vv. Выведите любой пошаговый обход этого графа.

Входные данные

В первой строке входного файла записаны два целых числа nn, mm (1 \leq n \leq 100; 0 \leq m \leq 100001≤n≤100;0 ≤m≤10000) - количество вершин и ребер в графе.

Следующие mm строк содержат по два числа через пробел u_i, v_iu 
i
​	
 ,v 
i
​	
  (1 \leq u_i, v_i \leq n1≤u 
i
​	
 ,v 
i
​	
 ≤n); каждая такая строчка означает, что в графе существует ребро между вершинами u_iu 
i
​	
  и v_iv 
i
​	
 .

Последняя строчка содержит единственное целое число vv (1 \leq v \leq n1≤v≤n) - вершина, из которой следует начинать обход.

Выходные данные

В первой строке выведите единственное целое число rr - количество вершин в найденном пошаговом обходе(1 \leq t \leq 100001≤t≤10000; гарантируется, что обход, удовлетворяющий этим ограничениям, существует).

Во второй строке выведите сами числа u_1, u_2, \ldots u_ru 
1
​	
 ,u 
2
​	
 ,…u 
r
​	
  через пробел.

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

9
4 1 2 1 3 5 3 1 4
Sample Input 2:

4 6
3 4
2 4
1 3
1 2
1 4
2 3
4
Sample Output 2:

7
4 3 1 2 1 3 4


*/

#include <bits/stdc++.h>

using namespace std;


void dfs(int v, const vector<vector<int>>& graph, vector<int>& used, vector<int>& res) {
    used[v] = 1;
    res.push_back(v + 1);
    for (auto u : graph[v]) {
        if (not used[u]) {
            dfs(u, graph, used, res);
            res.push_back(v + 1);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int
     i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    int start;
    cin >> start;
    --start;
    vector<int> used(n);
    vector<int> res;
    dfs(start, graph, used, res);

    cout << res.size() << endl;
    for (auto i : res) {
        cout << i << ' ';
    }
}
