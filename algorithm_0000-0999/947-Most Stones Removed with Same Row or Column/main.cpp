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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        unordered_map<int, vector<int>> rowIds, colIds;
        for (int i = 0; i < n; ++i) {
            int x = stones[i][0], y = stones[i][1];
            rowIds[x].push_back(i);
            colIds[y].push_back(i);
        }

        DisjointSets ds(n);
        for (const auto& [_, ids] : rowIds) {
            for (int id : ids) {
                ds.merge(id, ids[0]);
            }
        }
        for (const auto& [_, ids] : colIds) {
            for (int id : ids) {
                ds.merge(id, ids[0]);
            }
        }

        return n - ds.size();
    }
};
