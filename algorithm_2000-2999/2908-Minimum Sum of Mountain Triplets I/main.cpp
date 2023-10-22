class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();

        int ret = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] >= nums[j]) { continue; }
                for (int k = j + 1; k < n; ++k) {
                    if (nums[j] <= nums[k]) { continue; }
                    ret = std::min(ret, nums[i] + nums[j] + nums[k]);
                }
            }
        }

        return ret == INT_MAX ? -1: ret;
    }
};
