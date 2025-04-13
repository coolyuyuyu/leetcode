class Solution {
public:
    bool dpFillout(vector<int>& nums) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        if (total & 1) { return false; }
        int half = total / 2;

        int n = nums.size();
        nums.insert(nums.begin(), 0);

        // dp[i][s]: is it possible to find a subset from nums[1:i] and whose sum equals to s
        bool dp[n + 1][half + 1];
        dp[0][0] = true;
        for (int s = 1; s <= half; ++s) {
            dp[0][s] = false;
        }
        for (int i = 1; i <= n; ++i) {
            for (int s = 0; s <= half; ++s) {
                dp[i][s] = dp[i - 1][s] || (s >= nums[i] && dp[i - 1][s - nums[i]]);
            }
        }

        return dp[n][half];
    }

    bool dpRefresh(vector<int>& nums) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        if (total & 1) { return false; }
        int half = total / 2;

        int n = nums.size();
        nums.insert(nums.begin(), 0);

        // dp[i][s]: is it possible to find a subset from nums[1:i] and whose sum equals to s
        bool dp[n + 1][half + 1];
        for (int i = 0; i <= n; ++i) {
            for (int s = 0; s <= half; ++s) {
                dp[i][s] = false;
            }
        }
        dp[0][0] = true;
        for (int i = 0; i < n; ++i) {
            for (int s = 0; s <= half; ++s) {
                if (dp[i][s]) {
                    dp[i + 1][s] = true;
                    if (s + nums[i] <= half) {
                        dp[i + 1][s + nums[i]] = true;
                    }
                }
            }
        }

        return dp[n][half];
    }

    bool canPartition(vector<int>& nums) {
        //return dpFillout(nums);
        return dpRefresh(nums);
    }
};
