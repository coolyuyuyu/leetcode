class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        arr.insert(arr.begin(), 0);

        // dp[i]: the largest sum of arr[0:i] after partitioned into subarrys of length at most k
        int dp[n + 1];
        std::fill(dp, dp + n + 1, INT_MIN);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int rangeMax = INT_MIN;
            for (int j = i; j >= std::max(i - k + 1, 1); --j) {
                rangeMax = std::max(rangeMax, arr[j]);
                dp[i] = std::max(dp[i], dp[j - 1] + rangeMax * (i - j + 1));
            }
        }

        return dp[n];
    }
};
