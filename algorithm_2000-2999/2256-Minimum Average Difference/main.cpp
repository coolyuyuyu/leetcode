class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> sums(nums.size());
        for (size_t i = 0; i < sums.size(); ++i) {
            sums[i] = nums[i];
        }
        std::partial_sum(sums.begin(), sums.end(), sums.begin());

        long long minAvgDiff = LONG_LONG_MAX;
        size_t index = 0;
        for (size_t i = 0; i < sums.size(); ++i) {
            long long lftAvg = sums[i] / (i + 1);
            long long rhtAvg = i + 1 == nums.size() ? 0 : (sums.back() - sums[i]) / (sums.size() - i - 1);
            long long avgDiff = abs(lftAvg - rhtAvg);
            if (avgDiff <minAvgDiff) {
                minAvgDiff = avgDiff;
                index = i;
            }
        }

        return index;
    }
};
