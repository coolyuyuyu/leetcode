class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        int finalState = (1 << n) - 1;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            visited[i][1 << i] = true;
            q.emplace(i, 1 << i);
        }
        for (int step = 0; !q.empty(); ++step) {
            for (int len = q.size(); 0 < len--;) {
                auto [cur, state] = q.front();
                q.pop();

                if (state == finalState) {
                    return step;
                }

                for (int nxt : graph[cur]) {
                    int nxtState = state | (1 << nxt);
                    if (visited[nxt][nxtState]) {
                        continue;
                    }

                    visited[nxt][nxtState] = true;
                    q.emplace(nxt, nxtState);
                }
            }
        }

        return -1;
    }
};
