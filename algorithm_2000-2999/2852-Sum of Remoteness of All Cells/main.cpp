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

    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

private:
    mutable vector<int> m_parents;
    int m_size;
};

class Solution {
public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        int n = grid.size();

        std::function<int(int, int)> getId = [&](int r, int c) {
            return r * n + c;
        };

        long long total = 0;
        DisjointSets ds(n * n);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] < 0) { continue; }
                total += grid[r][c];
                int id1 = getId(r, c);
                if (r > 0) {
                    int x = r - 1, y = c;
                    if (grid[x][y] >= 0) {
                        int id2 = getId(x, y);
                        ds.merge(id1, id2);
                    }
                }
                if (c > 0) {
                    int x = r, y = c - 1;
                    if (grid[x][y] >= 0) {
                        int id2 = getId(x, y);
                        ds.merge(id1, id2);
                    }
                }
            }
        }

        unordered_map<int, pair<int, long long>> root2cntsum;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] < 0) { continue; }
                int id = getId(r, c);
                auto& [cnt, sum] = root2cntsum[ds.root(id)];
                cnt += 1;
                sum += grid[r][c];
            }
        }

        long long ret = 0;
        for (const auto& [_, p] : root2cntsum) {
            const auto& [cnt, sum] = p;
            ret += cnt * (total - sum);
        }

        return ret;
    }
};
