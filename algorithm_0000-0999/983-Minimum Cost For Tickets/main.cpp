class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> s(days.begin(), days.end());

        int n = days.back();
        // dp[i] the minimum number of dollars you need travel to day i
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            if (s.find(i) == s.end()) {
                dp[i] = dp[i - 1];
            }
            else {
                dp[i] = std::min({
                    dp[std::max(i - 1, 0)] + costs[0],
                    dp[std::max(i - 7, 0)] + costs[1],
                    dp[std::max(i - 30, 0)] + costs[2]});
            }
        }

        return dp[n];
    }
};
