class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n)
        , m_cardinality(n, 1)
        , m_size(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
            m_cardinality[root2] += m_cardinality[root1];
            --m_size;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

    int cardinality(int elem) const {
        return m_cardinality[root(elem)];
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
    vector<int> m_cardinality;
    int m_size;
};


class Solution {
public:
    int byDFS(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        std::function<void(int, int)> dfs = [&](int r, int c) {
            grid[r][c] = 0;
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                if (grid[x][y] == 0) { continue; }

                dfs(x, y);
            }
        };
        for (int r = 0; r < m; ++r) {
            if (grid[r][0] == 1) {
                dfs(r, 0);
            }
            if (grid[r][n - 1] == 1) {
                dfs(r, n - 1);
            }
        }
        for (int c = 0; c < n; ++c) {
            if (grid[0][c] == 1) {
                dfs(0, c);
            }
            if (grid[m - 1][c] == 1) {
                dfs(m - 1, c);
            }
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    ++ret;
                }
            }
        }

        return ret;
    }

    int byDSU(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int boundaryId = m * n;
        std::function<int(int, int)> getId = [&](int r, int c) {
            return r * n + c;
        };

        DisjointSets ds(m * n + 1);

        int landCnt = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    ++landCnt;

                    if (r == 0 || c == 0 || r == (m - 1) || c == (n - 1)) {
                        ds.merge(getId(r, c), boundaryId);
                    }

                    if (r + 1 < m && grid[r + 1][c] == 1) {
                        ds.merge(getId(r, c), getId(r + 1, c));
                    }
                    if (c + 1 < n && grid[r][c + 1] == 1) {
                        ds.merge(getId(r, c), getId(r, c + 1));
                    }
                }
            }
        }

        return ret - ds.cardinality(boundaryId) + 1;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        //return byDFS(grid);
        return byDSU(grid);
    }
};
