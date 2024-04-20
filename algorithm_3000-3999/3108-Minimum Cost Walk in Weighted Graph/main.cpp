class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

private:
    mutable vector<int> m_parents;
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSets ds(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            ds.merge(u, v);
        }

        unordered_map<int, int> costs;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            int root = ds.root(u);
            if (costs.find(root) == costs.end()) {
                costs[root] = w;
            }
            else {
                costs[root] &= w;
            }
        }

        vector<int> ret(query.size());
        for (int i = 0; i < query.size(); ++i) {
            int s = query[i][0], t = query[i][1];
            if (s == t) {
                ret[i] = 0;
            }
            else if (ds.connected(s, t)) {
                ret[i] = costs[ds.root(s)];
            }
            else {
                ret[i] = -1;
            }
        }

        return ret;
    }
};
