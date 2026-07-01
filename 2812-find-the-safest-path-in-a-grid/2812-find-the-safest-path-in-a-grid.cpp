class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }

        auto check = [&](int mid) {
            if (dist[0][0] < mid) return false;

            vector<vector<bool>> vis(n, vector<bool>(n,false));
            queue<pair<int,int>> q;

            q.push({0,0});
            vis[0][0] = true;

            while (!q.empty()) {
                auto [x,y] = q.front();
                q.pop();

                if (x == n-1 && y == n-1)
                    return true;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;

                    if (vis[nx][ny])
                        continue;

                    if (dist[nx][ny] < mid)
                        continue;

                    vis[nx][ny] = true;
                    q.push({nx,ny});
                }
            }

            return false;
        };

        int lo = 0, hi = 2 * n;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (check(mid))
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return hi;
    }
};