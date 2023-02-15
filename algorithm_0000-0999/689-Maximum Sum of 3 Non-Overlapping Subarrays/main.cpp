class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>& presum = nums;
        std::partial_sum(presum.begin(), presum.end(), presum.begin());

        // dpL[i]: (S, I) such that the max sum S of k-element-subarray with lft end index I in nums[0:i]
        vector<array<int, 2>> dpL(n);
        for (int maxSum = INT_MIN, maxIdx, i = k - 1; i < n; ++i) {
            int sum = presum[i] - (k <= i ? presum[i - k] : 0);
            if (maxSum < sum) {
                maxSum = sum;
                maxIdx = i - k + 1;
            } 

            dpL[i] = {maxSum, maxIdx};
        }

        // dpR[i]: (S, I) such that the max sum S of k-element-subarray with lft end index I in nums[i:n-1]
        vector<array<int, 2>> dpR(n);
        for (int maxSum = INT_MIN, maxIdx, i = n - k; 0 <= i; --i) {
            int sum = presum[i + k - 1] - (0 < i ? presum[i - 1] : 0);
            if (maxSum <= sum) {
                maxSum = sum;
                maxIdx = i;
            } 

            dpR[i] = {maxSum, maxIdx};
        }

        vector<int> ret;
        for (int maxSum = INT_MIN, i = k; i < (n - 2 * k + 1); ++i) {
            int sum = dpL[i - 1][0] + (presum[i + k - 1] - presum[i - 1]) + dpR[i + k][0];
            if (maxSum < sum) {
                maxSum = sum;
                ret = {dpL[i - 1][1], i, dpR[i + k][1]};
            }
        }

        return ret;
    }
};
