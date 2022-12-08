class DisjointSets {
public:
    DisjointSets(size_t n)
        : m_roots(n) {
        std::iota(m_roots.begin(), m_roots.end(), (size_t)0);
    }

    void merge(size_t elem1, size_t elem2) {
        size_t root1 = root(elem1);
        size_t root2 = root(elem2);
        if (root1 != root2) {
            m_roots[root1] = root2;
        }
    }

    bool connected(size_t elem1, size_t elem2) const {
        return root(elem1) == root(elem2);
    }

private:
    size_t root(size_t elem) const {
        if (m_roots[elem] != elem) {
            m_roots[elem] = root(m_roots[elem]);
        }

        return m_roots[elem];
    }

    mutable vector<size_t> m_roots;
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSets ds(n + 1);
        for (const auto& road : roads) {
            ds.merge(road[0], road[1]);
        }

        int m = INT_MAX;
        for (const auto& road : roads) {
            if (ds.connected(1, road[0])) {
                 if (road[2] < m) {
                    m = road[2];
                }
            }
        }

        return m;
    }
};
