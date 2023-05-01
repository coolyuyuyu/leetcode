class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n)
        , m_size(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    DisjointSets(const DisjointSets& ds)
        : m_parents(ds.m_parents)
        , m_size(ds.m_size) {
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> edges1, edges2, edges3;
        for (const auto& edge : edges) {
            switch (edge[0]) {
            case 1:
                edges1.emplace_back(edge[1] - 1, edge[2] - 1);
                break;
            case 2:
                edges2.emplace_back(edge[1] - 1, edge[2] - 1);
                break;
            case 3:
                edges3.emplace_back(edge[1] - 1, edge[2] - 1);
                break;
            default:
                break;
            }
        }

        DisjointSets ds(n);

        int cnt3 = 0;
        for (int i = 0; i < edges3.size() && 1 < ds.size(); ++i) {
            auto [v1, v2] = edges3[i];
            if (!ds.connected(v1, v2)) {
                ds.merge(v1, v2);
                ++cnt3;
            }
        }

        int cnt1 = 0;
        DisjointSets ds1(ds);
        for (int i = 0; i < edges1.size() && 1 < ds1.size(); ++i) {
            auto [v1, v2] = edges1[i];
            if (!ds1.connected(v1, v2)) {
                ds1.merge(v1, v2);
                ++cnt1;
            }
        }
        if (1 < ds1.size()) {
            return -1;
        }

        int cnt2 = 0;
        DisjointSets ds2(ds);
        for (int i = 0; i < edges2.size() && 1 < ds2.size(); ++i) {
            auto [v1, v2] = edges2[i];
            if (!ds2.connected(v1, v2)) {
                ds2.merge(v1, v2);
                ++cnt2;
            }
        }
        if (1 < ds2.size()) {
            return -1;
        }

        return edges.size() - cnt1 - cnt2 - cnt3;
    }
};
