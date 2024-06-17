class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> num2cnt;
        for (int p : power) {
            ++num2cnt[p];
        }
        int n = num2cnt.size();
        pair<int, int> arr[n];
        int i = 0;
        for (const auto& [num, cnt] : num2cnt) {
            arr[i++] = {num, cnt};
        }

        if (n == 1) {
            return 1LL * arr[0].first * arr[0].second;
        }

        // dp[i][0]: the maximum possible total damage from num2cnt[0:i] and num2cnt[i] is NOT taken
        // dp[i][1]: the maximum possible total damage from num2cnt[0:i] and num2cnt[i] is taken
        long long dp[n][2];

        dp[0][0] = 0, dp[0][1] = arr[0].first * arr[0].second;

        dp[1][0] = std::max(dp[0][0], dp[0][1]);
        if (arr[0].first + 2 >= arr[1].first) {
            dp[1][1] = dp[0][0] + arr[1].first * arr[1].second;;
        }
        else {
            dp[1][1] = std::max(dp[0][0], dp[0][1]) + arr[1].first * arr[1].second;
        }

        for (int i = 2; i < n; ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);

            const auto& [aNum, _1] = arr[i - 2];
            const auto& [bNum, _2] = arr[i - 1];
            const auto& [cNum, cCnt] = arr[i];
            if (aNum + 2 >= cNum) {
                dp[i][1] = dp[i - 2][0] + cNum * cCnt;
            }
            else if (bNum + 2 >= cNum) {
                dp[i][1] = dp[i - 1][0] + cNum * cCnt;
            }
            else {
                dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1]) + cNum * cCnt;
            }
        }

        return std::max(dp[n - 1][0], dp[n - 1][1]);
    }
};
