class DisjointSets {
public:
    DisjointSets(int n) 
        : m_parents(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

private:
    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

    mutable vector<int> m_parents;
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [](const auto& edge1, const auto& edge2) { return edge1[2] < edge2[2]; });

        vector<int> indexes(queries.size());
        std::iota(indexes.begin(), indexes.end(), 0);
        std::sort(indexes.begin(), indexes.end(), [&queries](const auto& index1, const auto& index2) { return queries[index1][2] < queries[index2][2]; });

        vector<bool> ret(queries.size());
        DisjointSets ds(n);
        for (int i = 0, j = 0; i < queries.size(); ++i) {
            const auto& query = queries[indexes[i]];
            for (j < edgeList.size() && edgeList[j][2] < query[2]; ++j) {
                ds.merge(edgeList[j][0], edgeList[j][1]);
            }

            ret[indexes[i]] = ds.connected(query[0], query[1]);
        }

        return ret;
    }
};
