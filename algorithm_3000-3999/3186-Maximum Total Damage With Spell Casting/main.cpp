class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> num2cnt;
        for (int p : power) {
            ++num2cnt[p];
        }

        int n = num2cnt.size();
        pair<int, int> spells[n];
        int i = 0;
        for (const auto& [num, cnt] : num2cnt) {
            spells[i++] = {num, cnt};
        }

        // dp[i]: the maximum possible total damage from spells[0:i]
        long long dp[n];
        for (int i = 0; i < n; ++i) {
            const auto& [num, cnt] = spells[i];

            dp[i] = 1L * num * cnt;
            if (i >= 1) {
                dp[i] = std::max(dp[i], dp[i - 1]);
            }

            if (i >= 1 && num - spells[i - 1].first > 2) {
                dp[i] = std::max(dp[i], dp[i - 1] + 1L * num * cnt);
            }
            else if (i >= 2 && num - spells[i - 2].first > 2) {
                dp[i] = std::max(dp[i], dp[i - 2] + 1L * num * cnt);
            }
            else if (i >= 3) {
                dp[i] = std::max(dp[i], dp[i - 3] + 1L * num * cnt);
            }
        }

        return dp[n - 1];
    }
};
