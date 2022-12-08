class DisjointSets {
public:
    DisjointSets(size_t n)
        : m_roots(n)
        , m_size(n) {
        std::iota(m_roots.begin(), m_roots.end(), (size_t)0);
    }

    void merge(size_t elem1, size_t elem2) {
        size_t root1 = root(elem1);
        size_t root2 = root(elem2);
        if (root1 != root2) {
            m_roots[root1] = root2;
            --m_size;
        }
    }

    size_t size() const {
        return m_size;
    }

private:
    size_t root(size_t elem) const {
        if (m_roots[elem] != elem) {
            m_roots[elem] = root(m_roots[elem]);
        }

        return m_roots[elem];
    }

    mutable std::vector<size_t> m_roots;
    size_t m_size;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSets ds(n);
        for (const auto& e : edges) {
            ds.merge(e[0], e[1]);
        }

        return ds.size();
    }
};
