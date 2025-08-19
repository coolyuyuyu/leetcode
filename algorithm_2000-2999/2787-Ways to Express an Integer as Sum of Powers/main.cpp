class Solution {
public:
    int M = 1e9 + 7;

    int quickPow(int base, int exp) {
        int ret = 1;
        for (; exp; exp >>= 1) {
            if (exp & 1) {
                ret = (1L * ret * base) % M;
            }
            base = (1L * base * base) % M;
        }
        return ret;
    };

    int topdnDP1(int n, int x) {
        vector<int> nums;
        for (int i = 1; true; ++i) {
            int num = quickPow(i, x);
            if (num > n) { break; }
            nums.push_back(num);
        }
        std::reverse(nums.begin(), nums.end());
        int m = nums.size();

        int dp[m][n + 1];
        for (int i = 0; i < m; ++i) {
            for (int s = 0; s <= n; ++s) {
                dp[i][s] = -1;
            }
        }

        // f(i, s): the number of ways s can be expressed as the sum of nums[i:m-1]
        std::function<int(int, int)> f = [&](int i, int s) {
            if (s == 0) {
                return 1;
            }
            else if (i >= m) {
                return 0;
            }

            int& ret = dp[i][s];
            if (ret >= 0) {
                return ret;
            }

            ret = f(i + 1, s);
            if (nums[i] <= s) {
                ret += f(i + 1, s - nums[i]);
                ret %= M;
            }

            return ret;
        };

        return f(0, n);
    }

    // Space: O(n^2)
    int btmupDP1(int n, int x) {
        vector<int> nums;
        for (int i = 1; true; ++i) {
            int num = quickPow(i, x);
            if (num > n) { break; }
            nums.push_back(num);
        }
        int m = nums.size();
        nums.insert(nums.begin(), 0);

        // dp[i][s]: the number of ways s can be expressed as the sum of nums[1:i]
        int dp[m + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = 1;
        }
        for (int s = 1; s <= n; ++s) {
            dp[0][s] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            for (int s = 1; s <= n; ++s) {
                dp[i][s] = dp[i - 1][s];
                if (nums[i] <= s) {
                    dp[i][s] += dp[i - 1][s - nums[i]];
                    dp[i][s] %= M;
                }
            }
        }

        return dp[m][n];
    }

    // Space: O(n)
    int btmupDP2(int n, int x) {
        vector<int> nums;
        for (int i = 1; true; ++i) {
            int num = quickPow(i, x);
            if (num > n) { break; }
            nums.push_back(num);
        }
        int m = nums.size();
        nums.insert(nums.begin(), 0);

        // dp[i][s]: the number of ways s can be expressed as the sum of nums[1:i]
        int dp[n + 1];
        dp[0] = 1;
        for (int s = 1; s <= n; ++s) {
            dp[s] = 0;
        }

        for (int i = 1; i <= m; ++i) {
            for (int s = n; s >= 1; --s) {
                if (nums[i] <= s) {
                    dp[s] += dp[s - nums[i]];
                    dp[s] %= M;
                }
            }
        }

        return dp[n];
    }

    int numberOfWays(int n, int x) {
        return topdnDP1(n, x);
        //return btmupDP1(n, x);
        //return btmupDP2(n, x);
    }
};
