class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (abs(nums[i] - nums[j]) <= std::min(nums[i], nums[j])) {
                    ret = std::max(ret, nums[i] ^ nums[j]);
                }
            }
        }

        return ret;
    }
};
