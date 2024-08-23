class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid) {
        int n = grid.size();
        m_sums.resize(n * n);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                int asum = 0;
                for (const auto& [dr, dc]: s_adirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= n || y < 0 || y >= n) { continue; }
                    asum += grid[x][y];
                }

                int dsum = 0;
                for (const auto& [dr, dc]: s_ddirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= n || y < 0 || y >= n) { continue; }
                    dsum += grid[x][y];
                }

                m_sums[grid[r][c]] = {asum, dsum};
            }
        }
    }

    int adjacentSum(int value) {
        return m_sums[value].first;
    }

    int diagonalSum(int value) {
        return m_sums[value].second;
    }

private:
    static inline vector<pair<int, int>> s_adirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    static inline vector<pair<int, int>> s_ddirs = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

    vector<pair<int, int>> m_sums;
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
