class Solution {
public:
    int M = 1e9 + 7;

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int depth = 0;
        for (queue<pair<int, int>> q({{0, -1}}); !q.empty(); ++depth) {
            for (int i = q.size(); 0 < i--;) {
                auto [cur, pre] = q.front();
                q.pop();

                for (int nxt : graph[cur]) {
                    if (nxt == pre) { continue; }
                    q.emplace(nxt, cur);
                }
            }
        }

        int ret = 1;
        for (int d = depth - 2, base = 2; d; d >>= 1) {
            if (d & 1) {
                ret = 1LL * ret * base % M;
            }
            base = 1LL * base * base % M;
        }

        return ret;

    }
};
