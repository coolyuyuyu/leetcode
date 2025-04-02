class Solution {
public:
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

    // Time: O(n^2), TLE
    long long dpFwdFillout1(vector<vector<int>>& questions) {
        int n = questions.size();

        // dp[i][0]: the maximum points from questions[0:i] and skip question[i]
        // dp[i][1]: the maximum points from questions[0:i] and solve question[i]
        long long dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = questions[0][0];

        for (int i = 1; i < n; ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = questions[i][0];
            for (int j = 0; j < i; ++j) {
                if (j + questions[j][1] < i) {
                    dp[i][1] = std::max(dp[i][1], dp[j][1] + questions[i][0]);
                }
            }
        }

        return std::max(dp[n - 1][0], dp[n - 1][1]);
    }

    // Time: O(nlogn)
    long long dpFwdFillout2(vector<vector<int>>& questions) {
        int n = questions.size();

        pair<int, int> endTimes[n];
        for (int i = 0; i < n; ++i) {
            endTimes[i] = {i + questions[i][1], i};
        }
        std::sort(endTimes, endTimes + n);

        // dp[i][0]: the maximum points from questions[0:i] and skip question[i]
        // dp[i][1]: the maximum points from questions[0:i] and solve question[i]
        long long dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = questions[0][0];

        long long rollingMx = 0;
        for (int i = 1, p = 0; i < n; ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
            for (; p < n && endTimes[p].first < i; ++p) {
                rollingMx = std::max(rollingMx, dp[endTimes[p].second][1]);
            }
            dp[i][1] = rollingMx + questions[i][0];
        }

        return std::max(dp[n - 1][0], dp[n - 1][1]);
    }

    // Time: O(n^2), TLE
    long long dpFwdRefresh1(vector<vector<int>>& questions) {
        int n = questions.size();

        // dp[i][0]: the maximum points from questions[0:i] and skip question[i]
        // dp[i][1]: the maximum points from questions[0:i] and solve question[i]
        long long dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = questions[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = 0;
            dp[i][1] = questions[i][0];
        }

        for (int i = 0; i < n; ++i) {
            if (i + 1 < n) {
                dp[i + 1][0] = std::max(dp[i][0], dp[i][1]);
            }

            for (int j = i + questions[i][1] + 1; j < n; ++j) {
                dp[j][1] = std::max(dp[j][1], dp[i][1] + questions[j][0]);
            }
        }

        return std::max(dp[n - 1][0], dp[n - 1][1]);
    }

    // Time: O(n)
    long long dpFwdRefresh2(vector<vector<int>>& questions) {
        int n = questions.size();

        // dp[i][0]: the maximum points from questions[0:i] and skip question[i]
        // dp[i][1]: the maximum points from questions[0:i] and solve question[i]
        long long dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = questions[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = 0;
            dp[i][1] = questions[i][0];
        }

        long long bases[n];
        std::fill(bases, bases + n, 0);
        long long cur = 0;

        for (int i = 0; i < n; ++i) {
            cur = std::max(cur, bases[i]);
            dp[i][1] = cur + questions[i][0];

            if (i + 1 < n) {
                dp[i + 1][0] = std::max(dp[i][0], dp[i][1]);
            }

            int j = i + questions[i][1] + 1;
            if (j < n) {
                bases[j] = std::max(bases[j], dp[i][1]);
            }
        }

        return std::max(dp[n - 1][0], dp[n - 1][1]);
    }

    // Time: O(n)
    long long dpBwdFillout(vector<vector<int>>& questions) {
        int n = questions.size();

        // dp[i]: the maximum points from questions[i:]
        long long dp[n + 1];
        dp[n] = 0;

        for (int i = n - 1; i >= 0; --i) {
            int j = i + questions[i][1] + 1;
            dp[i] = std::max(dp[i + 1], (j < n ? dp[j] : 0) + questions[i][0]);
        }

        return dp[0];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        //return dpFwdFillout1(questions);
        //return dpFwdFillout2(questions);

        //return dpFwdRefresh1(questions);
        //return dpFwdRefresh2(questions);

        return dpBwdFillout(questions);
    }
};
