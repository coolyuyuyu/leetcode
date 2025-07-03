class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        numWays.insert(numWays.begin(), 0);

        int dp[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = 0;
        }

        vector<int> ret;
        for (int c = 1; c <= n; ++c) {
            if (dp[c] + 1 == numWays[c]) {
                ret.push_back(c);
                for (int i = c; i <= n; ++i) {
                    dp[i] += dp[i - c];
                }
            }
            else if (dp[c] != numWays[c]) {
                return {};
            }
        }

        return ret;
    }
};
