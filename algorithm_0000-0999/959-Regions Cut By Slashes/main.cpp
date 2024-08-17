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
    int unionfind_v1(vector<string>& grid) {
        // Treat a cell as 4 triangles split by cross diagonals

        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        std::function<int(int , int)> getId = [&](int r, int c) {
            return (r * n + c) * 4;
        };

        DisjointSets ds(m * n * 4);
        enum Dir {T = 0, B = 1, L = 2, R = 3};
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int id = getId(r, c);
                if (r > 0) {
                    ds.merge(id + T,  getId(r - 1, c) + B);
                }
                if (c > 0) {
                    ds.merge(id + L,  getId(r, c - 1) + R);
                }

                switch (grid[r][c]) {
                case '/':
                    ds.merge(id + L, id + T);
                    ds.merge(id + R, id + B);
                    break;
                case '\\':
                    ds.merge(id + R, id + T);
                    ds.merge(id + L, id + B);
                    break;
                case ' ':
                    ds.merge(id + L, id + T);
                    ds.merge(id + R, id + B);
                    ds.merge(id + R, id + T);
                    ds.merge(id + L, id + B);
                    break;
                }
            }
        }

        return ds.size();
    }

    int unionfind_v2(vector<string>& grid) {
        // Treat m*n cells as (m+1)*(n+1) points

        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        std::function<int(int , int)> getId = [&](int r, int c) {
            return r * (n + 1) + c;
        };

        DisjointSets ds((m + 1) * (n + 1));
        for (int r = 0; r < m; ++r) {
            ds.merge(getId(r, 0), getId(r + 1, 0));
            ds.merge(getId(r, n), getId(r + 1, n));
        }
        for (int c = 0; c < n; ++c) {
            ds.merge(getId(0, c), getId(0, c + 1));
            ds.merge(getId(m, c), getId(m, c + 1));
        }

        int ret = 1;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                switch (grid[r][c]) {
                case '/':
                {
                    int id1 = getId(r, c + 1), id2 = getId(r + 1, c);
                    if (ds.connected(id1, id2)) { ++ret; }
                    else { ds.merge(id1, id2); }
                    break;
                }
                case '\\':
                {
                    int id1 = getId(r, c), id2 = getId(r + 1, c + 1);
                    if (ds.connected(id1, id2)) { ++ret; }
                    else { ds.merge(id1, id2); }
                    break;
                }
                case ' ':
                    break;
                }
            }
        }

        return ret;
    }

    int dfs(vector<string>& grid) {
        // Treat a cell as 3*3 cells

        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        bool visited[m * 3][n * 3];
        for (int r = 0; r < m * 3; ++r) {
            for (int c = 0; c < n * 3; ++c) {
                visited[r][c] = false;
            }
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                switch (grid[r][c]) {
                case '/':
                {
                    visited[r * 3 + 0][c * 3 + 2] = true;
                    visited[r * 3 + 1][c * 3 + 1] = true;
                    visited[r * 3 + 2][c * 3 + 0] = true;
                    break;
                }
                case '\\':
                {
                    visited[r * 3 + 0][c * 3 + 0] = true;
                    visited[r * 3 + 1][c * 3 + 1] = true;
                    visited[r * 3 + 2][c * 3 + 2] = true;
                    break;
                }
                case ' ':
                    break;
                }
            }
        }

        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        std::function<void(int, int)> f = [&](int r, int c) {
            if (r < 0 || r >= m * 3 || c < 0 || c >= n * 3) { return; }
            if (visited[r][c]) { return; }
            visited[r][c] = true;

            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                f(x, y);
            }
        };

        int ret = 0;
        for (int r = 0; r < m * 3; ++r) {
            for (int c = 0; c < n * 3; ++c) {
                if (visited[r][c]) { continue; }
                ++ret;
                f(r, c);
            }
        }

        return ret;
    }

    int regionsBySlashes(vector<string>& grid) {
        //return unionfind_v1(grid);
        //return unionfind_v2(grid);
        return dfs(grid);
    }
};
