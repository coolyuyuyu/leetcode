class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n)
        , m_size(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    bool merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
            --m_size;
            return true;
        }
        return false;
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

    int size() const {
        return m_size;
    }

    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

private:
    mutable vector<int> m_parents;
    int m_size;
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DisjointSets ds(n + 1);
        vector<bool> visited(n + 1);
        for (int i = threshold + 1; i <= n; ++i) {
            if (visited[i]) { continue; }
            visited[i] = true;
            for (int z = i * 2; z <= n; z += i) {
                visited[z] = true;
                ds.merge(z, i);
            }
        }

        vector<bool> ret(queries.size());
        for (int i = 0; i < ret.size(); ++i) {
            int a = queries[i][0], b = queries[i][1];
            ret[i] = ds.connected(a, b);
        }

        return ret;
    }
};
