class DisjointSets {
public:
    DisjointSets(int n)
        : m_roots(n) {
        std::iota(m_roots.begin(), m_roots.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_roots[root1] = root2;
        }
    }

    int root(int elem) const {
        if (m_roots[elem] != elem) {
            m_roots[elem] = root(m_roots[elem]);
        }
        return m_roots[elem];
    }

private:
    mutable vector<int> m_roots;
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSets ds(n);
        for (const auto& edge : edges) {
            ds.merge(edge[0], edge[1]);
        }

        unordered_map<int, int> cnts;
        for (int i = 0; i < n; ++i) {
            ++cnts[ds.root(i)];
        }

        long long presum = 0;
        long long ret = 0;
        for (auto [root, cnt] : cnts) {
            ret += (cnt * presum);
            presum += cnt;
        }

        return ret;
    }
};
