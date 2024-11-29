class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        vector<int> degrees(n, 0);
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            ++degrees[node1], ++degrees[node2];
        }

        vector<int> ret(n, 0);

        queue<int> q;
        for (int u = 0; u < n; ++u) {
            if (degrees[u] == 1) {
                q.push(u);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            ret[cur] = INT_MAX;

            for (int nxt : graph[cur]) {
                if (--degrees[nxt] == 1) {
                    q.push(nxt);
                }
            }
        }

        for (int u = 0; u < n; ++u) {
            if (ret[u] == 0) {
                q.push(u);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur]) {
                if (ret[nxt] < INT_MAX) { continue; }
                ret[nxt] = ret[cur] + 1;
                q.push(nxt);
            }
        }

        return ret;
    }
};
