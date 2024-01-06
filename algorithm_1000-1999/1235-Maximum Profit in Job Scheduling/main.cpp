class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        tuple<int, int, int> jobs[n + 1];
        jobs[0] = {0, 0, 0};
        for (int i = 0; i < n; ++i) {
            jobs[i + 1] = {startTime[i], endTime[i], profit[i]};
        }
        std::sort(jobs, jobs + n + 1, [](const auto& job1, const auto& job2){ return std::get<1>(job1) < std::get<1>(job2); });

        // dp[i]: the maximum profit you can take from jobs[1:i]
        int dp[n + 1];
        dp[0] = std::get<2>(jobs[0]);

        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            const auto& [startTime, _, profit] = jobs[i];
            auto itr = std::upper_bound(
                jobs, jobs + i,
                tuple<int, int, int>{0, startTime, 0},
                [](const auto& job1, const auto& job2){ return std::get<1>(job1) < std::get<1>(job2); });
            int j = std::distance(jobs, std::prev(itr));
            dp[i] = std::max(dp[i - 1], dp[j] + profit);
        }

        return dp[n];
    }
};
