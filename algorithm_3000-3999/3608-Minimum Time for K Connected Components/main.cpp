class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n)
        , m_cardinality(n, 1)
        , m_size(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
            m_cardinality[root2] += m_cardinality[root1];
            --m_size;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

    int cardinality(int elem) const {
        return m_cardinality[root(elem)];
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
    vector<int> m_cardinality;
    int m_size;
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        std::sort(edges.begin(), edges.end(), [](auto& e1, auto & e2) { return e1[2] > e2[2]; });

        DisjointSets ds(n);
        for (const auto& edge: edges) {
            int u = edge[0], v = edge[1], t = edge[2];
            ds.merge(u, v);
            if (ds.size() < k) {
                return t;
            }
        }

        return 0;
    }
};
