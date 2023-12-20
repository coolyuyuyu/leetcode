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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        std::function<bool(int, int)> checkSimilar = [&](int i, int j) {
            for (int idx = 0, len = strs[0].size(), cnt = 0; idx < len; ++idx) {
                if (strs[i][idx] != strs[j][idx]) {
                    if (++cnt > 2) {
                        return false;
                    }
                }
            }

            return true;
        };

        DisjointSets ds(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (checkSimilar(i, j)) {
                    ds.merge(i, j);
                }
            }
        }

        return ds.size();
    }
};
