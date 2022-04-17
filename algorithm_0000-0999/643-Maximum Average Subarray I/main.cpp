class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        assert(k <= nums.size());

        int sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
        int maxSum = sum;
        for (size_t i = k; i < nums.size(); ++i) {
            sum -= nums[i - k];
            sum += nums[i];
            if (maxSum < sum) {
                maxSum = sum;
            }
        }

        return maxSum * 1.0 / k;
    }
};
