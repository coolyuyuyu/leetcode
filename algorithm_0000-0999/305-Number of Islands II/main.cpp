class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n, -1)
        , m_size(0) {
    }

    void enable(int elem) {
        if (enabled(elem)) { return; }
        m_parents[elem] = elem;
        ++m_size;
    }

    bool enabled(int elem) const {
        return m_parents[elem] != -1;
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
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        std::function<int(int, int)> encode = [&](int r, int c) {
            return r * n + c;
        };

        vector<int> ret(positions.size());

        DisjointSets ds(m * n);
        for (int i = 0; i < positions.size(); ++i) {
            int id1 = encode(positions[i][0], positions[i][1]);
            ds.enable(id1);

            for (const auto& [dr, dc] : dirs) {
                int x = positions[i][0] + dr;
                int y = positions[i][1] + dc;
                if (x < 0 || m <= x || y < 0 || n <= y) { continue; }

                int id2 = encode(x, y);
                if (ds.enabled(id2)) {
                    ds.merge(id1, id2);
                }
            }

            ret[i] = ds.size();
        }

        return ret;
    }
};
