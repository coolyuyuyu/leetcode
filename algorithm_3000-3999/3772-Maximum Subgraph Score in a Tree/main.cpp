class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<int> graph[n];
        for (const auto& edge :edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // dp[v]: the score of subtree rooted at v
        vector<int> dp(n, 0);
        std::function<void(int, int)> dfs1 = [&](int cur, int pre) {
            dp[cur] = (good[cur] == 1 ? 1 : -1);
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }
                dfs1(nxt, cur);
                dp[cur] = std::max(dp[cur], dp[cur] + dp[nxt]);
            }
        };
        dfs1(0, -1);

        vector<int> ret(n, 0);
        std::function<void(int, int)> dfs2 = [&](int cur, int pre) {
            int preScore = (pre == -1 ? 0 : ret[pre]);
            int& curScore = ret[cur];
            curScore = dp[cur] + std::max(0, preScore - std::max(0, dp[cur]));
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }
                dfs2(nxt, cur);
            }
        };
        dfs2(0, -1);

        return ret;
    }
};
