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
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size(), m = properties.empty() ? 0 : properties[0].size();
        vector<set<int>> sets(n);
        for (int i = 0; i < n; ++i) {
            sets[i].insert(properties[i].begin(), properties[i].end());
        }

        DisjointSets ds(n);
        vector<int> intersect(m);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cntDistinct = std::distance(intersect.begin(), std::set_intersection(sets[i].begin(), sets[i].end(), sets[j].begin(), sets[j].end(), intersect.begin()));
                if (cntDistinct >= k) {
                    ds.merge(i, j);
                }
            }
        }

        return ds.size();
    }
};
