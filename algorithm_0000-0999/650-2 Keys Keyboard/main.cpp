class Solution {
public:
    int byTopdnRecursive(int n) {
        if (n == 1) { return 0; }

        for (int i = 2; i <= n; ++i) {
            if (n % i == 0) {
                return byTopdnRecursive(n / i) + i;
            }
        }

        return INT_MAX;
    }

    int byBtmupDP(int n) {
        // dp[i]: the minimum number of operations to get the character 'A' exactly i times
        int dp[n + 1];
        dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= i; ++j) {
                if (i % j == 0) {
                    dp[i] = dp[i / j] + j;
                    break;
                }
            }
        }

        return dp[n];
    }

    int minSteps(int n) {
        //return byTopdnRecursive(n);
        return byBtmupDP(n);
    }
};
