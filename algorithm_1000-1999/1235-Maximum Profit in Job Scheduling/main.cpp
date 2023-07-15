class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<tuple<int, int, int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        jobs.insert(jobs.begin(), {-1, -1, 0});
        std::sort(jobs.begin(), jobs.end(), [&](const auto& job1, const auto& job2) { return std::get<1>(job1) < std::get<1>(job2); });

        // dp[i]: the maximum profit from first i jobs
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            auto itr = std::upper_bound(
                jobs.begin(), jobs.begin() + i,
                tuple<int, int, int>{-1, std::get<0>(jobs[i]), 0},
                [&](const auto& job1, const auto& job2) { return std::get<1>(job1) < std::get<1>(job2); });
            int x = itr - 1 - jobs.begin();
            dp[i] = std::max(dp[i - 1], dp[x] + std::get<2>(jobs[i]));
        }

        return dp[n];
    }
};
