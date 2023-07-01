class DisjointSets {
public:
    DisjointSets(size_t n)
        : m_parents(n)
        , m_sizes(n, 1) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
            m_sizes[root2] += m_sizes[root1];
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

    int size(int elem) const {
        return m_sizes[root(elem)];
    }

private:
    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }
        return m_parents[elem];
    }

    mutable vector<int> m_parents;
    vector<int> m_sizes;
};

class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    vector<int> byUnionFind(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        for (const auto& hit : hits) {
            int r = hit[0], c = hit[1];
            grid[r][c] *= -1;
        }

        std::function<int(int, int)> getId = [&](int r, int c) {
            return r * n + c;
        };

        int ceilId = m * n;
        DisjointSets ds(m * n + 1);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] != 1) { continue; }
                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                    if (grid[x][y] != 1) { continue; }
                    ds.merge(getId(r, c), getId(x, y));
                }
            }
        }
        for (int c = 0; c < n; ++c) {
            if (grid[0][c] == 1) {
                ds.merge(getId(0, c), ceilId);
            }
        }

        vector<int> ret(hits.size());
        for (int i = hits.size(); 0 < i--;) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) {
                ret[i] = 0;
                continue;
            }

            grid[r][c]= 1;
            if (r == 0) {
                ds.merge(getId(r, c), ceilId);
            }

            bool connectCeil = (r == 0);
            int count = 0;
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                if (grid[x][y] != 1) { continue; }
                if (ds.connected(getId(r, c), getId(x, y))) { continue; }

                if (ds.connected(getId(x, y), ceilId)) {
                    connectCeil = true;
                }
                else {
                    count += ds.size(getId(x, y));
                }
                ds.merge(getId(r, c), getId(x, y));
            }
            ret[i] = (connectCeil ? count : 0);
        }

        return ret;
    }

    vector<int> byDfs(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        for (const auto& hit : hits) {
            int r = hit[0], c = hit[1];
            grid[r][c] *= -1;
        }

        std::function<int(int, int)> dfs = [&](int r, int c) {
            grid[r][c] = 2;

            int count = 1;
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                if (grid[x][y] != 1) { continue; }
                count += dfs(x, y);
            }

            return count;
        };
        for (int c = 0; c < n; ++c) {
            if (grid[0][c] == 1) {
               dfs(0, c);
            }
        }

        vector<int> ret(hits.size());
        for (int i = hits.size(); 0 < i--;) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) {
                ret[i] = 0;
                continue;
            }

            grid[r][c]= 1;

            bool connectCeil = (r == 0);
            if (!connectCeil) {
                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                    if (grid[x][y] == 2) {
                        connectCeil = true;
                        break;
                    }
                }
            }
            ret[i] = (connectCeil ? dfs(r, c) - 1 : 0);
        }

        return ret;

    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        //return byUnionFind(grid, hits);
        return byDfs(grid, hits);
    }
};
