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

    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

private:
    mutable vector<int> m_parents;
};

class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1.empty() ? 0 : grid1[0].size();

        std::function<int(int, int)> getId = [&](int r, int c) {
            return r * n + c;
        };

        DisjointSets ds(m * n);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (!grid1[r][c]) { continue; }
                if (r > 0 && grid1[r - 1][c]) {
                    ds.merge(getId(r, c), getId(r - 1, c));
                }
                if (c > 0 && grid1[r][c - 1]) {
                    ds.merge(getId(r, c), getId(r, c - 1));
                }
            }
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (!grid1[r][c] || !grid2[r][c]) { continue; }

                int group = ds.root(getId(r, c));
                bool sameGroup = true;
                queue<pair<int, int>> q;
                q.emplace(r, c);
                grid2[r][c] = 0;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    if (ds.root(getId(x, y)) != group) {
                        sameGroup = false;
                    }

                    for (const auto& [dr, dc] : dirs) {
                        int a = x + dr, b = y + dc;
                        if (a < 0 || a >= m || b < 0 || b >= n) { continue; }
                        if (grid2[a][b] == 0) { continue; }

                        grid2[a][b] = 0;
                        q.emplace(a, b);
                    }
                }

                if (sameGroup) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};