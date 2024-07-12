class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n)
        , m_size(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    bool merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
            --m_size;
            return true;
        }
        else {
            return false;
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> edges1, edges2, edges3;
        for (const auto& edge : edges) {
            int type = edge[0], u = edge[1] - 1, v = edge[2] - 1;
            switch (type) {
            case 1:
                edges1.emplace_back(u, v);
                break;
            case 2:
                edges2.emplace_back(u, v);
                break;
            case 3:
                edges3.emplace_back(u, v);
                break;
            }
        }

        DisjointSets ds(n);
        int cnt3 = 0;
        for (const auto& [u, v] : edges3) {
            if (ds.merge(u, v)) {
                ++cnt3;
            }
        }
        if (ds.size() == 1) {
            return edges.size() - (n - 1);
        }

        DisjointSets ds1(ds);
        int cnt1 = 0;
        for (const auto& [u, v] : edges1) {
            if (ds1.merge(u, v)) {
                ++cnt1;
            }
        }
        if (ds1.size() > 1) {
            return -1;
        }

        DisjointSets ds2(ds);
        int cnt2 = 0;
        for (const auto& [u, v] : edges2) {
            if (ds2.merge(u, v)) {
                ++cnt2;
            }
        }
        if (ds2.size() > 1) {
            return -1;
        }

        return edges.size() - cnt1 - cnt2 - cnt3;
    }
};
