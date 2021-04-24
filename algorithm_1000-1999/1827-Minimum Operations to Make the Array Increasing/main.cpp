class Solution {
public:
    int minOperations(vector<int>& nums) {
        assert(!nums.empty());

        int maxVal = nums.front();
        int numOperations = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] <= maxVal) {
                ++maxVal;
                numOperations += (maxVal - nums[i]);
            }
            else {
                maxVal = nums[i];
            }
        }

        return numOperations;
    }
};
