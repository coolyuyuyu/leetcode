class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, curMax = 0;
        for (int num : nums) {
            curMax += num;
            maxSum = std::max(maxSum, curMax);
            if (curMax < 0) {
                curMax = 0;
            }
        }
        return maxSum;
    }
};
