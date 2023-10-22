class Solution {
public:
    string topdnDFS(vector<int>& stoneValue) {
        int n = stoneValue.size();

        int presum[n];
        std::partial_sum(stoneValue.begin(), stoneValue.end(), presum);
        std::function<int(int)> sufsum = [&](int i) {
            if (i >= n) {
                return 0;
            }
            return presum[n - 1] - (0 < i ? presum[i - 1] : 0);
        };

        // dp[i]: the maximum score the player can take from stoneValue[i:]
        int dp[n];
        std::fill(dp, dp + n, INT_MIN);
        std::function<int(int)> f = [&](int i) {
            if (n <= i) {
                return 0;
            }

            int& ret = dp[i];
            if (ret != INT_MIN) {
                return ret;
            }

            for (int j = 1; j <= 3 && i + j - 1 < n; ++j) {
                //ret = std::max(ret, sum(i, i + j - 1) + sum(i + j, n) - f(i + j));
                ret = std::max(ret, sufsum(i) - f(i + j));
            }
            return ret;
        };

        int score = f(0);
        int other = sufsum(0) - score;
        if (score > other) {
            return "Alice";
        }
        else if (score == other) {
            return "Tie";
        }
        else {
            return "Bob";
        }
    }

    string btmupDP(vector<int>& stoneValue) {
        int n = stoneValue.size();

        int presum[n];
        std::partial_sum(stoneValue.begin(), stoneValue.end(), presum);
        std::function<int(int)> sufsum = [&](int i) {
            if (i >= n) {
                return 0;
            }
            return presum[n - 1] - (0 < i ? presum[i - 1] : 0);
        };

        int dp[n];
        for (int i = n; 0 < i--;) {
            dp[i] = INT_MIN;
            for (int j = 1; j <= 3 && i + j - 1 < n; ++j) {
                //dp[i] = std::max(dp[i], sum(i, i + j - 1) + sum(i + j, n) - dp[i + j]);
                dp[i] = std::max(dp[i], sufsum(i) - (i + j < n ? dp[i + j] : 0));
            }
        }

        int score = dp[0];
        int other = sufsum(0) - score;
        if (score > other) {
            return "Alice";
        }
        else if (score == other) {
            return "Tie";
        }
        else {
            return "Bob";
        }
    }

    string stoneGameIII(vector<int>& stoneValue) {
        //return topdnDFS(stoneValue);
        return btmupDP(stoneValue);
    }
};
