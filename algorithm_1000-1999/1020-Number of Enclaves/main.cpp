class DisjointSets {
public:
    DisjointSets(int n)
        : m_roots(n) {
        std::iota(m_roots.begin(), m_roots.end(), 0);
    }

    void enable(int elem) {
        if (m_roots[elem] == -1) {
            m_roots[elem] = elem;
        }
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_roots[root1] = root2;
        }
    }

    int root(int elem) const {
        if (m_roots[elem] != elem) {
            m_roots[elem]  = root(m_roots[elem]);
        }

        return m_roots[elem];
    }

private:
    mutable vector<int> m_roots;
};
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int cornerId = m * n;
        auto getId = [m, n](int r, int c) {
            return r * n + c;
        };

        DisjointSets ds(m * n + 1);
        ds.enable(cornerId);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    int id = getId(r, c);

                    if (r == 0 || c == 0 || r == (m - 1) || c == (n - 1)) {
                        ds.merge(id, cornerId);
                    }
                    if ((r + 1) < m && grid[r + 1][c] == 1) {
                        ds.merge(id, getId(r + 1, c));
                    }
                    if ((c + 1) < n && grid[r][c + 1] == 1) {
                        ds.merge(id, getId(r, c + 1));
                    }
                }
            }
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    if (ds.root(getId(r, c)) != ds.root(cornerId)) {
                        ++ret;
                    }
                }
            }
        }

        return ret;
    }
};
