class Solution {
public:
    int topDn_DP(int n, int lastRow) {
        if (n == 0) {
            return 1;
        }
        else if (n == 1) {
            return 0;
        }

        int cnt = 0;
        for (int i = 2; i <= n && i < lastRow; i += 3) {
            cnt += topDn_DP(n - i, i);
        }

        return cnt;
    }

    int topDn_DP_memo_helper(int n, int lastRow, vector<vector<int>>& cache) {
        if (n == 0) {
            return 1;
        }
        else if (n == 1) {
            return 0;
        }

        if (cache[n][lastRow] != -1) {
            return cache[n][lastRow];
        }

        int cnt = 0;
        for (int i = 2; i <= n && i < lastRow; i += 3) {
            cnt += topDn_DP_memo_helper(n - i, i, cache);
        }
        cache[n][lastRow] = cnt;

        return cache[n][lastRow];
    }

    int topDn_DP_memo(int n) {
        vector<vector<int>> cache(n + 1, vector<int>(n + 2, -1));
        return topDn_DP_memo_helper(n, n + 1, cache);
    }

    int btmUp_Dp(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (size_t i = 2; i <= n; i += 3) {
            for(size_t j = n + 1; i < j--;) {
                dp[j] += dp[j - i];
            }
        }

        return dp[n];
    }

    int houseOfCards(int n) {
        //return topDn_DP(n, n + 1);
        //return topDn_DP_memo(n);

        return btmUp_Dp(n);
    }
};