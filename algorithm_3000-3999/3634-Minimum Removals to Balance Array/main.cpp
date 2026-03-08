class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int ret = INT_MAX;
        for (int i = 0, j = 0, n = nums.size(); i < n; ++i) {
            while (j < n && 1LL * nums[i] * k >= nums[j]) {
                ++j;
            }

            ret = std::min(ret, n - (j - i));
        }

        return ret;
    }
};
