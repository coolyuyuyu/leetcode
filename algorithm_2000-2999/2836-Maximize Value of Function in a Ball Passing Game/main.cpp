class Solution {
public:
    // Time: O(n * k)
    long long dp1(vector<int>& receiver, long long k) {
        int n = receiver.size();

        // dp[i][j]: the sum of ids from i during j passes
        long long dp[n][k + 1];
        for (int i = 0; i < n; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= k; ++j) {
            for (int i = 0; i < n; ++i) {
                dp[i][j] = dp[receiver[i]][j - 1] + i;
            }
        }

        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = std::max(ret, dp[i][k]);
        }

        return ret;
    }

    // Time: O(n * log2(k))
    long long dp2(vector<int>& receiver, long long k) {
        // binary lift

        int n = receiver.size();
        int m = ceil(log2(k));

        // pos[i][j]: the pos from i after 2^j passes
        int pos[n][m + 1];
        for (int i = 0; i < n; ++i) {
            pos[i][0] = receiver[i];
        }
        // dp[i][j]: dp[i][j]: the sum of ids from i during 2^j passes
        long long dp[n][m + 1];
        for (int i = 0; i < n; ++i) {
            dp[i][0] = receiver[i];
        }

        for (int j = 1; j <= m; ++j) {
            for (int i = 0; i < n; ++i) {
                pos[i][j] = pos[pos[i][j - 1]][j - 1];
                dp[i][j] = dp[i][j - 1] + dp[pos[i][j - 1]][j - 1];
            }
        }

        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            long long val = i;
            int cur = i;
            for (long long j = 0, pass = k; pass; pass >>= 1, j++) {
                if (pass & 1) {
                    val += dp[cur][j];
                    cur = pos[cur][j];
                }
            }
            ret = std::max(ret, val);
        }

        return ret;
    }

    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        //return dp1(receiver, k);
        return dp2(receiver, k);
    }
};
