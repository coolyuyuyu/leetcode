class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ret = 0;
        for (int i = 1, n = nums.size(); i + 1 < n; ++i) {
            if ((nums[i - 1] + nums[i + 1]) * 2 == nums[i]) {
                ++ret;
            }
        }

        return ret;
    }
};
