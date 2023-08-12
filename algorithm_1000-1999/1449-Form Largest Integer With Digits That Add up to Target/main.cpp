class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        // dp[i]: the maximum integer which the total cost is equal to i
        vector<string> dp(target + 1);
        for (int i = 1; i <= target; ++i) {
            dp[i] = "0";
        }
        for (int i = 1; i <= target; ++i) {
            for (int d = 1; d <= 9; ++d) {
                if (i < cost[d - 1]) { continue; }
                if (dp[i - cost[d - 1]]== "0") { continue; }
                string tmp = dp[i - cost[d - 1]] + std::to_string(d);
                if (dp[i].size() < tmp.size() || (dp[i].size() == tmp.size() && dp[i] < tmp)) {
                    dp[i] = tmp;
                }
            }
        }

        return dp[target];
    }
};
