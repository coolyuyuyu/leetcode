class Solution {
public:
    // Time: O(n), Space: O(n)
    int dp1(vector<int>::iterator first, vector<int>::iterator last) {
        int n = std::distance(first, last);

        // dp[i][0]: the maximum amount of money rob from house[0:i] and house[i] is NOT robbed
        // dp[i][1]: the maximum amount of money rob from house[0:i] and house[i] is robbed.
        int dp[n][2];
        dp[0][0] = 0; dp[0][1] = *first++;
        for(int i = 1; i < n; ++i, ++first) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + *first;
        }

        return std::max(dp[n - 1][0], dp[n - 1][1]);
    }

    // Time: O(n), Space: O(1)
    int dp2(vector<int>::iterator first, vector<int>::iterator last) {
        int n = std::distance(first, last);

        // dpN: the maximum amount of money rob from house[0:i] and house[i] is NOT robbed
        // dpY: the maximum amount of money rob from house[0:i] and house[i] is robbed.
        int dpN = 0, dpY = INT_MIN;
        for (int i = 0; i < n; ++i, ++first) {
            int tmpN = dpN, tmpY = dpY;
            dpN = std::max(tmpN, tmpY);
            dpY = tmpN + *first;
        }

        return std::max(dpN, dpY);
    }

    // Time: O(n^2), Space: O(n^2)
    int dp3(vector<int>::iterator first, vector<int>::iterator last) {
        int n = std::distance(first, last);

        // dp[i][j]: the maximum amount of money rob from house[i:j]
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            dp[i][i] = *(first + i);
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = len - 1; j < n; ++i, ++j) {
                dp[i][j] = std::max(*(first + i) + (i + 2 <= j ? dp[i + 2][j] : 0), dp[i + 1][j]);
            }
        }

        return dp[0][n - 1];
    }

    // Time: O(n), Space: O(1)
    int greedy(vector<int>::iterator first, vector<int>::iterator last) {
        int pre = 0, cur = 0;
        for (; first != last; ++first) {
            int tmp = cur;
            cur = std::max(cur, pre + *first);
            pre = tmp;
        }

        return std::max(pre, cur);
    }

    int rob(vector<int>& nums) {
        //return dp1(nums.begin(), nums.end());
        //return dp2(nums.begin(), nums.end());
        //return dp3(nums.begin(), nums.end());
        return greedy(nums.begin(), nums.end());
    }
};
