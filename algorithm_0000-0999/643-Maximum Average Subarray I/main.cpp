class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        assert(k <= nums.size());

        int sum = 0;
        for (size_t i = 0; i < k; ++i) {
            sum += nums[i];
        }
        double avg = sum * 1.0 / k;

        for (size_t i = k; i < nums.size(); ++i) {
            sum -= nums[i - k];
            sum += nums[i];
            avg = max(avg, sum * 1.0 / k);
        }

        return avg;
    }
};