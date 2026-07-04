#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Build adjacency list with edge weights
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        // DFS traversal
        vector<bool> visited(n+1, false);
        int minEdge = INT_MAX;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (auto &nbr : adj[node]) {
                minEdge = min(minEdge, nbr.second); // track minimum edge weight
                if (!visited[nbr.first]) {
                    dfs(nbr.first);
                }
            }
        };

        dfs(1); // start from city 1
        return minEdge;
    }
};
