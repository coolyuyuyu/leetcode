class Solution {
public:
    long long dp1(const vector<vector<int>>& questions) {
        int n = questions.size();

        // dp[i][0]: max points from questions[0:i] and do solve questions[i]
        // dp[i][1]: max points from questions[0:i] and do not solve questions[i]
        vector<vector<long long>> dp(n, vector<long long>(2));
        dp[0] = {0, questions[0][0]};

        vector<pair<int, int>> endTimes(n);
        for (int i = 0; i < n; ++i) {
            endTimes[i] = {i + questions[i][1], i};
        }
        std::sort(endTimes.begin(), endTimes.end());

        int p = 0;
        long long rollingMax = 0;
        for (int i = 1; i < n; ++i) {
            while (p < n && endTimes[p].first < i) {
                rollingMax = std::max(rollingMax, dp[endTimes[p].second][1]);
                ++p;
            }

            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = rollingMax + questions[i][0];
        }

        return std::max(dp[n - 1][0], dp[n - 1][1]);
    }

    long long dp2(const vector<vector<int>>& questions) {
        int n = questions.size();

        // dp[i][0]: max points from questions[0:i] and do solve questions[i]
        // dp[i][1]: max points from questions[0:i] and do not solve questions[i]
        vector<vector<long long>> dp(n, vector<long long>(2));
        dp[0] = {0, questions[0][0]};

        vector<long long> diffs(n, 0);
        long long diff = 0;
        for (int i = 0; i < n; ++i) {
            diff = std::max(diff, diffs[i]);
            dp[i][1] = diff + questions[i][0];

            if ((i + 1) < n) {
                dp[i + 1][0] = std::max(dp[i][0], dp[i][1]);
            }

            int j = i + questions[i][1] + 1;
            if (j < n) {
                diffs[j] = std::max(diffs[j], dp[i][1]);
            }
        }

        return std::max(dp[n - 1][0], dp[n - 1][1]);
    }

    long long dp3(const vector<vector<int>>& questions) {
        int n = questions.size();

        // dp[i]: max points from questions[i:n-1]
        vector<long long> dp(n);

        for (int i = n; 0 < i--;) {
            long long solveN = (i + 1) < n ? dp[i + 1] : 0;
            long long solveY = ((i + questions[i][1] + 1) < n ? dp[i + questions[i][1] + 1] : 0) + questions[i][0];
            dp[i] = std::max(solveN, solveY);
        }

        return dp[0];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        //return dp1(questions);
        //return dp2(questions);
        return dp3(questions);
    }
};

// dp1: 填表法
//     dp[i][0]: max points from questions[0:i] and do solve questions[i]
//     dp[i][1]: max points from questions[0:i] and do not solve questions[i]

//     dp[i][0] = max(dp[i-1][0], dp[i-1][1])
//     dp[i][1] = max(dp[j][1] + questions[i][0], ...), where for each j, j + questions[j][1] < i 

// dp2: 刷表法
//     dp[i][0]: max points from questions[0:i] and do solve questions[i]
//     dp[i][1]: max points from questions[0:i] and do not solve questions[i]

//     dp[i+1][0] = max(dp[i][0], dp[i][1])
//     dp[j][1] = max(dp[i][1] + questions[j][0], ...), where for each j, i + questions[i][1] < j

// dp3:
//     dp[i]: max points from questions[i:n-1]

//     do solve questions[i], dp[i] = dp[i + question[i][1] + 1] + questions[i][0];
//     do not solve questions[i], dp[i] = dp[i + 1]
