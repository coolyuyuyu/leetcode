class Solution {
public:
    int M = 1e9 + 7;

    int countSubMultisets(vector<int>& nums, int l, int r) {
        vector<pair<int, int>> nonZeroCnts; int zeroCnt; {
            unordered_map<int, int> cnts;
            zeroCnt = 0;
            for (int num : nums) {
                if (num != 0) {
                    ++cnts[num];
                }
                else {
                    ++zeroCnt;
                }
            }
            nonZeroCnts.assign(cnts.begin(), cnts.end());
        }
        int n = nonZeroCnts.size();
        nonZeroCnts.insert(nonZeroCnts.begin(), {0, 0});

        std::function<int(int x)> f = [&](int x) -> int {
            if (x < 0) {
                return 0;
            }

            // dp[i][j]: the count of sub-multisets within cnts[1:i] where sum of elements is j
            int dp[n + 1][x + 1];
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= x; ++j) {
                    dp[i][j] = 0;
                }
            }
            dp[0][0] = 1;
            for (int i = 1; i <= n; ++i) {
                const auto& [num, cnt] = nonZeroCnts[i];
                for (int j = 0; j <= x; ++j) {
                    // dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num * 1] + ... dp[i - 1][j - num * cnt]
                    // => dp[i][j - num * 1] = dp[i - 1][j - cnt * 1] + dp[i - 1][j - num * 2] + ... dp[i - 1][j - num * (cnt + 1)]
                    // => dp[i][j] = dp[i][j - num * 1] + dp[i - 1][j] - dp[i - 1][j - num * (cnt + 1)]
                    dp[i][j] = 0;
                    if (0 <= j - num * 1) {
                        dp[i][j] += dp[i][j - num * 1];
                        dp[i][j] %= M;
                    }
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= M;
                    if (0 <= j - num * (cnt + 1)) {
                        dp[i][j] -= dp[i - 1][j - num * (cnt + 1)];
                        dp[i][j] = ((dp[i][j] % M) + M) % M;
                    }
                }
            }

            long long ret = 0;
            for (int j = 0; j <= x; ++j) {
                ret += dp[n][j];
                ret %= M;
            }
            ret *= (zeroCnt + 1);
            ret %= M;

            return ret;
        };

        int ret = f(r) - f(l - 1);
        ret = ((ret % M) + M) % M;
        return ret;
    }
};
