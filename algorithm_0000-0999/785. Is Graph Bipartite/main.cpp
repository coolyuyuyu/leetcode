class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    DisjointSets(const DisjointSets& ds)
        : m_parents(ds.m_parents) {
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
    bool bfs(const vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> colors(n, 0); // 0: no color, 1: color1, 2: color2
        for (int i = 0; i < n; ++i) {
            if (colors[i] != 0) {
                continue;
            }

            colors[i] = 1;
            for (queue<int> q({i}); !q.empty();) {
                int v = q.front();
                q.pop();

                for (int neighbor : graph[v]) {
                    if (colors[neighbor] == 0) {
                        colors[neighbor] = (colors[v] == 1 ? 2 : 1);
                        q.push(neighbor);
                    }
                    else if (colors[neighbor] == colors[v]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool union_find(const vector<vector<int>>& graph) {
        int n = graph.size();

        DisjointSets ds(n);
        for (int i = 0; i < n; ++i) {
            if (graph[i].empty()) {
                continue;
            }
            
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
        return union_find(graph);
    }
};
