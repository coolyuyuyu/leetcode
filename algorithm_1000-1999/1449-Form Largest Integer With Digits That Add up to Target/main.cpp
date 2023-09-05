class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        cost.insert(cost.begin(), -1);

        // dp[i]: the maximum integer you can paint where the cost is i
        vector<string> dp(target + 1);
        dp[0] = "";
        for (int i = 1; i <= target; ++i) {
            dp[i] = "0";
        }
        for (int i = 1; i <= target; ++i) {
            for (int j = 1; j <= 9; ++j) {
                if (i < cost[j]) { continue; }
                if (dp[i - cost[j]] == "0") { continue; }
                string tmp = dp[i - cost[j]] + std::to_string(j);
                if (dp[i].size() < tmp.size() || (dp[i].size() == tmp.size() && dp[i] < tmp)) {
                    dp[i] = tmp;
                }
            }
        }

        return dp[target];
    }
};
