class Solution {
public:
    // Direction vectors for moving up, down, left, and right
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Edge Case: If the start or end cell has a thief, safeness factor is 0
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }

        // ---------------------------------------------------------------------
        // PHASE 1: Multi-Source BFS to calculate distance to the nearest thief
        // ---------------------------------------------------------------------
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Push all thieves into the queue to start radiating outward simultaneously
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // Standard BFS layer-by-layer
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // If within bounds and hasn't been visited yet
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // ---------------------------------------------------------------------
        // PHASE 2: Dijkstra-style Max-Heap to find the safest path
        // ---------------------------------------------------------------------
        // Priority Queue stores: {safeness_factor, {x, y}}
        // Default C++ priority_queue is a Max-Heap, which is exactly what we want
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // Initialize with the starting cell (0, 0)
        pq.push({dist[0][0], {0, 0}});
        visited[0][0] = true;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int current_safeness = it.first;
            int x = it.second.first;
            int y = it.second.second;

            // Since it's a Max-Heap, the first time we reach the destination, 
            // it is guaranteed to be the path with the maximum possible safeness factor.
            if (x == n - 1 && y == n - 1) {
                return current_safeness;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // Check bounds and make sure it's not visited
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    
                    // The safeness of a path is limited by the minimum cell value along it
                    int next_safeness = min(current_safeness, dist[nx][ny]);
                    pq.push({next_safeness, {nx, ny}});
                }
            }
        }

        return 0;
    }
};