class DisjointSets {
public:
    DisjointSets(size_t n)
        : m_roots(n) {
        std::iota(m_roots.begin(), m_roots.end(), 0);
    }

    void connect(int elem1, int elem2) {
        int root1 = root(elem1);
        int root2 = root(elem2);
        if (root1 != root2) {
            m_roots[root1] = root2;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

private:
    int root(int elem) const {
        if (m_roots[elem] != elem) {
            m_roots[elem] = root(m_roots[elem]);
        }
        return m_roots[elem];
    }

    mutable vector<int> m_roots;
};

class Solution {
public:
    bool dfs_color(int n, const vector<vector<int>>& dislikes) {
        vector<vector<int>> neighbors(n);
        for (const auto& edge : dislikes) {
            neighbors[edge[0] - 1].push_back(edge[1] - 1);
            neighbors[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> colors(n, -1); // -1: no color

        stack<int> stk;
        for (int src = 0; src < n; ++src) {
            if (0 <= colors[src]) { // colored
                continue;
            }

            stk.push(src);
            while (!stk.empty()) {
                int node = stk.top();
                stk.pop();

                for (int neighbor : neighbors[node]) {
                    if (0 <= colors[neighbor]) { // colored
                        if (colors[neighbor] == colors[node]) {
                            return false;
                        }
                        else {
                            continue;
                        }
                    }

                    colors[neighbor] = (colors[node] == 0 ? 1 : 0);
                    stk.push(neighbor);
                }
            }
        }

        return true;
    }

    bool bfs_color(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> neighbors(n);
        for (const auto& edge : dislikes) {
            neighbors[edge[0] - 1].push_back(edge[1] - 1);
            neighbors[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> colors(n, -1); // -1: no color

        queue<int> q;
        for (int src = 0; src < n; ++src) {
            if (0 <= colors[src]) { // colored
                continue;
            }

            q.push(src);
            for (int c = 0; !q.empty(); c = (c == 0 ? 1 : 0)) {
                for (int i = 0, n = q.size(); i < n; ++i) {
                    int node = q.front();
                    q.pop();

                    if (0 <= colors[node]) { // colored
                        if (colors[node] == c) { // colored expected
                            continue;
                        }
                        else {
                            return false;
                        }
                    }
                    colors[node] = c;

                    for (int neighbor : neighbors[node]) {
                        q.push(neighbor);
                    }
                }
            }
        }

        return true;
    }

    bool union_find(int n, const vector<vector<int>>& dislikes) {
        vector<vector<int>> neighbors(n);
        for (const auto& edge : dislikes) {
            neighbors[edge[0] - 1].push_back(edge[1] - 1);
            neighbors[edge[1] - 1].push_back(edge[0] - 1);
        }

        DisjointSets ds(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < neighbors[i].size(); ++j) {
                if (ds.connected(i, neighbors[i][j])) {
                    return false;
                }

                ds.connect(neighbors[i][0], neighbors[i][j]);
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //return dfs_color(n, dislikes);
        //return bfs_color(n, dislikes);
        return union_find(n, dislikes);
    }
};
