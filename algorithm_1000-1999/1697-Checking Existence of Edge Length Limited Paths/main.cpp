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
        std::sort(edgeList.begin(), edgeList.end(), [](const auto& edge1, const auto& edge2){ return edge1[2] < edge2[2]; });

        int queryCnt = queries.size();
        int queryIndexes[queryCnt];
        std::iota(queryIndexes, queryIndexes + queryCnt, 0);
        std::sort(queryIndexes, queryIndexes + queryCnt, [&](int idx1, int idx2){ return queries[idx1][2] < queries[idx2][2]; });

        vector<bool> ret(queryCnt);

        DisjointSets ds(n);
        for (int i = 0, j = 0; i < queryCnt; ++i) {
            int queryIndex = queryIndexes[i];
            const auto& query = queries[queryIndex];
            int p = query[0], q = query[1], limit = query[2];
            for (; j < edgeList.size() && edgeList[j][2] < limit; ++j) {
                int u = edgeList[j][0], v = edgeList[j][1];
                ds.merge(u, v);
            }

            ret[queryIndex] = ds.connected(p, q);
        }

        return ret;
    }
};
