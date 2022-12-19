class DisjointSet {
public:
    DisjointSet(size_t n)
        : m_roots(n) {
        std::iota(m_roots.begin(), m_roots.end(), 0);
    }

    void connect(int elem1, int elem2) {
        int root1 = root(elem1);
        int root2 = root(elem2);
        if (root1 != root2) {
            m_roots[root1] = root2;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

private:
    int root(int elem) const {
        if (m_roots[elem] != elem) {
            m_roots[elem] = root(m_roots[elem]);
        }
        return m_roots[elem];
    }

    mutable vector<int> m_roots;
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);
        for (const auto& edge : edges) {
            ds.connect(edge[0], edge[1]);
        }

        return ds.connected(source, destination);
    }
};
