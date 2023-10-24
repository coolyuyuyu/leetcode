class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size() / 2;
        int m = n * 2;

        int GCD[m][m];
        for (int i = 0; i < m; ++i) { // 2 1-bit
            for (int j = i + 1; j < m; ++j) {
                GCD[i][j] = std::gcd(nums[i], nums[j]);
            }
        }

        // state: binary representation whether nums[i] is considered
        // dp[state]: the maximum score of state
        int dp[1 << (n * 2)];
        dp[0] = 0; // zero 1-bit
        for (int i = 0; i < m; ++i) { // 2 1-bit
            for (int j = i + 1; j < m; ++j) {
                int state = (1 << i) | (1 << j);
                dp[state] = GCD[i][j];
            }
        }

        for (int i = 2; i <= n; ++i) {
            int k = 2 * i;
            // Gosper's hack: Iterate all the m-bit state where there are k 1-bits.
            for (int state = (1 << k) - 1; state < (1 << m);) {
                dp[state] = 0;

                // iterate all subset, exclude 0
                for (int subset = state; subset > 0; subset = (subset - 1) & state) {
                    if (__builtin_popcount(subset) != (i - 1) * 2) { continue; }
                    if (state & subset != subset) { continue; }

                    int diff = state - subset;
                    int idx1 = -1, idx2 = -1;
                    for (int i = 0; i < m; ++i) {
                        if ((diff >> i) & 1) {
                            if (idx1 == -1) {
                                idx1 = i;
                            }
                            else if (idx2 == -1) {
                                idx2 = i;
                                break;
                            }
                        }
                    }
                    dp[state] = std::max(dp[state], dp[subset] + i * GCD[idx1][idx2]);
                }

                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }

        return dp[(1 << m) - 1];
    }
};
