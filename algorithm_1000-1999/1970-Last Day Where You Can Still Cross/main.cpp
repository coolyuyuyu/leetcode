class DisjointSets {
public:
    DisjointSets(size_t n)
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
    int byDisjointedSets(int row, int col, const vector<vector<int>>& cells) {
        int m = row, n = col;
        vector<vector<int>> grid(m, vector<int>(n, 0));

        std::function<int(int, int)> getId = [&](int r, int c) {
            return r * n + c;
        };
        int virtLft = m * n, virtRht = m * n + 1;

        vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        DisjointSets ds(row * col + 2);
        for (int t = 0; t < cells.size(); ++t) {
            int r = cells[t][0] - 1, c = cells[t][1] - 1;
            grid[r][c] = 1;

            int id = getId(r, c);
            if (c == 0) {
                ds.merge(virtLft, id);
            }
            if ((c + 1) == n) {
                ds.merge(id, virtRht);
            }

            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || row <= x || y < 0 || col <= y) { continue; }
                if (grid[x][y] == 0) { continue; }
                ds.merge(id, getId(x, y));
            }

            if (ds.connected(virtLft, virtRht)) {
                return t;
            }
        }

        return cells.size();
    }

    int byBinarySearchBFS(int row, int col, vector<vector<int>>& cells) {
        int m = row, n = col;

        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        std::function<bool(int)> canAcrossTopBtm = [&](int t) {
            vector<vector<int>> grid(m, vector<int>(n, 0));
            for (int i = 0; i < t; ++i) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }

            queue<pair<int, int>> q;
            for (int c = 0; c < n; ++c) {
                if (grid[0][c] == 0) {
                    grid[0][c] = -1;
                    q.emplace(0, c);
                }
            }

            while (!q.empty()) {
                for (int len = q.size(); 0 < len--;) {
                    auto [r, c] = q.front();
                    q.pop();

                    if ((r + 1) == m) {
                        return true;
                    }

                    for (const auto& [dr, dc] : dirs) {
                        int x = r + dr, y = c + dc;
                        if (x < 0 || m <= x || y < 0 || n <= y) { continue; };
                        if (grid[x][y] == 0) {
                            grid[x][y] = -1;
                            q.emplace(x, y);
                        }
                    }
                }
            }

            return false;
        };

        int lo = 1, hi = cells.size();
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (canAcrossTopBtm(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }

        }

        return lo;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        //return byDisjointedSets(row, col, cells);
        return byBinarySearchBFS(row, col, cells);
    }
};
