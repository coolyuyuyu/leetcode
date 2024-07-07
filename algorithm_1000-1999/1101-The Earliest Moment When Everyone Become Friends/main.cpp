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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        std::sort(logs.begin(), logs.end(), [](const auto& log1, const auto& log2){ return log1[0] < log2[0]; });

        DisjointSets ds(n);
        for (const auto& log : logs) {
            int timestamp = log[0], x = log[1], y = log[2];
            ds.merge(x, y);
            if (ds.size() == 1) {
                return timestamp;
            }
        }

        return -1;
    }
};
