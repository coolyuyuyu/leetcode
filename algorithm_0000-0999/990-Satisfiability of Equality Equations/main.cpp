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
        unordered_map<char, int> var2id;
        for (const auto& equation : equations) {
            char var1 = equation[0], var2 = equation[3];
            var2id.emplace(var1, var2id.size());
            var2id.emplace(var2, var2id.size());
        }

        DisjointSets ds(var2id.size());
        for (const auto& equation : equations) {
            if (equation[1] == '=') {
                int id1 = var2id[equation[0]], id2 = var2id[equation[3]];
                ds.merge(id1, id2);
            }
        }

        for (const auto& equation : equations) {
            if (equation[1] == '!') {
                int id1 = var2id[equation[0]], id2 = var2id[equation[3]];
                if (ds.connected(id1, id2)) {
                    return false;
                }
            }
        }

        return true;
    }
};
