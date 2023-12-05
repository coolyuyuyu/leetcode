class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        tuple<int, int, int> job[n + 1];
        job[0] = {0, 0, 0};
        for (int i = 0; i < n; ++i) {
            job[i + 1] = {startTime[i], endTime[i], profit[i]};
        }
        std::sort(job + 1, job + n + 1, [&](const auto& j1, const auto& j2){ return std::get<1>(j1) < std::get<1>(j2); });

        // dp[i]: the maximum profit you can take from job[1:i]
        int dp[n + 1];
        dp[0] = std::get<2>(job[0]);
        for (int i = 1; i <= n; ++i) {
            auto itr = std::upper_bound(
                job,
                job + i,
                tuple<int, int, int>{0, std::get<0>(job[i]), 0},
                [&](const auto& j1, const auto& j2){ return std::get<1>(j1) < std::get<1>(j2); });
            int j = std::distance(job, itr) - 1;
            dp[i] = std::max(dp[i - 1], dp[j] + std::get<2>(job[i]));
        }

        return dp[n];
    }
};
