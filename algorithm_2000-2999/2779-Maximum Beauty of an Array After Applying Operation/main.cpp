class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int ret = 0;
        for (int lft = 0, rht = 0, n = nums.size(); lft < n; ++lft) {
            while (rht < n && nums[lft] + k >= nums[rht] - k) {
                ++rht;
            }

            ret = std::max(ret, rht - lft);
        }

        return ret;
    }
};
