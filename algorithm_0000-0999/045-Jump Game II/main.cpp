class Solution {
public:
    // TLE
    int jumpV1(const vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }

        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            int num = dp[i];
            for (size_t j = 1; j <= nums[i] && i + j < nums.size(); ++j) {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }

        return dp.back();
    }

    int jumpV2(const vector<int>& nums) {
        int curEnd = 0, curFarest = 0, count = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            curFarest = max(curFarest, i + nums[i]);
            if (curEnd <= i) {
                ++count;
                curEnd = curFarest;
            }
        }

        return count;
    }

    int jump(vector<int>& nums) {
        assert(!nums.empty());

        //return jumpV1(nums);

        return jumpV2(nums);
    }
};