class Solution {
public:
    int climbStairs1(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }

        return dp[n];
    }

    int climbStairs2(int n) {
        int f1 = 1, f2 = 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = f2;
            f2 = f1 + f2;
            f1 = tmp;
        }

        return f2;
    }

    int climbStairs(int n) {
        //return climbStairs1(n);

        return climbStairs2(n);
    }
};