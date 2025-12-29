class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        int root = 0;

        vector<int> nexts[n];
        for (const auto& conn : hierarchy) {
            int u = conn[0] - 1, v = conn[1] - 1;
            nexts[u].push_back(v);
        }

        int dp[n][2][2][budget + 1]; // cur, curBuy, preBuy, budget
        std::fill(&dp[0][0][0][0], &dp[0][0][0][0] + sizeof(dp) / sizeof(dp[0][0][0][0]), INT_MIN);

        vector<bool> visited(n * 4, false);
        std::function<void(int, bool, bool)> dfs = [&](int cur, bool curBuy, bool preBuy) {
            if (visited[(cur << 2) | (curBuy << 1) | preBuy]) {
                return;
            }
            visited[(cur << 2) | (curBuy << 1) | preBuy] = true;

            int cost, gain;
            if (curBuy) {
                cost = preBuy ? (present[cur] / 2) : present[cur];
                gain = cost <= budget ? (future[cur] - cost) : INT_MIN;
            }
            else {
                cost = 0;
                gain = 0;
            }
            if (cost <= budget) {
                dp[cur][curBuy][preBuy][cost] = gain;
            }

            for (int nxt : nexts[cur]) {
                dfs(nxt, true, curBuy);
                dfs(nxt, false, curBuy);

                int tmp[budget + 1];
                std::copy(&dp[cur][curBuy][preBuy][0], &dp[cur][curBuy][preBuy][0] + budget + 1, tmp);
                std::fill(&(dp[cur][curBuy][preBuy][0]), &dp[cur][curBuy][preBuy][0] + budget + 1, INT_MIN);
                for (int cost1 = 0; cost1 <= budget; ++cost1) {
                    if (tmp[cost1] == INT_MIN) { continue; }
                    for (int cost2 = 0; cost1 + cost2 <= budget; ++cost2) {
                        int best = max(dp[nxt][false][curBuy][cost2], dp[nxt][true][curBuy][cost2]);
                        if (best != INT_MIN) {
                            dp[cur][curBuy][preBuy][cost1 + cost2] = std::max(dp[cur][curBuy][preBuy][cost1 + cost2], tmp[cost1] + best);
                        }
                    }
                }
            }
        };
        dfs(root, false, false);
        dfs(root, true, false);

        int ret = INT_MIN;
        for (int cost = 0; cost <= budget; ++cost) {
            ret = std::max({ret, dp[root][false][false][cost], dp[root][true][false][cost]});
        }

        return ret;
    }
};
