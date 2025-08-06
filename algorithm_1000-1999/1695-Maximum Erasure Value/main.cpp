class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool> s(10001, false);
        int ret = 0;
        for (int i = 0, j = 0, n = nums.size(), sum = 0; i < n; ++i) {
            for (; j < n && !s[nums[j]]; ++j) {
                sum += nums[j];
                s[nums[j]] = true;
            }

            ret = std::max(ret, sum);

            sum -= nums[i];
            s[nums[i]] = false;
        }

        return ret;
    }
};
