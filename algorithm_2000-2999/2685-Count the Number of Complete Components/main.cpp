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

    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

private:
    mutable vector<int> m_parents;
    vector<int> m_cardinality;
    int m_size;
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSets ds(n);
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            ds.merge(a, b);
        }

        unordered_map<int, int> root2edgeCnts;
        for (int i = 0; i < n; ++i) {
            if (ds.cardinality(i) == 1) {
                root2edgeCnts[i] = 0;
            }
        }
        for (const auto& edge : edges) {
            int a = edge[0];
            ++root2edgeCnts[ds.root(a)];
        }

        int ret = 0;
        for (const auto& [root, edgeCnt] : root2edgeCnts) {
            int nodeCnt = ds.cardinality(root);
            if (nodeCnt * (nodeCnt - 1) / 2 == edgeCnt) {
                ++ret;
            }
        }

        return ret;
    }
};
