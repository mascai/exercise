#include <bits/stdc++.h>

using namespace std;

// O(NumNodes + NumRibs)
void dfs(int startNode, const vector<vector<int>>& graph, vector<int>& used) {
    used[startNode] = 1;
    for (auto curNode : graph[startNode]) {
        if (not used[curNode]) {
            dfs(curNode, graph, used);
        }
    }
}

// paint adjacent components
void dfsPaintAdjacentComponents(int startNode, const vector<vector<int>>& graph, vector<int>& used, int color) {
  used[startNode] = color;
  for (auto curNode : graph[startNode]) {
      if (not used[curNode]) {
          dfsPaintAdjacentComponents(startNode, graph, used, color);
      }
  }
}


// Find cycle
bool cycle = false;

void findCycle(int start, vector<int>& color, vector<int>& prev, const vector <vector<int>>& g) {
    color[start - 1] = 1; // gray
    for (auto v : g[start - 1]) {
        if (color[v - 1] == 0) {
            prev[v - 1] = start;
            findCycle(v, color, prev, g);
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

    string s;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        int a = stoi(s);
        cin >> s;
        int b = stoi(s);
        graph[a - 1].push_back(b);
        graph[b - 1].push_back(a);
    }

    vector<int> prev(n, -1);
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            findCycle(i, color, prev, graph);
        }
    }
    if (cycle) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
