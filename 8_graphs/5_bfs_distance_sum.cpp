/*
https://stepik.org/lesson/307332/step/5?unit=289420


Сумма расстояний

Дан связный неориентированный граф. Требуется найти сумму расстояний между всеми неупорядоченными парами вершин.

Входные данные

Первая строка входного файла содержит два натуральных числа nn и mm -  количество вершин и ребер графа соответственно (1 \le n \le 10001≤n≤1000, 0 \le m \le 10\,0000≤m≤10000).

Следующие mm строк содержат описание ребер по одному на строке.  Ребро номер ii описывается двумя натуральными числами b_ib 
i
​	
 , e_ie 
i
​	
  -  номерами концов ребра (1 \le b_i, e_i \le n1≤b 
i
​	
 ,e 
i
​	
 ≤n).

Гарантируется, что граф связен.

Выходные данные

Первая строка выходного файла должна содержать одно натуральное число -  сумму попарных расстояний между вершинами.

Sample Input 1:

5 5
1 2
2 3
3 4
5 3
1 5
Sample Output 1:

16
Sample Input 2:

2 1
2 1
Sample Output 2:

1


*/


#include <bits/stdc++.h>

using namespace std;

#define ll long long

void bfs(int start, const vector<vector<int>>& graph, vector<int>& dist) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (not q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : graph[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    } 
}

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());

    string s;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    long long res = 0; // sum of distances between all nodes

    vector<int> dist;
    for (int i = 0; i < n; ++i) {
        dist.assign(n, -1);
        bfs(i, graph, dist);
        for (auto item : dist) {
            res += item;
        }
    }
    cout << res / 2;;
    return 0;
}   
    
