/*
Задача на DFS

Имеется прямоугольный лабиринт размерами N x M. В лабиринте имеется вход, помеченный
знаком @, выход, помеченный знаком #, стены, обозначенные знаком +. Свободные клетки обо-
значаются точкой.
Требуется определить наименьшее число ходов для того, чтобы, двигаясь по свободным клеткам,
попасть из входа в выход. Движение возможно только по горизонтали и вертикали (до 4-х ходов из
клетки, не находящейся на границе).
Формат входных данных
4 4
+@++
+.++
+...
+++#
Ans: 5
*/

#include <bits/stdc++.h>

bool check_way(char ch) {
    return ch == '.' || ch == '@' || ch == '#';
}

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>>v(n, vector<char>(m)); // input labirint
    vector<vector<int>>graph(n*m);
    int start_i = 0, start_j = 0, end_i = 0, end_j = 0;;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == '@') {
                start_i = i;
                start_j = j;
            }
            if (v[i][j] == '#') {
                end_i = i;
                end_j = j;
            }
        }
    }
    int s = start_i * m + start_j;
    int to = end_i * m + end_j;
    // generate graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check_way(v[i][j])) {
                if (i + 1 < n && check_way(v[i + 1][j])) {
                    graph[m * i + j].push_back(m * (i + 1) + j);
                    graph[m * (i + 1) + j].push_back(m * i + j);
                }
                if (i - 1 >= 0  && check_way(v[i - 1][j])) {
                    graph[m * i + j].push_back(m * (i - 1) + j);
                    graph[m * (i - 1) + j].push_back(m * i + j);
                }
                if (j + 1 < m && check_way(v[i][j + 1])) {
                    graph[m * i + j + 1].push_back(m * i + j);
                    graph[m * i + j].push_back(m * i + j + 1);
                }
                if (j - 1 >= 0 && check_way(v[i][j - 1])) {
                    graph[m * i + j - 1].push_back(m * i + j);
                    graph[m * i + j].push_back(m * i + j - 1);
                }
            }
        }
    }
    queue<int> q;
    q.push(s); // id of the start
    vector<bool> used(n * m);
    vector<int> d(n * m), p(n * m);
    used[s] = true;
    p[s] = -1;
    // DFS
    while (q.front() != to) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < graph[v].size(); ++i) {
            int to = graph[v][i];
            if (!used[to]) {
                used[to] = true;
                q.push (to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    for (auto item : used) {
        cout << item << ' ';
    }
    cout << endl;
    //int to = end_i * m + end_j;
    cout << s << ' ' << to << endl;

    if (!used[to]) {
        cout << "No path!";
        return 0;
    }else {
        vector<int> path;
        for (int v=to; v!=-1; v=p[v])
            path.push_back (v);

        cout << path.size() - 1 << endl;
        reverse (path.begin(), path.end());
        cout << "Path: ";
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] + 1 << " ";

    }
    return 0;
}
