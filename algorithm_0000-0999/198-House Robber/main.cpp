class Solution {
public:
    int rob1(const vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        else if (nums.size() == 1) {
            return nums.front();
        }
        else if (nums.size() == 2){
            return max(nums[0], nums[1]);
        }

        size_t n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (size_t i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[n - 1];
    }

    int rob2(const vector<int>& nums) {
        int curMax = 0;
        int preMax = 0;
        for (int num : nums) {
            int tmp = curMax;
            curMax = max(curMax, preMax + num);
            preMax = tmp;
        }

        return curMax;
    }

    int rob(vector<int>& nums) {
        //return rob1(nums);

        return rob2(nums);
    }
};