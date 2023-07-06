class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        vector<int> balances(12, 0);
        for (const auto& transaction : transactions) {
            balances[transaction[0]] -= transaction[2];
            balances[transaction[1]] += transaction[2];
        }

        // retain non-zero
        {
            vector<int> tmp;
            for (int b : balances) {
                if (b != 0) {
                    tmp.push_back(b);
                }
            }
            balances.swap(tmp);
        }

        int n = balances.size();
        vector<int> sum(1 << n, 0);
        for (int state = 0; state < (1 << n); ++state) {
            for (int i = 0; i < n; ++i) {
                if ((state >> i) & 1) {
                    sum[state] += balances[i];
                }
            }
        }

        vector<int> dp(1 << n);
        dp[0] = 0;
        for (int state = 1; state < (1 << n); ++state) {
            if (sum[state] != 0) {
                dp[state] = INT_MAX;
                continue;
            }

            dp[state] = __builtin_popcount(state) - 1;
            for (int subset = state; 0 < subset; subset = (subset - 1) & state) {
                if (subset == state) {
                    continue;
                }

                if (sum[subset] == 0) {
                    dp[state] = std::min(dp[state], dp[subset] + dp[state - subset]);
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};
