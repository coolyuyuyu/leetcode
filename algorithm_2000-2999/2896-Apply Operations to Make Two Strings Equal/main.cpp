class Solution {
public:
    // Time: O(n^3)
    int dpV1(const string& s1, const string& s2, int x) {
        vector<int> nums;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                nums.push_back(i);
            }
        }

        int n = nums.size();
        if (n == 0) { return 0; }
        if (n & 1) { return -1; }

        // everytime we visit two elements i and j, with cost x or (nums[j] - nums[i])
        // dp[i]][j]: the cost to visit all elements
        int dp[n][n];

        for (int len = 2; len <= n; len += 2) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                dp[i][j] = (2 < len ? dp[i + 1][j - 1] : 0) + std::min(x, nums[j] - nums[i]);
                for (int k = i + 1; k + 1 < j; k += 2) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }

        return dp[0][n - 1];
    }

    // Time: O(n^2)
    int dpV2(const string& s1, const string& s2, int x) {
        vector<int> nums;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                nums.push_back(i);
            }
        }

        int n = nums.size();
        if (n == 0) { return 0; }
        if (n & 1) { return -1; }

        nums.insert(nums.begin(), 0);

        // dp[i][j]: after processed the first i elements, j elements are left unmatched
        int dp[n + 1][n + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = INT_MAX / 2;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (2 <= i) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 2][j] + nums[i] - nums[i - 1]);
                }
                if (j + 1 <= i - 1) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j + 1]);
                }
                if (0 <= j - 1) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + x);
                }
            }
        }

        return dp[n][0];
    }

    // Time: O(n)
    int dpV3(const string& s1, const string& s2, int x) {
        vector<int> nums;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                nums.push_back(i);
            }
        }

        int n = nums.size();
        if (n == 0) { return 0; }
        if (n & 1) { return -1; }

        nums.insert(nums.begin(), 0);

        // dp[i][j]: after processed the first i elements, j elements are left unmatched
        int dp[n + 1][3];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i][j] = INT_MAX / 2;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= 1; ++j) {
                if (2 <= i) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 2][j] + nums[i] - nums[i - 1]);
                }
                if (j + 1 <= i - 1) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j + 1]);
                }
                if (0 <= j - 1) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + x);
                }
            }
        }

        return dp[n][0];
    }

    int minOperations(string s1, string s2, int x) {
        //return dpV1(s1, s2, x);
        //return dpV2(s1, s2, x);
        return dpV3(s1, s2, x);
    }
};
