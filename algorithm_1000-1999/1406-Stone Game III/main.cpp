class Solution {
public:
    string topdn(const vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> suf(n + 1);
        suf[n] = 0;
        std::partial_sum(stoneValue.rbegin(), stoneValue.rend(), suf.rbegin() + 1);

        vector<int> cache(n, INT_MIN);
        std::function<int(int)> solve = [&](int i) {
            if (stoneValue.size() <= i) {
                return 0;
            }

            int& ret = cache[i];
            if (ret != INT_MIN) {
                return ret;
            }

            int sum = 0;
            for (int j = 1; j <= 3 && (i + j - 1) < n; ++j) {
                sum += stoneValue[i + j - 1];
                ret = std::max(ret, sum + suf[i + j] - solve(i + j));
            }

            return ret;
        };

        int score = solve(0);
        if (score < (suf[0] - score)) {
            return "Bob";
        }
        else if (score == (suf[0] - score)) {
            return "Tie";
        }
        else {
            return "Alice";
        }
    }

    string btmup(const vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> suf(n + 1);
        suf[n] = 0;
        std::partial_sum(stoneValue.rbegin(), stoneValue.rend(), suf.rbegin() + 1);

        vector<int> dp(n + 1, INT_MIN); // dp[i]: the maximum score the player can gain from stones[i:]
        dp[n] = 0;
        for (int i = n; 0 < i--;) {
            int sum = 0;
            for (int j = 1; j <= 3; ++j) {
                if (n <= i + j - 1) {
                    break;
                }
                sum += stoneValue[i + j - 1];
                dp[i] = std::max(dp[i], sum + suf[i + j] - dp[i + j]);
            }
        }

        if (dp[0] < (suf[0] - dp[0])) {
            return "Bob";
        }
        else if (dp[0] == (suf[0] - dp[0])) {
            return "Tie";
        }
        else {
            return "Alice";
        }
    }

    string stoneGameIII(vector<int>& stoneValue) {
        //return topdn(stoneValue);
        return btmup(stoneValue);
    }
};
