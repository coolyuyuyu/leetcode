class Strategy {
public:
    virtual void addEdge(const vector<int>& edge) = 0;
    virtual int shortestPath(int node1, int node2) = 0;
};

class Dijkastra : public Strategy {
public:
    Dijkastra(int n, const vector<vector<int>>& edges)
        : m_graph(n) {
        for (const auto& edge : edges) {
            m_graph[edge[0]].emplace(edge[1], edge[2]);
        }
    }

    void addEdge(const vector<int>& edge) {
        m_graph[edge[0]].emplace(edge[1], edge[2]);
    }

    int shortestPath(int src, int dst) {
        vector<bool> visited(m_graph.size(), false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> pq;
        pq.emplace(0, src);
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            if (visited[node]) {
                continue;
            }
            visited[node] = true;

            if (node == dst) {
                return dist;
            }

            for (auto [next, cost] : m_graph[node]) {
                if (visited[next]) {
                    continue;
                }

                pq.emplace(dist + cost, next);
            }
        }

        return -1;
    }

private:
    vector<unordered_map<int, int>> m_graph;
};

class Floyd : public Strategy {
public:
    Floyd(int n, const vector<vector<int>>& edges)
        : m_dp(n, vector<int>(n, INT_MAX / 3)) {
        for (int i = 0; i < n; ++i) {
            m_dp[i][i] = 0;
        }
        for (const auto& edge : edges) {
            m_dp[edge[0]][edge[1]] = edge[2];
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    m_dp[i][j] = std::min(m_dp[i][j], m_dp[i][k] + m_dp[k][j]);
                }
            }
        }
    }

    void addEdge(const vector<int>& edge) {
        int n = m_dp.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                m_dp[i][j] = std::min(m_dp[i][j], m_dp[i][edge[0]] + edge[2] + m_dp[edge[1]][j]);
            }
        }
    }

    int shortestPath(int src, int dst) {
        return ((INT_MAX / 3) <= m_dp[src][dst] ? -1 : m_dp[src][dst]);
    }

private:
    vector<vector<int>> m_dp;
};

class Graph {
public:
    Graph(int n, const vector<vector<int>>& edges)
        //: m_strategy(new Dijkastra(n, edges)) {
        : m_strategy(new Floyd(n, edges)) {
    }

    void addEdge(const vector<int>& edge) {
        m_strategy->addEdge(edge);
    }

    int shortestPath(int node1, int node2) {
        return m_strategy->shortestPath(node1, node2);
    }

private:
    Strategy* m_strategy;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
