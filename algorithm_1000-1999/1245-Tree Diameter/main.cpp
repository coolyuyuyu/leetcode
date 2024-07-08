class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        // Assume the longest path of the graph is in between node a and b.
        // Start from any node s, the farest node against s must be a or b.

        int n = edges.size() + 1;
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        std::function<pair<int, int>(int)> bfs = [&](int src) {
            bool visited[n];
            std::fill(visited, visited + n, false);

            queue<int> q;
            visited[src] = true;
            q.push(src);

            int leaf = src, depth = -1;
            for (; !q.empty(); ++depth) {
                leaf = q.front();
                for (int k = q.size(); 0 < k--;) {
                    int cur = q.front();
                    q.pop();
                    for (int nxt : graph[cur]) {
                        if (visited[nxt]) { continue; }

                        visited[nxt] = true;
                        q.push(nxt);
                    }
                }
            }

            return pair<int, int>{leaf, depth};
        };

        auto [s, maxDistfromS] = bfs(0);
        auto [t, maxDistfromT] = bfs(s);

        return maxDistfromT;
    }
};