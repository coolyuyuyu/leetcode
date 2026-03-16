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
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<tuple<int, int, int>> reqEdges, optEdges;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], s = edge[2], m = edge[3];
            if (m) {
                reqEdges.emplace_back(s, u, v);
            }
            else {
                optEdges.emplace_back(s, u, v);
            }
        }
        std::sort(reqEdges.rbegin(), reqEdges.rend());
        std::sort(optEdges.rbegin(), optEdges.rend());

        std::function<bool(int)> checkOk = [&](int stability) {
            if (!reqEdges.empty() && std::get<0>(reqEdges.back()) < stability) {
                return false;
            }

            DisjointSets ds(n);
            for (const auto& [_, u, v] : reqEdges) {
                if (ds.connected(u, v)) { return false; }
                ds.merge(u, v);
            }
            if (ds.size() == 1) {
                return true;
            }

            int cnt = 0;
            for (const auto& [s, u, v] : optEdges) {
                if (s >= stability) {
                    ds.merge(u, v);
                    if (ds.size() == 1) {
                        return true;
                    }
                }
                else if (s * 2 >= stability) {
                    if (ds.connected(u, v)) { continue; }
                    if (++cnt > k) { return false; }
                    ds.merge(u, v);
                    if (ds.size() == 1) {
                        return true;
                    }
                }
                else {
                    break;
                }
            }

            return false;
        };

        int lo = 0, hi = 1e5 * 2;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (checkOk(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return checkOk(lo) ? lo : -1;
    }
};
