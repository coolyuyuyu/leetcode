class Solution {
public:
    int topdn_recursive(int n) {
        vector<int> cache(n + 1, 0);
        cache[0] = 1;
        std::function<int(int)> f = [&](int n) {
            int& ret = cache[n];
            if (0 < ret) {
                return ret;
            }

            for (int lft = 0; lft < n; ++lft) {
                int rht = n - lft - 1;
                ret += f(lft) * f(rht);
            }

            return ret;
        };

        return f(n);
    }

    int btmup_dp(int n){
        // dp[i]: the number of structurally unique BST's which has exactly n nodes
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int lft = 0; lft < i; ++lft) {
                int rht = i - lft - 1;
                dp[i] += dp[lft] * dp[rht];
            }
        }

        return dp[n];
    }

    int numTrees(int n) {
        //return topdn_recursive(n);
        return btmup_dp(n);
    }
};
