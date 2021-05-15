#include <bits/stdc++.h>

#define ll long long

using namespace std;


// O(NumNodes + NumRibs)
void bfs(int startNode, const vector<vector<int>>& graph, vector<int>& used) {
    queue<int> q;
    q.push(startNode);
    used[startNode] = 1;

    while (not q.empty()) {
        int curNode = q.front();
        q.pop();
        for (auto v : graph[curNode]) {
            if (not used[v]) {
                q.push(v);
                used[v] = true;
            }
        }
    }    
}


void getDistance(int start, const vector<vector<int>>& graph, vector<int>& dist) {
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
        getDistance(i, graph, dist);
        for (auto item : dist) {
            res += item;
        }
    }
    cout << res / 2;;
    return 0;
}   
    
