class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = 1 << n;
        int finalState = m - 1;

        bool visited[n][m]; // [node][state]
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                visited[i][j] = false;
            }
        }

        queue<pair<int, int>> q; // [node][state]
        for (int i = 0; i < n; ++i) {
            int state = 1 << i;
            q.emplace(i, state);
            visited[i][state] = true;
        }

        for (int steps = 0; !q.empty(); ++steps) {
            for (int len = q.size(); 0 < len--;) {
                auto [cur, state] = q.front();
                q.pop();

                if (state == finalState) {
                    return steps;
                }

                for (int nxt : graph[cur]) {
                    int nextState = state | (1 << nxt);
                    if (visited[nxt][nextState]) { continue; }
                    visited[nxt][nextState] = true;
                    q.emplace(nxt, nextState);
                }
            }
        }

        return -1;
    }
};
