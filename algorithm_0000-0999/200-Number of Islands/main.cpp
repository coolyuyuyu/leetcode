class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n)
        , m_size(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
            --m_size;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

    int size() const {
        return m_size;
    }

private:
    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

    mutable vector<int> m_parents;
    int m_size;
};

class Solution {
public:
    int bfs(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        std::function<void(int, int)> f = [&](int r, int c) {
            grid[r][c] = '0';
            for (queue<pair<int, int>> q({{r, c}}); !q.empty();) {
                auto [r, c] = q.front();
                q.pop();
                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                    if (grid[x][y] == '0') { continue; }
                    grid[x][y] = '0';
                    q.emplace(x, y);
                }
            }
        };

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '1') {
                    f(r, c);
                    ++ret;
                }
            }
        }

        return ret;
    }

    int dfs(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        std::function<void(int, int)> f = [&](int r, int c) {
            grid[r][c] = '0';
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                if (grid[x][y] == '0') { continue; }
                f(x, y);
            }
        };

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '1') {
                    f(r, c);
                    ++ret;
                }
            }
        }

        return ret;
    }

    int dsu(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        std::function<int(int, int)> getId = [&](int r, int c) {
            return r * n + c;
        };

        DisjointSets ds(m * n);
        int seaCnt = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '1') {
                    if (r + 1 < m && grid[r + 1][c] == '1') {
                        ds.merge(getId(r, c), getId(r + 1, c));
                    }
                    if (c + 1 < n && grid[r][c + 1] == '1') {
                        ds.merge(getId(r, c), getId(r, c + 1));
                    }
                }
                else {
                    ++seaCnt;
                }
            }
        }

        return ds.size() - seaCnt;
    }

    int numIslands(vector<vector<char>>& grid) {
        return bfs(grid);
        //return dfs(grid);
        //return dsu(grid);
    }
};
