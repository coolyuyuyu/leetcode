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
    int byBFS(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        std::function<int(int, int)> f = [&](int r, int c) {
            assert(grid[r][c] == 1);
            grid[r][c] = 0;

            int area = 1;
            for (queue<pair<int, int>> q({{r, c}}); !q.empty();) {
                auto [r, c] = q.front();
                q.pop();

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                    if (grid[x][y] == 0) { continue; }

                    ++area;
                    grid[x][y] = 0;

                    q.emplace(x, y);
                }
            }

            return area;
        };

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    ret = std::max(ret, f(r, c));
                }
            }
        }

        return ret;
    }

    int byDSU(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        std::function<int(int, int)> getId = [&](int r, int c) {
            return r * n + c;
        };

        DisjointSets ds(m * n);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    if (r + 1 < m && grid[r + 1][c] == 1) {
                        ds.merge(getId(r, c), getId(r + 1, c));
                    }
                    if (c + 1 < n && grid[r][c + 1] == 1) {
                        ds.merge(getId(r, c), getId(r, c + 1));
                    }
                }
            }
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    ret = std::max(ret, ds.cardinality(getId(r, c)));
                }
            }
        }

        return ret;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //return byBFS(grid);
        return byDSU(grid);
    }
};
