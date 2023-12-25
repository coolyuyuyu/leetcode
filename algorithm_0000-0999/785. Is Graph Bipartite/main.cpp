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
    bool bfs(vector<vector<int>>& graph) {
        int n = graph.size();

        // -1: not colored, 0: color 0, 1: color 1
        int colors[n];
        std::fill(colors, colors + n, -1);
        for (int i = 0; i < n; ++i) {
            if (colors[i] != -1) { // not colored
                continue;
            }

            colors[i] = 0;
            for (queue<int> q({i}); !q.empty();) {
                int cur = q.front();
                q.pop();
                for (int nxt : graph[cur]) {
                    if (colors[nxt] == -1) {
                        colors[nxt] = 1 - colors[cur];
                        q.push(nxt);
                    }
                    else if (colors[nxt] == colors[cur]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool dsu(vector<vector<int>>& graph) {
        int n = graph.size();

        DisjointSets ds(n);
        for (int i = 0; i < n; ++i) {
            if (graph[i].empty()) { continue; }

            int k = graph[i][0];
            for (int j : graph[i]) {
                if (ds.connected(i, j)) {
                    return false;
                }
                ds.merge(k, j);
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //return bfs(graph);
        return dsu(graph);
    }
};
