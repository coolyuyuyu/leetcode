class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();

        int rhtMin[n];
        rhtMin[n - 1] = nums[n - 1];
        for (int i = n - 1; 0 < i--;) {
            rhtMin[i] = std::min(rhtMin[i + 1], nums[i]);
        }

        int ret = INT_MAX;
        for (int lftMin = nums[0], i = 1; i + 1 < n; ++i) {
            if (lftMin < nums[i] && nums[i] > rhtMin[i + 1]) {
            ret = std::min(ret, lftMin + nums[i] + rhtMin[i + 1]);
            }

            lftMin = std::min(lftMin, nums[i]);
        }

        return ret == INT_MAX ? -1: ret;
    }
};
