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
    bool equationsPossible(vector<string>& equations) {
        DisjointSets ds(26);
        for (const auto& equation : equations) {
            if (equation[1] == '=') {
                ds.merge(equation[0] - 'a', equation[3] - 'a');
            }
        }

        for (const auto& equation : equations) {
            if (equation[1] == '!') {
                if (ds.connected(equation[0] - 'a', equation[3] - 'a')) {
                    return false;
                }
            }
        }

        return true;
    }
};
