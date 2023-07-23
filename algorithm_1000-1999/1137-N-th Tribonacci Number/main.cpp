class Solution {
public:
    // Time: O(n), Space: O(n)
    int dp1(int n) {
        if (n == 0) {
            return 0;
        }
        else if (n < 3) {
            return 1;
        }

        // dp[i]: the number of distinct ways to climb to i
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        return dp[n];
    }

    // Time: O(n), Space: O(1)
    int dp2(int n) {
        if (n == 0) {
            return 0;
        }
        else if (n < 3) {
            return 1;
        }

        // [..., x, y, z]
        int x = 0, y = 1, z = 1;
        for (int i = 3; i <= n; ++i) {
            int tmp = x + y + z;
            x = y;
            y = z;
            z = tmp;
        }

        return z;
    }

    int tribonacci(int n) {
        //return dp1(n);
        return dp2(n);
    }
};
