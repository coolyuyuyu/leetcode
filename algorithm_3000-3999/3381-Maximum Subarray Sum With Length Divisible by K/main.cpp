class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> m(k, LLONG_MAX / 2);
        m[k - 1] = 0;

        long long ret = LLONG_MIN;

        long long sum = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            sum += nums[i];
            ret = std::max(ret, sum - m[i % k]);
            m[i % k] = std::min(m[i % k], sum);
        }

        return ret;
    }
};
