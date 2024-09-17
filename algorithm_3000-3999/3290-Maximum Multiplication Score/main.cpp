class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        a.insert(a.begin(), 0);
        b.insert(b.begin(), 0);
        long long dp[n + 1][5]; // dp[i][j]: the maximum score from choosing j numbers from a[0:i] and b[0:j], and both a[j] and b[j] is chosen
        long long max1 = LLONG_MIN / 2; // max1[i] = std::max(dp[1][1], dp[2][1], ..., dp[i][1])
        long long max2 = LLONG_MIN / 2; // max1[i] = std::max(dp[1][2], dp[2][2], ..., dp[i][2])
        long long max3 = LLONG_MIN / 2; // max1[i] = std::max(dp[1][3], dp[2][3], ..., dp[i][3])
        long long ret = LLONG_MIN;
        for (int i = 1; i <= n; ++i) {
            dp[i][1] = 1LL * a[1] * b[i];

            // dp[i][2] = std::max(dp[1][1], dp[2][1], ..., dp[i-1][1]) + a[2] * b[i]
            dp[i][2] = max1 + 1LL * a[2] * b[i];

            // dp[i][3] = std::max(dp[1][2], dp[2][2], ..., dp[i-1][2]) + a[3] * b[i]
            dp[i][3] = max2 + 1LL * a[3] * b[i];

            // dp[i][4] = std::max(dp[1][3], dp[2][3], ..., dp[i-1][3]) + a[4] * b[i]
            dp[i][4] = max3 + 1LL * a[4] * b[i];

            ret = std::max(ret, dp[i][4]);

            max1 = std::max(max1, dp[i][1]);
            max2 = std::max(max2, dp[i][2]);
            max3 = std::max(max3, dp[i][3]);
        }

        return ret;
    }
};
