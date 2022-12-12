class Solution {
public:
    // Time: O(n), Space: O(n)
    int iterative_dp1(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <=n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // Time: O(n), Space: O(1)
    int iterative_dp2(int n) {
        int x = 1, y = 1;
        for (int i = 2; i <=n; ++i) {
            int tmp = x + y;
            y = x;
            x = tmp;
        }
        return x;
    }

    int climbStairs(int n) {
        //return iterative_dp1(n);
        return iterative_dp2(n);
    }
};
