class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        jobDifficulty.insert(jobDifficulty.begin(), 0);

        // dp[i][k]: the minimum difficulty of a job schedule for jobDifficulty[1:i] finished in k days
        int dp[n + 1][d + 1];
        for (int i = 0; i <= n; ++i) {
            for (int k = 0; k <= std::min(d, i); ++k) {
                dp[i][k] = INT_MAX / 2;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int numParts = 1; numParts <= std::min(d, i); ++numParts) {
                int difficulty = INT_MIN;
                for (int j = i; numParts <= j; --j) {
                    difficulty = std::max(difficulty, jobDifficulty[j]);
                    dp[i][numParts] = std::min(dp[i][numParts], dp[j - 1][numParts - 1] + difficulty);
                }
            }
        }

        return dp[n][d];
    }
};
