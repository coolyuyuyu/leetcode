class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        int lftSum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            int rhtSum = sum - lftSum - nums[i];
            if (lftSum == rhtSum) {
                return i;
            }
            lftSum += nums[i];
        }

        return -1;
    }
};