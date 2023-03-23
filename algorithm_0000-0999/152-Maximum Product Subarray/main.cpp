class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> dpMax(n); // dpMax[i]: the maximum product subarray ending at i
        vector<int> dpMin(n); // dpMax[i]: the maximum product subarray ending at i
        dpMax[0] = dpMin[0] = nums[0];
        int ret = nums[0];
        for (int i = 1; i < n; ++i) {
            std::tie(dpMin[i], dpMax[i]) = std::minmax({dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i], nums[i]});
            ret = std::max(ret, dpMax[i]);
        }

        return ret;
    }
};
