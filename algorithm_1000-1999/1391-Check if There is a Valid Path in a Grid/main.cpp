class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

private:
    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

    mutable vector<int> m_parents;
};

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        std::function<int(int, int)> getId = [&](int r, int c) {
            return r * n + c;
        };
        int src = getId(0, 0), dst = getId(m - 1, n - 1);

        DisjointSets ds(m * n);
        for (int curR = 0; curR < m; ++curR) {
            for (int curC = 0; curC < n; ++curC) {
                int curT = grid[curR][curC];
                int curId = getId(curR, curC);
                if (curR > 0) {
                    int preT = grid[curR - 1][curC];
                    int preId = getId(curR - 1, curC);
                    if ((curT == 2 || curT == 5 || curT == 6) && (preT == 2 || preT == 3 || preT == 4)) {
                        ds.merge(curId, preId);
                    }
                }
                if (curC > 0) {
                    int preT = grid[curR][curC - 1];
                    int preId = getId(curR, curC - 1);
                    if ((curT == 1 || curT == 3 || curT == 5) && (preT == 1 || preT == 4 || preT == 6)) {
                        ds.merge(curId, preId);
                    }
                }
            }
        }

        return ds.connected(src, dst);
    }
};
