class Solution {
public:
    // TLE
    int recursion(const vector<int>& cost) {
        // f(i): minimum cost to reach the i step on a staircase
        std::function<int(int)> f = [&](int i) {
            if (i <= 1) {
                return 0;
            }

            return std::min(f(i - 2) + cost[i - 2], f(i - 1) + cost[i - 1]);
        };

        return f(cost.size());
    }

    int recursion_memo(const vector<int>& cost) {
        vector<int> cache(cost.size() + 1, -1);

        // f(i): minimum cost to reach the i step on a staircase
        std::function<int(int)> f = [&](int i) {
            int& ret = cache[i];
            if (0 <= ret) {
                return ret;
            }

            if (i <= 1) {
                return ret = 0;
            }

            return ret = std::min(f(i - 2) + cost[i - 2], f(i - 1) + cost[i - 1]);
        };

        return f(cost.size());
    }

    // Space: O(N)
    int dp_BtmUp_v1(const vector<int>& cost) {
        int n = cost.size();

        // dp[i]: minimum cost to reach the i step on a staircase
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            dp[i] = std::min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }

        return dp[n];
    }

    // Space: O(1)
    int dp_BtmUp_v2(const vector<int>& cost) {
        int n = cost.size();

        int cur = 0, pre = 0;
        for (int i = 2; i <= n; ++i) {
            int tmp = std::min(pre + cost[i - 2], cur + cost[i - 1]);
            pre = cur;
            cur = tmp;
        }

        return cur;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        //return recursion(cost);
        //return recursion_memo(cost);
        //return dp_BtmUp_v1(cost);
        return dp_BtmUp_v2(cost);
    }
};
