class Solution {
public:
    // Time: O(n^2), Space: O(n)
    int dp(const vector<int>& nums) {
        int n = nums.size();

        // dp[i]: the minimum number of jumps to reach nums[i]
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < std::min((i + nums[i] + 1), n); ++j) {
                dp[j] = std::min(dp[j], dp[i] + 1);
            }
        }

        return dp[n - 1];
    }

    // Time: O(n), Space: O(1)
    int greedy(const vector<int>& nums) {
        int n = nums.size();

        int ret = 0;
        for (int end = 0, far = 0, i = 0; (i + 1) < n; ++i) {
            far = std::max(far, i + nums[i]);
            if (end <= i) {
                ++ret;
                end = far;
            }
        }

        return ret;
    }

    // Time: O(n), Space: O(1)
    int slide_window(const vector<int>& nums) {
        int n = nums.size();

        int ret = 0;
        for (int lft = 0, rht = 0; (rht + 1) < n;) {
            ++ret;

            int far = 0;
            for (int cur = lft; cur <= rht; ++cur) {
                far = std::max(far, cur + nums[cur]);
            }
            lft = rht + 1, rht = far;
        }

        return ret;
    }

    int jump(vector<int>& nums) {
        //return dp(nums);
        //return greedy(nums);
        return slide_window(nums);
    }
};
