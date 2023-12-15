class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ret = 0;
        for (int state = 0; state < (1 << n); ++state) {
            int dist[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = INT_MAX / 3;
                }
            }
            for (int i = 0; i < n; ++i) {
                dist[i][i] = 0;
            }

            for (const auto& road : roads) {
                int u = road[0], v = road[1], w = road[2];
                if (((state >> u) & 1) == 0) { continue; }
                if (((state >> v) & 1) == 0) { continue; }
                for (int i = 0; i < n; ++i) {
                    if (((state >> i) & 1) == 0) { continue; }
                    for (int j = 0; j < n; ++j) {
                        if (((state >> j) & 1) == 0) { continue; }
                        dist[i][j] = std::min(dist[i][j], dist[i][u] + w + dist[v][j]);
                        dist[i][j] = std::min(dist[i][j], dist[i][v] + w + dist[u][j]);
                    }
                }
            }

            bool pass = true;
            for (int i = 0; i < n && pass; ++i) {
                if (((state >> i) & 1) == 0) { continue; }
                for (int j = 0; j < n && pass; ++j) {
                    if (((state >> j) & 1) == 0) { continue; }
                    if (dist[i][j] > maxDistance) {
                        pass = false;
                    }
                }
            }

            if (pass) {
                ++ret;
            }
        }

        return ret;
    }
};
