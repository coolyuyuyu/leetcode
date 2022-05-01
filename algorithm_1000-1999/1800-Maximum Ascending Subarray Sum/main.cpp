class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0, curSum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (0 < i && nums[i] <= nums[i - 1]) {
                curSum = 0;
            }
            curSum += nums[i];
            maxSum = std::max(maxSum, curSum);
        }

        return maxSum;
    }
};
