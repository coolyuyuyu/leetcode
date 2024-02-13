class Solution {
public:
    int maximumGap(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int ret = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            ret = std::max(ret, nums[i + 1] - nums[i]);
        }

        return ret;
    }
};
