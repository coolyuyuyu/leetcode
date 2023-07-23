class Solution {
public:
    // Time: O(n), Space: O(n)
    int dp1(int n) {
        // dp[i]: the number of distinct ways to climb to i
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    // Time: O(n), Space: O(1)
    int dp2(int n) {
        int cur = 1, pre = 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = cur + pre;
            pre = cur;
            cur = tmp;
        }

        return cur;
    }

    int climbStairs(int n) {
        //return dp1(n);
        return dp2(n);
    }
};
