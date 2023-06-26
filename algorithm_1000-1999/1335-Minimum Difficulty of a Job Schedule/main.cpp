class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }

        jobDifficulty.insert(jobDifficulty.begin(), 0);

        // dp[i][numParts]: the minimum difficulty of a job schedule such that splitting jobs[1:i] into numParts days
        vector<vector<int>> dp(n + 1, vector<int>(d + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = INT_MAX / 2;
        }

        for (int i = 1; i <= n; ++i) {
            for (int numParts = 1; numParts <= std::min(i, d); ++numParts) {
                int maxDifficult = INT_MIN;
                dp[i][numParts] = INT_MAX / 2;
                for (int j = i; numParts <= j; j--) {
                    maxDifficult = std::max(maxDifficult, jobDifficulty[j]);
                    dp[i][numParts] = std::min(dp[i][numParts], dp[j - 1][numParts - 1] + maxDifficult);
                }
            }
        }
        
        return dp[n][d];
    }
};
