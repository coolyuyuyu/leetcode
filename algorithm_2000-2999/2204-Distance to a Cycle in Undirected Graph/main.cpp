class Solution {
public:

    vector<int> detectCycles(int n, vector<int> graph[]) {
        vector<int> degrees(n, 0);
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                ++degrees[v];
            }
        }

        queue<int> q;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) {
                visited[i] = true;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (visited[v]) { continue; }
                if (--degrees[v] == 1) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        vector<int> cycles;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                cycles.push_back(i);
            }
        }

        return cycles;
    }

    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        vector<int> cycles = detectCycles(n, graph);

        vector<int> ret(n);

        queue<int> q;
        vector<bool> visited(n, false);
        for (int cycle : cycles) {
            visited[cycle] = true;
            q.push(cycle);
        }

        for (int dist = 0; !q.empty(); ++dist) {
            for (int i = q.size(); 0 < i--;) {
                int u = q.front();
                q.pop();

                ret[u] = dist;

                for (int v : graph[u]) {
                    if (visited[v]) { continue; }
                    visited[v] = true;
                    q.push(v);
                }
            }
            
        }

        return ret;
    }
};
