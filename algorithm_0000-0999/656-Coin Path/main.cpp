class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        int n = coins.size();

        vector<int> dp(n, INT_MAX / 2);
        vector<vector<int>> paths(n);
        dp[0] = coins[0];
        paths[0] = {1};
        for (int i = 1; i < n; ++i) {
            if (coins[i] == -1) { continue; }
            for (int j = std::max(i - maxJump, 0); j < i; ++j) {
                if (dp[j] + coins[i] < dp[i]) {
                    dp[i] = dp[j] + coins[i];
                    paths[i] = paths[j];
                    paths[i].push_back(i + 1);
                }
                else if (dp[j] + coins[i] == dp[i]) {
                    vector<int> tmp(paths[j]);
                    tmp.push_back(i + 1);
                    if (tmp < paths[i]) {
                        paths[i] = tmp;
                    }
                }
            }
        }

        return paths[n - 1];
    }
};
