class Solution {
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        unordered_map<int, int> g2cnt;
        for (int g : group) {
            ++g2cnt[g];
        }

        // dp[v][g]: number of node of group g from subtree rooted at v
        int dp[n][21];
        for (int v = 0; v < n; ++v) {
            std::fill(&dp[v][0], &dp[v][0] + 21, 0);
        }

        long long ret = 0;
        std::function<void(int, int)> f = [&](int cur, int pre) {
            dp[cur][group[cur]] = 1;
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }

                f(nxt, cur);
                for (const auto& [g, cnt] : g2cnt) {
                    dp[cur][g] += dp[nxt][g];
                    ret += 1LL * dp[nxt][g] * (g2cnt[g] - dp[nxt][g]);
                }

            }
        };
        f(0, -1);

        return ret;
    }
};
