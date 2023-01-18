class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN, curMaxSum = 0;
        int minSum = INT_MAX, curMinSum = 0;
        int sum = 0;
        for (int num : nums) {
            curMaxSum += num;
            maxSum = std::max(maxSum, curMaxSum);
            curMaxSum = std::max(curMaxSum, 0);

            curMinSum += num;
            minSum = std::min(minSum, curMinSum);
            curMinSum = std::min(curMinSum, 0);

            sum += num;
        }

        if (sum == minSum) {
            return maxSum;
        }
        return std::max(maxSum, sum - minSum);
    }
};
