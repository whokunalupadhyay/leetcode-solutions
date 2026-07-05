class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (auto& [next, wt] : adj[node]) {
            ans = min(ans, wt);

            if (!vis[next]) {
                dfs(next, adj, vis);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        // Build graph
        for (auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> vis(n + 1, false);
        dfs(1, adj, vis);

        return ans;
    }
};