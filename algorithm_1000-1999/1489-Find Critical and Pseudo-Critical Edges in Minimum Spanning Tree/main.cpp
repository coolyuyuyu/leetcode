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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);
        }
        std::sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2) { return e1[2] < e2[2]; });
        edges.insert(edges.begin(), vector<int>());

        auto kruskal = [](int n, auto eFirst, auto eLast, int skip = -1) {
            DisjointSets ds(n);
            int cost = 0;
            for (auto itr = eFirst; itr != eLast; ++itr) {
                const vector<int>& edge = *itr;
                if (edge[3] == skip) {
                    continue;
                }
                if (ds.connected(edge[0], edge[1])) {
                    continue;
                }

                ds.merge(edge[0], edge[1]);
                cost += edge[2];

            }

            return ds.size() == 1 ? cost : INT_MAX;
        };

        vector<int> ret1; // critical
        vector<int> ret2; // pseudo-critical

        int costMST = kruskal(n, edges.begin() + 1, edges.end());
        for (int i = 1; i <= m; ++i) {
            if (kruskal(n, edges.begin() + 1, edges.end(), edges[i][3]) > costMST) {
                ret1.push_back(edges[i][3]);
            }
            else {
                edges[0] = edges[i];
                if (kruskal(n, edges.begin(), edges.end(), -1) == costMST) {
                    ret2.push_back(edges[i][3]);
                }
            }
        }

        return {ret1, ret2};
    }
};
