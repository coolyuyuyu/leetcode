class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int finalState = (1 << n) - 1;

        queue<pair<int, int>> q; // <node, state>
        vector<vector<int>> visited(n, vector<int>(1 << n, false));
        for (int node = 0; node < n; ++node) {
            q.emplace(node, 1 << node);
            visited[node][1 << node] = true;
        }
        for (int steps = 0;; !q.empty(); ++steps) {
            for (int len = q.size(); 0 < len--;) {
                auto [cur, state] = q.front();
                q.pop();

                if (state == finalState) {
                    return steps;
                }

                for (int nxt : graph[cur]) {
                    int nxtState = state | (1 << next);
                    if (visited[nxt][nxtState]) { continue; }

                    q.emplace(nxt, nxtState);
                    visited[nxt][nxtState] = true;
                }
            }
        }

        return -1;
    }
};
