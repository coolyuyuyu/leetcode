class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.back() + 1;

        unordered_set<int> s(days.begin(), days.end());

        vector<int> dp(n); // dp[i] the minimum number of dollars you need to travel for the first (i+1) days
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (s.find(i) == s.end()) {
                dp[i] = dp[i - 1];
            }
            else {
                dp[i] = std::min({
                    dp[std::max(0, i - 1)] + costs[0],
                    dp[std::max(0, i - 7)] + costs[1],
                    dp[std::max(0, i - 30)] + costs[2]}
                );
            }
        }

        return dp[n - 1];
    }
};
