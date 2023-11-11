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
        int n = m_graph.size();

        bool visited[n];
        std::fill(visited, visited + n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        pq.emplace(0, src);
        while (!pq.empty()) {
            auto [dist, cur] = pq.top();
            pq.pop();

            if (visited[cur]) { continue; }
            visited[cur] = true;

            if (cur == dst) {
                return dist;
            }

            for (const auto& [nxt, cost] : m_graph[cur]) {
                if (visited[nxt]) { continue; }
                pq.emplace(dist + cost, nxt);
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
        : m_dists(n, vector<int>(n, INT_MAX / 3)) {
        for (int i = 0; i < n; ++i) {
            m_dists[i][i] = 0;
        }
        for (const auto& edge : edges) {
            m_dists[edge[0]][edge[1]] = edge[2];
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    m_dists[i][j] = std::min(m_dists[i][j], m_dists[i][k] + m_dists[k][j]);
                }
            }
        }
    }

    void addEdge(const vector<int>& edge) {
        if (m_dists[edge[0]][edge[1]] <= edge[2]) {
            return;
        }

        int n = m_dists.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                m_dists[i][j] = std::min(m_dists[i][j], m_dists[i][edge[0]] + edge[2] + m_dists[edge[1]][j]);
            }
        }
    }

    int shortestPath(int src, int dst) {
        return (m_dists[src][dst] < INT_MAX / 3 ? m_dists[src][dst] : -1);
    }

private:
    vector<vector<int>> m_dists;
};

class Graph {
public:
    Graph(int n, const vector<vector<int>>& edges)
        : m_strategy(new Dijkastra(n, edges)) {
        //: m_strategy(new Floyd(n, edges)) {
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
