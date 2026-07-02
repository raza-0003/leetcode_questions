class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> best(n, vector<int>(m, -1));

        pq.push({startHealth, {0, 0}});
        best[0][0] = startHealth;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int h = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;

            // Ignore outdated state
            if (h < best[x][y]) continue;

            if (x == n - 1 && y == m - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                int newHealth = h - grid[nx][ny];

                if (newHealth <= 0)
                    continue;

                if (newHealth > best[nx][ny]) {
                    best[nx][ny] = newHealth;
                    pq.push({newHealth, {nx, ny}});
                }
            }
        }

        return false;
    }
};