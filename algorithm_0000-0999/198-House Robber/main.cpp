class Solution {
public:
    // Time: O(n), Space: O(n) 
    int dp1(vector<int>::iterator first, vector<int>::iterator last) {
        int n = std::distance(first, last);
        if (n == 0) {
            return 0;
        }

        vector<int> dpRobY(n); // dpRobY[i]: the maximum amount of money rub from houses[0:i] when house[i] is rob
        vector<int> dpRobN(n); // dpRobN[i]: the maximum amount of money rub from houses[0:i] when house[i] is NOT rob
        dpRobY[0] = *first; dpRobN[0] = 0;

        int i = 1;
        for (auto itr = first + 1; itr != last; ++itr, ++i) {
            dpRobY[i] = dpRobN[i - 1] + *itr;
            dpRobN[i] = std::max(dpRobY[i - 1], dpRobN[i - 1]);
        }

        return std::max(dpRobY[n - 1], dpRobN[n - 1]);
    }

    // Time: O(n), Space: O(1) 
    int dp2(vector<int>::iterator first, vector<int>::iterator last) {
        int n = std::distance(first, last);
        if (n == 0) {
            return 0;
        }

        int robY = *first;
        int robN = 0;

        int i = 1;
        for (auto itr = first + 1; itr != last; ++itr, ++i) {
            int tmpY = robY, tmpN = robN;
            robY = tmpN + *itr;
            robN = std::max(tmpY, tmpN);
        }

        return std::max(robY, robN);
    }

    // Time: O(n^2), Space: O(n^2) 
    int dp3(vector<int>::iterator first, vector<int>::iterator last) {
        int n = std::distance(first, last);

        vector<vector<int>> dp(n, vector<int>(n)); // dp[i][j]: the maximum amount of money rub from houses[i:ij]
        for (int i = 0; i < n; ++i) {
            dp[i][i] = *(first + i);
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; (i + len - 1) < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = std::max(*(first + i) + ((i + 2) <= j ? dp[i + 2][j] : 0), dp[i + 1][j]);
            }
        }

        return dp[0][n - 1];
    }

    // Time: O(n), Space: O(1) 
    int greedy(vector<int>::iterator first, vector<int>::iterator last) {
        int pre = 0, cur = 0;
        for (auto itr = first; itr != last; ++itr) {
            int tmp = cur;
            cur = std::max(pre + *itr, cur);
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
