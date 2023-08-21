class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        unordered_multimap<int, pair<int, int>> m;
        for (const auto& offer : offers) {
            m.emplace(offer[1] + 1, make_pair(offer[0] + 1, offer[2]));
        }

        // dp[i]: the maximum amount of gold from house[1:i]
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];

            const auto p = m.equal_range(i);
            for (auto itr = p.first; itr != p.second; ++itr) {
                const auto& [start, profit] = itr->second;
                dp[i] = std::max(dp[i], dp[start - 1] + profit);
            }
        }

        return dp[n];
    }
};
