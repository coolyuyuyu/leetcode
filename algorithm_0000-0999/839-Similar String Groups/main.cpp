class Solution {
public:
    class DisjointSets {
    public:
        DisjointSets(size_t count)
            : m_parents(count)
            , m_count(count) {
            for (size_t i = 0; i < m_parents.size(); ++i) {
                m_parents[i] = i;
            }
        }

        size_t find(size_t i) {
            if (m_parents[i] != i) {
                m_parents[i] = find(m_parents[i]);
            }

            return m_parents[i];
        }

        void merge(size_t i, size_t j) {
            size_t rootI = find(i);
            size_t rootJ = find(j);
            if (rootI != rootJ) {
                --m_count;
            }

            m_parents[rootI] = rootJ;
        }

        inline size_t size() const {
            return m_count;
        }

    private:
        vector<size_t> m_parents;
        size_t m_count;
    };

    bool checkSimilar(const string& a, const string& b) {
        size_t len = a.size();
        size_t diff = 0;
        for (size_t i = 0; i < len; ++i) {
            if (a[i] != b[i]) {
                if (2 < ++diff) {
                    return false;
                }
            }
        }

        return true;
    }

    int numSimilarGroups(vector<string>& A) {
        DisjointSets ds(A.size());
        for (size_t i = 0; i + 1 < A.size(); ++i) {
            for (size_t j = i + 1; j < A.size(); ++j) {
                if (checkSimilar(A[i], A[j])) {
                    ds.merge(i, j);
                }
            }
        }

        return ds.size();
    }
};