class Solution {
public:
    int M = 1e9 + 7;

    int recursion(int n, int x) {
        vector<int> nums;
        for (int i = 1; true; ++i) {
            int num = 1;
            for (int j = 0; j < x; ++j) {
                num *= i;
            }
            if (n < num) {
                break;
            }
            nums.push_back(num);
        }
        std::reverse(nums.begin(), nums.end());
        int m = nums.size();

        int cache[m][n + 1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= n; ++j) {
                cache[i][j] = -1;
            }
        }

        // f(i, j): the number of ways to construct sum j from first i nums
        std::function<int(int, int)> f = [&](int i, int j) -> int {
            if (j == 0) {
                return 1;
            }
            if (m <= i) {
                return 0;
            }

            int& ret = cache[i][j];
            if (0 <= ret) {
                return ret;
            }
            ret = 0;

            ret += f(i + 1, j);
            ret %= M;
            if (nums[i] <= j) {
                ret += f(i + 1, j - nums[i]);
                ret %= M;
            }

            return ret;
        };

        return f(0, n);
    }

    // Space: O(n^2)
    int dp1(int n, int x) {
        vector<int> nums;
        for (int i = 1; true; ++i) {
            int num = 1;
            for (int j = 0; j < x; ++j) {
                num *= i;
            }
            if (n < num) {
                break;
            }
            nums.push_back(num);
        }
        int m = nums.size();

        nums.insert(nums.begin(), 0);

        // dp[i][j]: the number of ways to construct sum j from nums[1:i]
        int dp[m + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (nums[i] <= j) {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                    dp[i][j] %= M;
                }
            }
        }

        return dp[nums.size() - 1][n];
    }

    // Space: O(n)
    int dp2(int n, int x) {
        vector<int> nums;
        for (int i = 1; true; ++i) {
            int num = 1;
            for (int j = 0; j < x; ++j) {
                num *= i;
            }
            if (n < num) {
                break;
            }
            nums.push_back(num);
        }
        int m = nums.size();

        nums.insert(nums.begin(), 0);

        // dp[j]: the number of ways to construct sum j
        int dp[n + 1];
        dp[0] = 1;
        for (int j = 1; j <= n; ++j) {
            dp[j] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = n; 1 <= j; --j) {
                if (nums[i] <= j) {
                    dp[j] += dp[j - nums[i]];
                    dp[j] %= M;
                }
            }
        }

        return dp[n];
    }

    int numberOfWays(int n, int x) {
        return recursion(n, x);
        //return dp1(n, x);
        //return dp2(n, x);
    }
};
