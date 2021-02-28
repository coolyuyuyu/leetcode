class Solution {
public:
    int rob(vector<int>& nums, size_t bgn, size_t end) {
        int cur = 0;
        int pre = 0;
        for (size_t index = bgn; index < end; ++index) {
            int tmpCur = cur;
            cur = max(pre + nums[index], cur);
            pre = tmpCur;
        }

        return cur;
    }

    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        else if (nums.size() == 1) {
            return nums.front();
        }

        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }
};