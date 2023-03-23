class DisjointSets {
public:
    DisjointSets(int n)
        : m_roots(n)
        , m_size(n) {
        std::iota(m_roots.begin(), m_roots.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_roots[root1] = root2;
            --m_size;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

    size_t size() const {
        return m_size;
    }

private:
    int root(int elem) const {
        if (m_roots[elem] != elem) {
            m_roots[elem] = root(m_roots[elem]);
        }
        return m_roots[elem];
    }

    mutable vector<int> m_roots;
    int m_size;
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSets ds(n);

        int redundant = 0;
        for (const auto& conn : connections) {
            if (ds.connected(conn[0], conn[1])) {
                redundant++;
            }
            else {
                ds.merge(conn[0], conn[1]);
            }
        }
        assert(0 < ds.size());

        return ((ds.size() - 1) <= redundant) ? (ds.size() - 1) : -1;
    }
};
