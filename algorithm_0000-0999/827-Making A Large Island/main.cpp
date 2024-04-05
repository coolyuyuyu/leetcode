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

    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

private:
    mutable vector<int> m_parents;
    vector<int> m_cardinality;
    int m_size;
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        std::function<int(int, int)> getId = [&](int r, int c) {
            return r * n + c;
        };

        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        DisjointSets ds(m * n);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) { continue; }
                if (r > 0 && grid[r - 1][c]) { ds.merge(getId(r, c), getId(r - 1, c)); }
                if (c > 0 && grid[r][c - 1]) { ds.merge(getId(r, c), getId(r, c - 1)); }
            }
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c]) {
                    ret = std::max(ret, ds.cardinality(getId(r, c)));
                }
                else {
                    int other = 0;
                    unordered_set<int> roots;
                    for (const auto& [dr, dc] : dirs) {
                        int x = r + dr, y = c + dc;
                        if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                        if (grid[x][y] && roots.insert(ds.root(getId(x, y))).second) {
                            other += ds.cardinality(getId(x, y));
                        }
                    }
                    ret = std::max(ret, 1 + other);
                }
            }
        }

        return ret;
    }
};
