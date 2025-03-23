class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        vector<pair<int, int>> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
        }
        unordered_set<int> targets(marked.begin(), marked.end());

        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [dist, cur] = pq.top();
            pq.pop();

            if (visited[cur]) { continue; }
            visited[cur] = true;

            if (targets.find(cur) != targets.end()) {
                return dist;
            }

            for (const auto& [nxt, w] : graph[cur]) {
                if (visited[nxt]) { continue; }
                pq.emplace(dist + w, nxt);
            }
        }

        return -1;
    }
};
