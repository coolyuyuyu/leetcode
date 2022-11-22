class Solution {
public:
    bool canJump1(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        for (size_t i = 0; i < dp.size(); ++i) {
            if (!dp[i]) {
                continue;
            }

            for (size_t j = i + 1, end = std::min(i + nums[i] + 1, dp.size()); j < end; ++j) {
                dp[j] = true;
            }
        }

        return dp.back();
    }

    // Time: O(n)
    bool canJump2(vector<int>& nums) {
        for (size_t pos = 0, reach = 0; pos < nums.size() && pos <= reach; ++pos) {
            reach = std::max(reach, pos + nums[pos]);
            if (nums.size() <= (reach + 1)) {
                return true;
            }
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        //return canJump1(nums);
        return canJump2(nums);
    }
};
