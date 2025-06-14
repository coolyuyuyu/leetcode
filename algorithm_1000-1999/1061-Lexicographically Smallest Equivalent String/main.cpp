class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 < root2) {
            m_parents[root2] = root1;
        }
        else if (root1 > root2){
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSets ds(26);
        for (int i = 0, n = s1.size(); i < n; ++i) {
            ds.merge(s1[i] - 'a', s2[i] - 'a');
        }

        string ret(baseStr.size(), '\0');
        for (int i = 0, n = baseStr.size(); i < n; ++i) {
            ret[i] = 'a' + ds.root(baseStr[i] - 'a');
        }

        return ret;
    }
};
