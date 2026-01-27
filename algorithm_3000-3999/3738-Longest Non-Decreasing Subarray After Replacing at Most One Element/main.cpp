class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int pre[n]; // pre[i]: the len of longest non-decreasing subarray ending at i
        pre[0] = 1;
        for (int i = 1; i < n; ++i) {
            pre[i] = (nums[i - 1] <= nums[i] ? (pre[i - 1] + 1) : 1);
        }

        int suf[n]; // suf[i]: the len of longest non-decreasing subarray starting at i
        suf[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = (nums[i] <= nums[i + 1] ? (suf[i + 1] + 1) : 1);
        }

        int ret = 0;
        ret = std::max(ret, *std::max_element(pre, pre + n));
        if (ret < n) {
            ret = ret + 1;
        }

        for (int i = 1; i < n - 1; ++i) {
            if (nums[i - 1] <= nums[i + 1]) {
                ret = std::max(ret, pre[i - 1] + 1 + suf[i + 1]);
            }
        }

        return ret;
    }
};
