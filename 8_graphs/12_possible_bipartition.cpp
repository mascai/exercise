/*
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= n <= 2000
0 <= dislikes.length <= 104
dislikes[i].length == 2
1 <= dislikes[i][j] <= n
ai < bi
All the pairs of dislikes are unique.

*/


class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for (auto vec : dislikes) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }

        vector<int> colors(n + 1, 0); // 0 -- not visited, 1 / -1 -- colored
        vector<int> visited(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (visited[i]) {
                continue; // already visited
            }
            colors[i] = 1;
            queue<int> q;
            q.push(i);
            while (not q.empty()) {
                int curr = q.front();
                q.pop();
                if (visited[curr]) {
                    continue;
                }
                visited[curr] = 1;

                for (int adjacent : graph[curr]) {
                    if (colors[curr] == colors[adjacent]) {
                        return false;
                    }
                    colors[adjacent] = colors[curr] == -1 ? 1 : -1;
                    q.push(adjacent);
                }
            }
        }
        return true;
    }
};
