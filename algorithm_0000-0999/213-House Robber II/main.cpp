class Solution {
public:
    // 198: House Robber I
    // Time: O(n), Space: O(1)
    int dp1(vector<int>::iterator first, vector<int>::iterator last) {
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

    // 198: House Robber I
    // Time: O(n^2), Space: O(n^2) 
    int dp2(vector<int>::iterator first, vector<int>::iterator last) {
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

    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        //return std::max(dp1(nums.begin() + 1, nums.end()), dp1(nums.begin(), nums.end() - 1));
        return std::max(dp2(nums.begin() + 1, nums.end()), dp2(nums.begin(), nums.end() - 1));
    }
};
