class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        vector<int> balances(12, 0);
        for (const auto& transaction : transactions) {
            balances[transaction[0]] -= transaction[2];
            balances[transaction[1]] += transaction[2];
        }
        { // remove zero amount
            vector<int> tmp;
            for (int balance : balances) {
                if (balance != 0) {
                    tmp.push_back(balance);
                }
            }
            balances.swap(tmp);
        }
        int n = balances.size();

        // state: binary representation whehter the ith person is considered
        // even[state]: whether the state is break even or not
        // dp[state]: the minimum number of transactions required to settle the debt of state
        bool even[1 << n];
        int dp[1 << n];
        for (int state = 0; state < (1 << n); ++state) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if ((state >> i) & 1) {
                    sum += balances[i];
                }
            }
            even[state] = (sum == 0);
            dp[state] = INT_MAX;
        }
        dp[0] = 0;
        for (int state = 1; state < (1 << n); ++state) {
            if (!even[state]) {
                continue;
            }

            dp[state] = __builtin_popcount(state) - 1;
            for (int subset = state; subset; subset = (subset - 1) & state) {
                if (even[subset]) {
                    dp[state] = std::min(dp[state], dp[subset] + dp[state - subset]);
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};
