class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        for (size_t n = nums.size() / 2; 0 < n; n /= 2) {
            for (size_t i = 0; i < n; ++i) {
                if (i & 1) {
                    nums[i] = std::max(nums[2 * i], nums[2 * i + 1]);
                }
                else {
                    nums[i] = std::min(nums[2 * i], nums[2 * i + 1]);
                }
            }
        }

        return nums[0];
    }
};
