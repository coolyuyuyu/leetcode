class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap.empty() ? 0 : heightMap[0].size();

        bool visited[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                visited[r][c] = false;
            }
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> pq;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 || r == m - 1 || c == 0 || c == n - 1) {
                    visited[r][c] = true;
                    pq.emplace(heightMap[r][c], r, c);
                }
            }
        }

        int ret = 0;

        int curH = INT_MIN;
        while (!pq.empty()) {
            auto [h, r, c] = pq.top();
            pq.pop();

            curH = std::max(curH, heightMap[r][c]);
            ret += curH - heightMap[r][c];

            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                if (visited[x][y]) { continue; }

                visited[x][y] = true;
                pq.emplace(heightMap[x][y], x, y);
            }
        }

        return ret;
    }
};
