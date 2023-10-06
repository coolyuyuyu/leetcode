class Solution {
public:
    // Time: (n^2)
    int dynamicProgramming(int n) {
        if (n == 2) {
            return 1;
        }
        else if (n == 3) {
            return 2;
        }

        int dp[n + 1];
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            dp[i] = 0;
            for (int j = 2; j <= i / 2; ++j) {
                dp[i] = std::max(dp[i], dp[j] * dp[i - j]);
            }
        }

        return dp[n];
    }

    // Time: (1)
    int math(int n) {
        if (n == 2) {
            return 1;
        }
        else if (n == 3) {
            return 2;
        }

        if (n % 3 == 0) {
            return pow(3, n / 3);
        }
        else if (n % 3 == 1) {
            return pow(3, n / 3 - 1) * 4;
        }
        else {
            return pow(3, n / 3) * 2;
        }
    }

    int integerBreak(int n) {
        //return dynamicProgramming(n);
        return math(n);
    }
};
