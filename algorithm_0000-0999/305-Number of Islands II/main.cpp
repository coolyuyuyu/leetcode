class DisjointSets {
public:
    DisjointSets(size_t n)
        : m_size(0)
        , m_parents(n, -1) {
    }

    size_t size() const {
        return m_size;
    }

    void fill(int elem) {
        if (filled(elem)) {
            return;
        }

        ++m_size;
        m_parents[elem] = elem;
    }

    bool filled(int elem) {
        return 0 <= m_parents[elem];
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            --m_size;
            m_parents[root1] = root2;
        }
    }

private:
    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }
        return m_parents[elem];
    }

    size_t m_size;
    mutable vector<int> m_parents;
};

class Solution {
public:
    vector<array<int, 2>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        auto encode = [m, n](const vector<int>& position) -> int {
            return position[0] * n + position[1];
        };

        DisjointSets ds(m * n);

        vector<int> ret(positions.size());
        for (int i = 0; i < positions.size(); ++i) {
            const vector<int>& position = positions[i];

            int id = encode(position);
            ds.fill(id);

            for (const auto& dir : dirs) {
                vector<int> neighbor = {position[0] + dir[0], position[1] + dir[1]};
                if (neighbor[0] < 0 || m <= neighbor[0] || neighbor[1] < 0 || n <= neighbor[1]) {
                    continue;
                }

                int neighborId = encode(neighbor);
                if (!ds.filled(neighborId)) {
                    continue;
                }

                ds.merge(id, neighborId);
            }

            ret[i] = ds.size();
        }

        return ret;
    }
};
