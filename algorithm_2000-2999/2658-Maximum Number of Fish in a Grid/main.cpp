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
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        DisjointSets ds(m * n);
        std::function<int(int, int)> getId = [&](int r, int c) {
            return r * n + c;
        };

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) { continue; }
                int id1 = getId(r, c);
                if (r > 0 && grid[r - 1][c]) {
                    int id2 = getId(r - 1, c);
                    ds.merge(id1, id2);
                }
                if (c > 0 && grid[r][c - 1]) {
                    int id2 = getId(r, c - 1);
                    ds.merge(id1, id2);
                }
            }
        }

        unordered_map<int, int> root2fish;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) { continue; }
                root2fish[ds.root(getId(r, c))] += grid[r][c];
            }
        }

        int ret = 0;
        for (const auto& [_, fish] : root2fish) {
            ret = std::max(ret, fish);
        }

        return ret;
    }
};
