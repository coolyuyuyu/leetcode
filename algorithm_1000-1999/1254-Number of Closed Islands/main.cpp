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
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int boundaryId = m * n;
        std::function<int(int, int)> getId = [&](int r, int c) {
            return r * n + c;
        };

        DisjointSets ds(m * n + 1);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    if (r == 0 || c == 0 || r == (m - 1) || c == (n - 1)) {
                        ds.merge(getId(r, c), boundaryId);
                    }
                    if (r + 1 < m && grid[r + 1][c] == 0) {
                        ds.merge(getId(r, c), getId(r + 1, c));
                    }
                    if (c + 1 < n && grid[r][c + 1] == 0) {
                        ds.merge(getId(r, c), getId(r, c + 1));
                    }
                }
                else {
                    ds.merge(getId(r, c), boundaryId);
                }
            }
        }

        return ds.size() - 1;
    }
};
