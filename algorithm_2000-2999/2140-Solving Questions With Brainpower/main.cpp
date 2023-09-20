class Solution {
public:
    // Time: O(n^2)
    long long dp1_TLE(vector<vector<int>>& questions) {
        // forward dp 填表法

        int n = questions.size();
        questions.insert(questions.begin(), {0, 0});

        // dp[i][0]: the maximum points from questions[1:i] and skip questions[i]
        // dp[i][1]: the maximum points from questions[1:i] and solve questions[i]
        long long dp[n + 1][2];
        dp[0][0] = 0, dp[0][1] = questions[0][0];

        // dp[i][0] = max{dp[i - 1][0], dp[i - 1][1]}
        // dp[i][1] = max{dp[j][1] + questions[i][0], ...}, where for each j, j + questions[j][1] < i

        for (int i = 1; i <= n; ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);

            dp[i][1] = 0;
            for (int j = 0; j < i; ++j) {
                if (j + questions[j][1] < i) {
                    dp[i][1] = std::max(dp[i][1], dp[j][1] + questions[i][0]);
                }
            }
        }

        return std::max(dp[n][0], dp[n][1]);
    }

    // Time: O(nlogn)
    long long dp1(vector<vector<int>>& questions) {
        // forward dp 填表法

        int n = questions.size();
        questions.insert(questions.begin(), {0, 0});

        // dp[i][0]: the maximum points from questions[1:i] and skip questions[i]
        // dp[i][1]: the maximum points from questions[1:i] and solve questions[i]
        long long dp[n + 1][2];
        dp[0][0] = 0, dp[0][1] = questions[0][0];

        // dp[i][0] = max{dp[i - 1][0], dp[i - 1][1]}
        // dp[i][1] = max{dp[j][1] + questions[i][0], ...}, where for each j, j + questions[j][1] < i

        pair<int, int> endTime[n + 1];
        for (int i = 0; i <= n; ++i) {
            endTime[i] = {i + questions[i][1], i};
        }
        std::sort(endTime, endTime + n + 1);

        long long preMaxDP1 = 0;
        for (int i = 1, j = 0; i <= n; ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);

            for (; j <= n && endTime[j].first < i; ++j) {
                preMaxDP1 = std::max(preMaxDP1, dp[endTime[j].second][1]);
            }
            dp[i][1] = preMaxDP1 + questions[i][0];
        }

        return std::max(dp[n][0], dp[n][1]);
    }

    // Time: O(n^2)
    long long dp2_TLE(vector<vector<int>>& questions) {
        // forward dp 刷表法

        int n = questions.size();
        questions.insert(questions.begin(), {0, 0});

        // dp[i][0]: the maximum points from questions[1:i] and skip questions[i]
        // dp[i][1]: the maximum points from questions[1:i] and solve questions[i]
        long long dp[n + 1][2];
        dp[0][0] = 0, dp[0][1] = questions[0][0];
        for (int i = 1; i <= n; ++i) {
            dp[i][1] = INT_MIN;
        }

        // dp[i + 1][0] = max{dp[i][0], dp[i][1]}
        // dp[j][1] = max{dp[j][1], dp[i][1] + questions[j][0]}, where for each j, i + questions[i][1] < j

        for (int i = 0; i <= n; ++i) {
            if (i + 1 <= n) {
                dp[i + 1][0] = std::max(dp[i][0], dp[i][1]);
            }

            for (int j = i + questions[i][1] + 1; j <= n; ++j) {
                dp[j][1] = std::max(dp[j][1], dp[i][1] + questions[j][0]);
            }
        }

        return std::max(dp[n][0], dp[n][1]);
    }

    // Time: O(nlogn)
    long long dp2(vector<vector<int>>& questions) {
        // forward dp 刷表法

        int n = questions.size();
        questions.insert(questions.begin(), {0, 0});

        // dp[i][0]: the maximum points from questions[1:i] and skip questions[i]
        // dp[i][1]: the maximum points from questions[1:i] and solve questions[i]
        long long dp[n + 1][2];
        dp[0][0] = 0, dp[0][1] = questions[0][0];

        // dp[i + 1][0] = max{dp[i][0], dp[i][1]}
        // dp[j][1] = max{dp[j][1], dp[i][1] + questions[j][0]}, where for each j, i + questions[i][1] < j

        long long base[n + 1];
        for (int i = 0; i <= n; ++i) {
            base[i] = 0;
        }
        long long diff = 0;

        for (int i = 0; i <= n; ++i) {
            diff = std::max(diff, base[i]);
            dp[i][1] = diff + questions[i][0];

            if (i + 1 <= n) {
                dp[i + 1][0] = std::max(dp[i][0], dp[i][1]);
            }

            int j = i + questions[i][1] + 1;
            if (j <= n) {
                base[j] = std::max(base[j], dp[i][1]);
            }
        }

        return std::max(dp[n][0], dp[n][1]);
    }

    // Time: O(n)
    long long dp3(vector<vector<int>>& questions) {
        // backward dp 填表法

        int n = questions.size();

        // dp[i]: the maximum points from questions[i:]
        long long dp[n + 1];
        dp[n] = 0;

        for (int i = n; 0 < i--;) {
            int j = i + questions[i][1] + 1;
            dp[i] = std::max(dp[i + 1], (j < n ? dp[j] : 0) + questions[i][0]);
        }

        return dp[0];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        //return dp1_TLE(questions);
        //return dp1(questions);
        //return dp2_TLE(questions);
        //return dp2(questions);
        return dp3(questions);
    }
};
