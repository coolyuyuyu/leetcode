class Solution {
public:
    // Time: O(kn^2), TLE
    int topdnDFS1(int k, int n) {
        // dp[i][j]: the minimum number of moves for i eggs and j floors
        int dp[k + 1][n + 1];
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = INT_MAX;
            }
        }
        std::function<int(int, int)> f = [&](int k, int n) {
            if (k == 1) { return n; }
            else if (n <= 1) { return n; }

            int& ret = dp[k][n];
            if (ret != INT_MAX) { return ret; }

            for (int i = 1; i < n; ++i) {
                ret = std::min(ret, 1 + std::max(f(k - 1, i - 1), f(k, n - i)));
            }

            return ret;
        };

        return f(k, n);
    }

    // Time: O(knlogn)
    int topdnDFS2(int k, int n) {
        // dp[i][j]: the minimum number of moves for i eggs and j floors
        int dp[k + 1][n + 1];
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = INT_MAX;
            }
        }
        std::function<int(int, int)> f = [&](int k, int n) {
            if (k == 1) { return n; }
            else if (n <= 1) { return n; }

            int& ret = dp[k][n];
            if (ret != INT_MAX) { return ret; }

            // for (int i = 1; i < n; ++i) {
            //     ret = std::min(ret, 1 + std::max(f(k - 1, i - 1),  f(k, n - i)));
            // }
            // => assume fa(i) = f(k - 1, i - 1), fb(i): f(k, n - i)
            // => fa is monotonically increasing, fb is monotonically decreasing
            // => binary search find first i such that fa(i) >= fb(i)
            int lo = 1, hi = n - 1;
            while (lo < hi) {
                int i = lo + (hi - lo) / 2;
                int fa = f(k - 1, i - 1), fb = f(k, n - i);
                if (fa >= fb) {
                    hi = i;
                }
                else {
                    lo = i + 1;
                }
            }
            ret = 1 + std::max(f(k - 1, lo - 1), f(k, n - lo));

            return ret;
        };

        return f(k, n);
    }

    int superEggDrop(int k, int n) {
        return topdnDFS1(k, n);
        //return topdnDFS2(k, n);
    }
};
