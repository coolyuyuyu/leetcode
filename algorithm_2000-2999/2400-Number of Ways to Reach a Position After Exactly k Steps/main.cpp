class Solution {
public:
    int M = 1e9 + 7;

    int dynamic_programming(int startPos, int endPos, int k) {
        if (k < abs(endPos - startPos)) {
            return 0;
        }

        int offset = k;
        
        // dp[i][j]: the number of different ways to reach the position j at ith steps
        vector<vector<int>> dp(k + 1, vector<int>(2 * k + 1, 0));
        dp[0][0 + offset] = 1;

        
        for (int i = 1; i <= k; ++i) {
            for (int j = -k; j <= k; ++j) {
                if (-k <= (j - 1)) {
                    dp[i][j + offset] += dp[i - 1][j - 1 + offset];
                }

                if ((j + 1) <= k) {
                    dp[i][j + offset] += dp[i - 1][j + 1 + offset];
                    dp[i][j + offset] %= M;
                }
            }
        }

        return dp[k][abs(endPos - startPos) + offset];
    }

    int combinatorics(int startPos, int endPos, int k) {
        int d = abs(endPos - startPos);
        if (k < d) {
            return 0;
        }
        if ((d + k) & 1) {
            return 0;
        }

        // assume move right a steps and move left b steps to reach endPos
        // a + b = k
        // a - b = d
        // => a = (k + d) / 2
        // => combination C(k, a)

        int n = k, r = (k + d) / 2;
        vector<vector<long long>> cache(n + 1, vector<long long>(r + 1));
        std::function<long long(int, int)> combination = [&](int n, int r) {
            if (n == 0 || r == 0 || n == r) {
                return 1LL;
            }
            
            long long& ret = cache[n][r];
            if (ret != 0) {
                return ret;
            }

            ret = combination(n-1, r-1) + combination(n-1, r);
            ret = ret % M;
            return ret;
        };
        return combination(n, r);
    }

    int numberOfWays(int startPos, int endPos, int k) {
        //return dynamic_programming(startPos, endPos, k);
        return combinatorics(startPos, endPos, k);
    }
};
