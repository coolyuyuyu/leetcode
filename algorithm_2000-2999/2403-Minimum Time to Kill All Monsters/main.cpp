class Solution {
public:
    long long minimumTime(vector<int>& power) {
        int n = power.size();
        int numStates = (1 << n);

        vector<long long> dp(numStates, LLONG_MAX);
        dp[0] = 0;
        for (int state = 1; state < dp.size(); ++state) {
            int popCnt = __builtin_popcount(state);
            for (int i = 0; i < n; ++i) {
                if (state & (1 << i)) {
                    dp[state] = std::min(dp[state], dp[state & ~(1 << i)] + (power[i] - 1) / popCnt + 1);
                }
            }
        }

        return dp[numStates - 1];
    }
};
