class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n)
        , m_size(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSets ds(n);
        for (int i = 0; i < n;) {
            int j;
            for (j = i + 1; j < n; ++j) {
                if (nums[j] - nums[j - 1] <= maxDiff) {
                    ds.merge(j - 1, j);
                }
            }
            i = j;
        }

        int m = queries.size();
        vector<bool> ret(m);
        for (int i = 0; i < m; ++i) {
            int u = queries[i][0], v = queries[i][1];
            ret[i] = ds.connected(u, v);
        }

        return ret;
    }
};
