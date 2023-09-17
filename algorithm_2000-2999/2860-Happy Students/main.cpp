class Solution {
public:
    int countWays(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        int ret = 0;
        if (0 < nums[0]) {
            ++ret;
        }
        for (int i = 0; (i + 1) < n; ++i) {
            if (nums[i] < (i + 1) && (i + 1) < nums[i + 1]) {
                ++ret;
            }
        }
        if (nums[n - 1] < n) {
            ++ret;
        }

        return ret;
    }
};
