class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        bool visited[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                visited[r][c] = false;
            }
        }

        int k = queries.size();
        int indexes[k];
        std::iota(indexes, indexes + k, 0);
        std::sort(indexes, indexes + k, [&](int idx1, int idx2) { return queries[idx1] < queries[idx2]; });

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> pq;
        visited[0][0] = true;
        pq.emplace(grid[0][0], 0, 0);

        vector<int> ret(k);
        for (int i = 0, cnt = 0; i < k; ++i) {
            int query = queries[indexes[i]];
            while (!pq.empty() && query > std::get<0>(pq.top())) {
                auto [val, r, c] = pq.top();
                pq.pop();

                ++cnt;

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                    if (visited[x][y]) { continue; }
                    visited[x][y] = true;
                    pq.emplace(grid[x][y], x, y);
                }
            }

            ret[indexes[i]] = cnt;
        }

        return ret;
    }
};
