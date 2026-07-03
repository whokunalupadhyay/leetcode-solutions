class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        int lo = INT_MAX, hi = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if ((u != 0 && u != n - 1 && !online[u]) ||
                (v != 0 && v != n - 1 && !online[v]))
                continue;

            adj[u].push_back({v, w});
            lo = min(lo, w);
            hi = max(hi, w);
        }

        if (lo == INT_MAX) return -1;

        auto check = [&](int mid) {
            vector<long long> dist(n, LLONG_MAX);
            priority_queue<pair<long long,int>,
                           vector<pair<long long,int>>,
                           greater<pair<long long,int>>> pq;

            dist[0] = 0;
            pq.push({0, 0});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d != dist[u]) continue;
                if (u == n - 1) return true;

                for (auto &[v, w] : adj[u]) {
                    if (w < mid) continue;

                    long long nd = d + w;
                    if (nd < dist[v] && nd <= k) {
                        dist[v] = nd;
                        pq.push({nd, v});
                    }
                }
            }

            return false;
        };

        if (!check(lo)) return -1;

        int ans = lo;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};