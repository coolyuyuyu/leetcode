class DisjointSets {
public:
    DisjointSets(size_t n)
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

    size_t size() const {
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
    size_t m_size;
};

class Solution {
public:
    bool checkSimilar(const string& s, const string& t) {
        int cntDiff = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != t[i] && 2 < ++cntDiff) {
                return false;
            }
        }

        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        DisjointSets ds(strs.size());
        for (int i = 0; (i + 1) < strs.size(); ++i) {
            for (int j = i + 1; j < strs.size(); ++j) {
                if (checkSimilar(strs[i], strs[j])) {
                    ds.merge(i, j);
                }
            }
        }

        return ds.size();
    }
};
